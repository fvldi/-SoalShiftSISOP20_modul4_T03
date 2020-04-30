#define FUSE_USE_VERSION 28
#include <fuse.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <dirent.h>
#include <errno.h>
#include <sys/time.h>

static const char * dirpath = "~/Downloads";

void reverse(char * x, int begin, int end) {
  char c;
  if (begin >= end) return;
  c = * (x + begin);
  *(x + begin) = * (x + end);
  *(x + end) = c;
  reverse(x, ++begin, --end);
}

void reversePath(const char *path, char bufferKeluar[]) {
  char bufferPath[1000];
  strcpy(bufferPath, path);
  char bufferOut[1000] = "";
  char *token = strtok(bufferPath, "/");
  while(token != NULL) {
    char buffer[1000];
    strcpy(buffer, token);
    reverse(buffer, 0, strlen(buffer)-1);
    sprintf(bufferOut, "%s/%s", bufferOut, buffer);

    token = strtok(NULL, "/");
  }
  strcpy(bufferKeluar, bufferOut);
}

static int _getattr(const char * path, struct stat * stbuf) {

  int res;
  char fpathbuffer[1000];
  char fpath[1000];

  if (strcmp(path, "/") == 0) {
    path = dirpath;
    sprintf(fpath, "%s", path);
  } else {
    reversePath(path, fpathbuffer);
    sprintf(fpath, "%s%s", dirpath, fpathbuffer);
  }

  res = lstat(fpath, stbuf);

  if (res == -1) return -errno;

  return 0;

}

static int _readdir(const char * path, void * buf, fuse_fill_dir_t filler, off_t offset, struct fuse_file_info * fi) {

  char fpathbuffer[1000];
  char fpath[1000];

  if (strcmp(path, "/") == 0) {
    path = dirpath;
    sprintf(fpath, "%s", path);
  } else {
    reversePath(path, fpathbuffer);
    sprintf(fpath, "%s%s", dirpath, fpathbuffer);
  }

  int res = 0;

  DIR * dp;
  struct dirent * de;
  (void) offset;
  (void) fi;

  dp = opendir(fpath);
  if (dp == NULL) return -errno;

  while ((de = readdir(dp)) != NULL) {

    struct stat st;
    memset( & st, 0, sizeof(st));

    st.st_ino = de -> d_ino;
    st.st_mode = de -> d_type << 12;

    char str[1000];
    strcpy(str, de -> d_name);
    reverse(str, 0, strlen(str) - 1);

    res = (filler(buf, str, & st, 0));

    if (res != 0) break;

  }

  closedir(dp);

  return 0;

}

static int _read(const char * path, char * buf, size_t size, off_t offset, struct fuse_file_info * fi) {

  char fpathbuffer[1000];
  char fpath[1000];

  if (strcmp(path, "/") == 0) {
    path = dirpath;
    sprintf(fpath, "%s", path);
  } else {
    reversePath(path, fpathbuffer);
    sprintf(fpath, "%s%s", dirpath, fpathbuffer);
  }

  int res = 0;
  int fd = 0;
  (void) fi;

  fd = open(fpath, O_RDONLY);

  if (fd == -1) return -errno;

  res = pread(fd, buf, size, offset);

  if (res == -1)res = -errno;

  close(fd);

  return res;

}

static struct fuse_operations xmp_oper = {
  .getattr = _getattr,
  .readdir = _readdir,
  .read = _read,
};

int main(int argc, char * argv[]){
  umask(0);
  return fuse_main(argc, argv, & xmp_oper, NULL);
}
