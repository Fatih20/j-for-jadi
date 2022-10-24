/*
    LStatMakanan adalah ADT List Statik yang digunakan untuk menyimpan daftar makanan yang tersedia pada aplikasi.
    List Statik yang digunakan adalah list statik rata kiri yang immutable.
*/
#ifndef LSTATMAKANAN_H
#define LSTATMAKANAN_H

#include "../boolean.h"
#include "../Makanan/makanan.h"
#include "../Teks/teks.h"

/*  Kamus Umum */
#define capacityLSM 100
/* Kapasitas penyimpanan */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Makanan LStatMakananEl; /* type elemen List */
typedef int IdxType;
/**
 * @brief ADT LStatMakanan yang menyimpan daftar makanan aplikasi
 * Indeks yang digunakan [0..capacityLSM-1]
 * Definisi :
   List kosong: semua elemen bernilai MARK
   Definisi elemen pertama: elmtLSM(l,i) dengan i=0
 *
 */
typedef struct
{
  LStatMakananEl makanan[capacityLSM]; /* memori tempat penyimpan elemen (container) */
} LStatMakanan;

/* ********** SELEKTOR ********** */
#define elmtLSM(l, i) (l).makanan[(i)]

/**
 * @brief Mengembalikan MARK
 *
 * @return MARK
 */
Makanan getMarkLStatMakanan();
/* ********** KONSTRUKTOR ********** */
/**
 * @brief Konstruktor : List kosong
 *
 * @param l
 */
void buatLStatMakanan(LStatMakanan *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/**
 * @brief mengembalikan banyaknya elemen dalam list
 *
 * @param l list yang dicek jumlah elemennya
 * @return int yang mewakili jumlah elemen list
 */
int panjangLStatMakanan(LStatMakanan l);

/* *** Selektor INDEKS *** */
/**
 * @brief Mengembalikan indeks terakhir l
 *
 * @param l list yang ingin diketahui indeks terakhirnya (TIDAK KOSONG)
 * @return IdxType yang merupakan indeks terakhir l
 */
IdxType lastIdxLStatMakanan(LStatMakanan l);

/* ********** Test Indeks yang valid ********** */
/**
 * @brief Mengirimkan true jika i adalah indeks yang valid utk kapasitas List l
 * yaitu antara indeks yang terdefinisi utk container
 * @param l
 * @param i
 * @return boolean
 */
boolean isIdxValidLStatMakanan(LStatMakanan l, IdxType i);

/**
 * @brief
 *
 * @param l Mengirimkan true jika i adalah indeks yang terdefinisi utk List l
 * yaitu antara 0..length(l)-1
 *  @param i
 * @return boolean
 */
boolean isIdxEffLStatMakanan(LStatMakanan l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * @brief Mengirimkan true jika List l kosong, mengirimkan false jika tidak
 *
 * @param l
 * @return boolean
 */
boolean isEmptyLStatMakanan(LStatMakanan l);

/**
 * @brief Mengirimkan true jika List l penuh, mengirimkan false jika tidak
 *
 * @param l
 * @return boolean
 */
boolean isFullLStatMakanan(LStatMakanan l);

/**
 * @brief membaca daftar makanan dari file
 * Format <file>
 * 6 # Jumlah makanan
 * 11 # ID Makanan
 * Ayam Mentah # Nama makanan
 * 1 0 0 # Waktu kadaluarsa
 * 0 0 15 # Lama pengiriman
 * Buy # Aksi pengolahan
 * 0 0 0 # Lama aksi pengolahan
 *
 * @param l
 * @param file
 */
void readLStatMakanan(LStatMakanan *l, char *file);

/**
 * @brief Menuliskan isi list makanan
 *
 * @param l
 */
void printLStatMakanan(LStatMakanan l);

/* ********** SEARCHING ********** */
/**
 * @brief  Search apakah ada elemen List l yang bernilai val
 *
 * @param l
 * @param val
 * @return int index ditemukannya val dalam l
 */
int indexOfLStatMakanan(LStatMakanan l, LStatMakananEl val);

/**
 * @brief Mengembalikan nama makanan dengan idMakanan ID
 * 
 * @param l 
 * @param id 
 * @return Teks 
 */
Teks getNameFromID(LStatMakanan l, Teks id);

void insertLastLStatMakanan(LStatMakanan *l, LStatMakananEl val);
/* Proses: Menambahkan val sebagai elemen terakhir List */
/* I.S. List l boleh kosong, tetapi tidak penuh */
/* F.S. val adalah elemen terakhir l yang baru */

#endif