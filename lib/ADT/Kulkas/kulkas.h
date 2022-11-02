#ifndef KULKAS_H
#define KULKAS_H

#include <stdio.h>
#include "../Makanan/makanan.h"
#include "../Teks/teks.h"
#include "../ListDinMakanan/ldinmakanan.h"

#define Nil -1
#define PanjangKulkas 20
#define LebarKulkas 10

/**
 * @brief Tipe Data Kulkas
 * @param isi: matriks kulkas dengan ukuran 50x50
 */
typedef struct
{
    int isi[LebarKulkas][PanjangKulkas];
    int sisaKapasitas;
    LDinMakanan makananKulkas;

} Kulkas;

#define isiKulkas(k, i, j) (k).isi[i][j]
#define sisaKapasitas(k) (k).sisaKapasitas
#define makananKulkas(k) (k).makananKulkas

/**
 * @brief Inisiasi tipedata kulkas
 * @param k ADT Kulkas
 * @return ADT Kulkas dengan matriks kosong (Nil) dan sisaKapasitas = CAPACITY*CAPACITY
 */
void buatKulkas(Kulkas *k);

/**
 * @brief Mencetak kulkas ke layar
 * @param k ADT Kulkas
 */
void cetakKulkas(Kulkas k);

/**
 * @brief Menambahkan makanan ke kulkas
 * @param k ADT Kulkas
 * @param makanan ADT Makanan berisi makanan yang akan diisi
 * @return makanan akan masuk ke k jika ada ruang yang bisa ditempati
 */
void tambahIsiKulkas(Kulkas *k, Makanan makanan);

/**
 * @brief Mengeluarkan makanan dari kulkas
 * @param k ADT Kulkas
 * @param makanan ADT Makanan berisi makanan yang akan dikeluarkan
 * @return makanan akan masuk dibuang dari k
 */
void keluarkanIsiKulkas(Kulkas *k, Makanan *makanan);

/**
 * @brief Mengecek apakah makanan bisa dimasukkan secara horizontal
 * @param pilihanX input pivot X dari user
 * @param pilihanY input pivot Y dari user
 * @param panjang panjang makanan
 * @param lebar lebar makanan
 */
boolean cekHorizontal(Kulkas k, int pilihanX, int pilihanY, int panjang, int lebar);

/**
 * @brief Mengecek apakah makanan bisa dimasukkan secara vertikal
 * @param pilihanX input pivot X dari user
 * @param pilihanY input pivot Y dari user
 * @param panjang panjang makanan
 * @param lebar lebar makanan
 */
boolean cekVertikal(Kulkas k, int pilihanX, int pilihanY, int panjang, int lebar);

#endif