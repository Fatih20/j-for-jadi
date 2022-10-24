#ifndef LDINKAR_H
#define LDINKAR_H

#include "../boolean.h"
#include <stdio.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef char LDinKarEl; /* type elemen list */
typedef int IdxType;
/**
 * @brief ADT LDinKar yang merupakan list dinamis rata kiri dengan LDinKarEl char
 * @param nEff >=0, banyak elemen efektif
 * @param capacity kapasitas/ukuran list
 */
typedef struct
{
    LDinKarEl *kar;
    int nEff;
    int capacity;
} LDinKar;

/* ********** SELEKTOR ********** */
#define nEffLDC(l) (l).nEff
#define kar(l) (l).kar
#define elmtLDC(l, i) (l).kar[i]
#define capacityLDC(l) (l).capacity

/* ********** KONSTRUKTOR ********** */

/**
 * @brief Konstruktor : Membuat list char kosong
 *
 * @param l alamat list char
 * @param capacity kapasitas list dinamis l
 */
void buatLDinKar(LDinKar *l, int capacity);

/**
 * @brief men-dealokasi memori list l
 *
 * @param l list makanan l yang mula-mula terdefinisi
 */
void dealokasiLDinKar(LDinKar *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/**
 * @brief mengembalikan banyaknya elemen list char l
 *
 * @param l list makanan yang terdefinisi (bisa kosong)
 * @return int : banyaknya elemen dalam list l
 */
int panjangLDinKar(LDinKar l);

/* *** Selektor INDEKS *** */

/**
 * @brief mengembalikan indeks elemen l terakhir
 *
 * @param l prekondisi : l tidak kosong
 * @return IdxType : indeks elemen l terakhir
 */
IdxType lastIdxLDinKar(LDinKar l);

/* ********** Test Indeks yang valid ********** */

/**
 * @brief Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxValidLDinKar(LDinKar l, IdxType i);

/**
 * @brief Mengirimkan true jika i adalah indeks yang terdefinisi utk list, yaitu antara 0..NEff-1
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxEffLDinKar(LDinKar l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * @brief Mengirimkan true jika list kosong, false jika list tidak kosong.
 *
 * @param l
 * @return boolean
 */
boolean isEmptyLDinKar(LDinKar l);

/**
 * @brief  Mengirimkan true jika list l penuh, mengirimkan false jika tidak
 *
 * @param l
 * @return boolean
 */
boolean isFullLDinKar(LDinKar l);

/**
 * @brief membaca list makanan
 * Proses : terima N jumlah makanan
 * 1. Baca banyaknya elemen diakhiri enter, misalnya N
 *    Pembacaan diulangi sampai didapat N yang benar yaitu 0 <= N <= CAPACITY(l)
 *    Jika N tidak valid, tidak diberikan pesan kesalahan
 * 2. Jika 0 < N <= CAPACITY(l); Lakukan N kali: Baca elemen mulai dari indeks
      0 satu per satu diakhiri enter
 * ini buat debug dan driver doang sebenarnya ga butuh harusnyaa
 *
 * @param l sudah dialokasikan sebelumnya
 */
void readLDinKar(LDinKar *l);

/**
 * @brief Menampilkan isi list char sebagai string
 * @param l boleh kosong
 */
void printLDinKar(LDinKar l);

/* ********** OPERASI LAIN ********** */
/**
 * @brief Menyalin isi lIn ke lOut
 *
 * @param lIn lIn terdefinisi
 * @param lOut sembarang
 */
void copyLDinKar(LDinKar lIn, LDinKar *lOut);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertFirstLDinKar(LDinKar *l, LDinKarEl val);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertLastLDinKar(LDinKar *l, LDinKarEl val);

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/**
 * @brief Menambahkan val sebagai elemen list pada index idx. Jika list penuh, maka list akan diexpand. Jika idx tidak valid, akan dicetak pesan error.
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan pada list
 * @param idx index tempat pengisian val
 */
void insertAtLDinKar(LDinKar *l, LDinKarEl val, IdxType idx);

/**
 * @brief Menambahkan capacity l sebanyak num
 * @param l
 * @param num Tambahan capacity l
 */
void expandLDinKar(LDinKar *l, int num);
#endif