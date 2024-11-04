# Pencarian Solusi Diagonal Magic Cube dengan Local Search
Tugas Besar 1 IF3170 Inteligensi Artifisial - Local Search

<br/>
<p align="center">
  <img height="360px" src="https://i.ibb.co.com/MhdKHH5/magic-cube.png" alt="magic-cube-dimensi-5"/>
  <br>
  <a><i><sup>Magic Cube berukuran 5x5x5</sup></i></a>
</p>
<br/>

## Anggota 
1. Maria Flora Renata Siringoringo (13522010)
2. M Athaullah Daffa Kusuma Mulia (13522044)
3. Dzaky Satrio Nugroho (13522059)
4. Rafiki Prawira Harianto (13522065)

## Daftar Isi
* [Deskripsi Program](#deskripsi-singkat)
* [Dependencies](#informasi-tambahan)
* [Features](#fitur-utama)
* [Setup](#setup)
* [Cara Penggunaan](#petunjuk-cara-menjalankan-program-dan-lainnya)

## Deskripsi Singkat
Program ini merupakan tugas besar 1 dari mata kuliah IF3170 Inteligensi Artifisial. Program ini berfungsi untuk mencari solusi local optima dari magic cube berukuran 5x5x5 menggunakan 3 jenis algoritma local search yang berbeda, yaitu hill-climbing, simulated annealing, dan genetic algorithm.  

## Informasi Tambahan
- Program dibuat dengan : C++ (g++ 11.*)
- IDE yang digunakan : Visual Studio Code
- Laporan dibuat dengan : Google Docs 

## Fitur Utama
- Pencarian solusi Diagonal Magic Cube berukuran 5x5x5 dengan menggunakan algoritma Hill-Climbing. 
- Pencarian solusi Diagonal Magic Cube berukuran 5x5x5 dengan menggunakan algoritma Simulated Annealing.
- Pencarian solusi Diagonal Magic Cube berukuran 5x5x5 dengan menggunakan algoritma Genetic Algorithm.

## Setup
1. Program mempunyai file main masing-masing dari algoritma yang hendak dijalankan, silahkan masuk ke src dengan `cd src`.

## Petunjuk Cara Menjalankan Program dan lainnya

### Cara Menjalankan Program
berikut merupakan langkah untuk menjalankan program:
1. Pastikan lokasi folder sesuai dengan [Setup](#setup)
2. Jalankan Program dengan file masing-masing dari algoritma
3. Jika hendak menjalankan algoritma hill-climbing, jalankan hillclimb.cpp
4. Jika hendak menjalankan simulated-annealing, jalankan simulated-annealing.cpp
5. Jika hendak menjalankan genetic algorithm, jalankan genetic-algorithm.cpp
6. Jika hendak membuat plotting, silahkan jalankan plot_maker.py

### Input
Silahkan ikuti instruksi yang diberikan ketika pengguna menjalankan file yang telah disebutkan [Sebelumnya](#cara-menjalankan-program). Perbedaan algoritma yang dipilih berarti input yang diminta akan berbeda. Untuk `plot_maker.py`, silahkan input angka dari value-value dengan dipisahkan koma.

### Output
Nantinya program akan mengoutput hasil algoritma local search yang telah dijalankan. Hasilnya secara general berisi state akhir yang didapat, nilai akhir objective function, durasi dari algoritma, banyak iterasi, dan value dari state-state yang dipilih menurut algoritma (angka-angka tersebut akan dipisah dengan koma, silahkan jalankan `plot_maker.py` untuk keperluan plotting)