#ifndef LDINTEKS_H
#define LDINTEKS_H

#include "../boolean.h"
#include "../Teks/teks.h"
#include <stdio.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Teks LDinTeksEl; /* type elemen list */
typedef int IdxType;
/**
 * @brief ADT LDinTeks yang merupakan list dinamis rata kiri dengan LDinTeksEl char
 * @param nEff >=0, banyak elemen efektif
 * @param capacity kapasitas/ukuran list
 */
typedef struct
{
    LDinTeksEl *teks;
    int nEff;
    int capacity;
} LDinTeks;

/* ********** SELEKTOR ********** */
#define nEffLDT(l) (l).nEff
#define teks(l) (l).teks
#define elmtLDT(l, i) (l).teks[i]
#define capacityLDT(l) (l).capacity

/* ********** KONSTRUKTOR ********** */

/**
 * @brief Konstruktor : Membuat list teks kosong
 *
 * @param l alamat list teks
 * @param capacity kapasitas list dinamis l
 */
void buatLDinTeks(LDinTeks *l, int capacity);

/**
 * @brief men-dealokasi memori list l
 *
 * @param l list makanan l yang mula-mula terdefinisi
 */
void dealokasiLDinTeks(LDinTeks *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/**
 * @brief mengembalikan banyaknya elemen list teks l
 *
 * @param l list makanan yang terdefinisi (bisa kosong)
 * @return int : banyaknya elemen dalam list l
 */
int panjangLDinTeks(LDinTeks l);

/* *** Selektor INDEKS *** */

/**
 * @brief mengembalikan indeks elemen l terakhir
 *
 * @param l prekondisi : l tidak kosong
 * @return IdxType : indeks elemen l terakhir
 */
IdxType lastIdxLDinTeks(LDinTeks l);

/* ********** Test Indeks yang valid ********** */

/**
 * @brief Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxValidLDinTeks(LDinTeks l, IdxType i);

/**
 * @brief Mengirimkan true jika i adalah indeks yang terdefinisi utk list, yaitu antara 0..NEff-1
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxEffLDinTeks(LDinTeks l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * @brief Mengirimkan true jika list kosong, false jika list tidak kosong.
 *
 * @param l
 * @return boolean
 */
boolean isEmptyLDinTeks(LDinTeks l);

/**
 * @brief  Mengirimkan true jika list l penuh, mengirimkan false jika tidak
 *
 * @param l
 * @return boolean
 */
boolean isFullLDinTeks(LDinTeks l);

/**
 * @brief membaca list teks
 *
 * @param l sudah dialokasikan sebelumnya
 */
void readLDinTeks(LDinTeks *l);

/**
 * @brief Menampilkan isi list char sebagai string
 * @param l boleh kosong
 */
void printLDinTeks(LDinTeks l);

/* ********** OPERASI LAIN ********** */
/**
 * @brief Menyalin isi lIn ke lOut
 *
 * @param lIn lIn terdefinisi
 * @param lOut sembarang
 */
void copyLDinTeks(LDinTeks lIn, LDinTeks *lOut);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertFirstLDinTeks(LDinTeks *l, LDinTeksEl val);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertLastLDinTeks(LDinTeks *l, LDinTeksEl val);

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/**
 * @brief Menambahkan val sebagai elemen list pada index idx. Jika list penuh, maka list akan diexpand. Jika idx tidak valid, akan dicetak pesan error.
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan pada list
 * @param idx index tempat pengisian val
 */
void insertAtLDinTeks(LDinTeks *l, LDinTeksEl val, IdxType idx);

/**
 * @brief Menambahkan capacity l sebanyak num
 * @param l
 * @param num Tambahan capacity l
 */
void expandLDinTeks(LDinTeks *l, int num);
#endif