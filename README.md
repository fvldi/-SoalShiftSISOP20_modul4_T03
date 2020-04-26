# Soal Shift SISOP20 Modul 4
## Kelompok T03
### 01. Muhamad Rifaldi - 05311840000022
### 02. Dimas Pramudya H - 05311840000037

---

Di suatu perusahaan, terdapat pekerja baru yang super jenius, ia bernama jasir. Jasir baru bekerja selama seminggu di perusahan itu, dalam waktu seminggu tersebut ia selalu terhantui oleh ketidak amanan dan ketidak efisienan ​file system ​ yang digunakan perusahaan tersebut. Sehingga ia merancang sebuah file system yang sangat aman dan efisien. Pada segi keamanan, Jasir telah menemukan 2 buah metode enkripsi file. Pada mode enkripsi pertama, nama file-file pada direktori terenkripsi akan dienkripsi menggunakan metode substitusi. Sedangkan pada metode enkripsi yang kedua, file-file pada direktori terenkripsi akan di-split menjadi file-file kecil. Sehingga orang-orang yang tidak menggunakan filesystem rancangannya akan kebingungan saat mengakses direktori terenkripsi tersebut. Untuk segi efisiensi, dikarenakan pada perusahaan tersebut sering dilaksanakan sinkronisasi antara 2 direktori, maka jasir telah merumuskan sebuah metode agar filesystem-nya mampu mengsingkronkan kedua direktori tersebut secara otomatis. Agar integritas filesystem tersebut lebih terjamin, maka setiap command yang dilakukan akan dicatat kedalam sebuah file log. (catatan: filesystem berfungsi normal layaknya linux pada umumnya) (catatan: mount source (root) filesystem adalah direktori /home/[user]/Documents)
  
Berikut adalah detail filesystem rancangan jasir: 
  
## 01. Enkripsi versi 1
-  A. Jika sebuah direktori dibuat dengan awalan ```“encv1_”```, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1.
- B. Jika sebuah direktori di-​rename ​ dengan awalan ```“encv1_”```, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v1. 
- C. Apabila sebuah direktori terenkripsi di-​rename ​ menjadi tidak terenkripsi, maka isi adirektori tersebut akan terdekrip. 
- D. Setiap pembuatan direktori terenkripsi baru (mkdir ataupun rename) akan tercatat ke sebuah database/log berupa file.
- E. Semua file yang berada dalam direktori ter enkripsi menggunakan caesar cipher dengan key.

```9(ku@AW1[Lmvgax6q`5Y2Ry?+sF!^HKQiBXCUSe&0M.b%rI'7d)o4~VfZ*{#:}ETt$3J-zpc]lnh8,GwP_ND|jO```

Misal kan ada file bernama “kelincilucu.jpg” dalam directory FOTO_PENTING, dan key yang dipakai adalah 10
__“encv1_rahasia/FOTO_PENTING/kelincilucu.jpg” => “encv1_rahasia/ULlL@u]AlZA(/g7D.|_.Da_a.jpg__

__Note : Dalam penamaan file ‘/’ diabaikan, dan ekstensi tidak perlu di encrypt.__
- F. Metode enkripsi pada suatu direktori juga berlaku kedalam direktori lainnya yang ada didalamnya.
 

### Source Code : 


### Penjelasan : 


### Output :


## 02. Enkripsi versi 2
- A. Jika sebuah direktori dibuat dengan awalan ```“encv2_”```, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v2. 
- B. Jika sebuah direktori di-rename dengan awalan ```“encv2_”```, maka direktori tersebut akan menjadi direktori terenkripsi menggunakan metode enkripsi v2.
- C. Apabila sebuah direktori terenkripsi di-rename menjadi tidak terenkripsi, maka isi direktori tersebut akan terdekrip.
- D. Setiap pembuatan direktori terenkripsi baru (mkdir ataupun rename) akan tercatat ke sebuah database/log berupa file.
- E. Pada enkripsi v2, file-file pada direktori asli akan menjadi bagian-bagian kecil sebesar 1024 bytes dan menjadi normal ketika diakses melalui filesystem rancangan jasir. Sebagai contoh, file ```File_Contoh.txt``` berukuran 5 kB pada direktori asli akan menjadi 5 file kecil yakni : ```File_Contoh.txt.000```, ```File_Contoh.txt.001```, ```File_Contoh.txt.002```, ```File_Contoh.txt.003```, dan ```File_Contoh.txt.004```.
- F. Metode enkripsi pada suatu direktori juga berlaku kedalam direktori lain yang ada didalam direktori tersebut (rekursif).


### Source Code : 


### Penjelasan : 


### Output :


## 03. Sinkronisasi direktori otomatis:


### Source Code : 


### Penjelasan : 


### Output :


## 04. Log system:


### Source Code : 


### Penjelasan : 


### Output :


## Kendala :

