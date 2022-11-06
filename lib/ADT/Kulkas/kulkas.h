#ifndef KULKAS_H
#define KULKAS_H

#include <stdio.h>
#include "../Makanan/makanan.h"
#include "../Teks/teks.h"
#include "../ListDinMakanan/ldinmakanan.h"

#define Nil -1
#define PanjangKulkas 20
#define LebarKulkas 10

typedef struct
{
    int arrayKulkas[LebarKulkas][PanjangKulkas];
} IsiKulkas;

/**
 * @brief Tipe Data Kulkas
 * @param isi: matriks kulkas dengan ukuran 50x50
 */
typedef struct
{
    IsiKulkas isi;
    int sisaKapasitas;
    LDinMakanan makananKulkas;

} Kulkas;

#define isiKulkas(kulkas, i, j) aksesIsiKulkas(((kulkas).isi), i, j)
#define sisaKapasitas(kulkas) (kulkas).sisaKapasitas
#define makananKulkas(kulkas) (kulkas).makananKulkas
#define aksesIsiKulkas(isiArray, i, j) (isiArray).arrayKulkas[i][j]

/**
 * @brief Inisiasi tipedata kulkas
 * @param k ADT Kulkas
 * @return ADT Kulkas dengan matriks kosong (Nil) dan sisaKapasitas = CAPACITY*CAPACITY
 */
void buatKulkas(Kulkas *k);

/**
 * @brief Mencetak isi kulkas dan list makanan kulkas ke layar
 * @param k ADT Kulkas
 */
void cetakKulkas(Kulkas k);

/**
 * @brief Mencetak isi kulkas ke layar
 * @param k ADT Kulkas
 */
void cetakIsiKulkas(Kulkas k);

/**
 * @brief Mencetak list makanan kulkas ke layar
 * @param k ADT Kulkas
 */
void cetakListMakananKulkas(Kulkas k);

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
 * @brief Mengubah susunan isi kulkas
 * @param k ADT Kulkas
 * @return isi kulkas akan berubah susunannya sesuai perintah user
 */
void ubahIsiKulkas(Kulkas *k);

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

/**
 * @brief Prosedur mengecek apakah makanan bisa masuk Horizontal atau Vertikal
 * @param horizontal ADT Boolean penunjuk apakah bisa horizontal
 * @param vertikal ADT Boolean penunjuk apakah bisa vertikal
 * @param k ADT Kulkasnt
 * @param pilihanX
 * @param pilihanY
 * @param panjang
 * @param lebar
 */
void cekHorizontalVertical(boolean *horizontal, boolean *vertikal, Kulkas k, int pilihanX, int pilihanY, int panjang, int lebar);

/**
 * @brief Prosedur untuk mengisi makanan secara vertikal dari pivot
 * @param k ADT Kulkasnt
 * @param idx Nomor makanan dalam kulkas
 * @param pilihanX
 * @param pilihanY
 * @param panjang
 * @param lebar
 */
void isiVertikal(Kulkas *k, int idx, int pilihanX, int pilihanY, int panjang, int lebar);

/**
 * @brief Prosedur untuk mengisi makanan secara horizontal dari pivot
 * @param k ADT Kulkasnt
 * @param idx Nomor makanan dalam kulkas
 * @param pilihanX
 * @param pilihanY
 * @param panjang
 * @param lebar
 */
void isiHorizontal(Kulkas *k, int idx, int pilihanX, int pilihanY, int panjang, int lebar);

/**
 * @brief Membuat salinan isiKulkas
 * @param baru ADT IsiKulkas kosong
 * @param lama ADT IsiKulkas yang akan disalin
 */
void copyIsiKulkas(IsiKulkas baru, IsiKulkas lama);

#endif