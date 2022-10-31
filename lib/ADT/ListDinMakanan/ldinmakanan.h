#ifndef LDINMAKANAN_H
#define LDINMAKANAN_H

#include "../boolean.h"
#include "../Makanan/makanan.h"
#include <stdio.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Makanan LDinMakananEl; /* type elemen list */
typedef int IdxType;
/**
 * @brief ADT LDinMakanan yang merupakan list dinamis rata kiri dengan LDinMakananEl Makanan
 * @param nEff >=0, banyak elemen efektif
 * @param capacity kapasitas/ukuran list
 */
typedef struct
{
    LDinMakananEl *makanan;
    int nEff;
    int capacity;
} LDinMakanan;

/* ********** SELEKTOR ********** */
#define nEffLDM(l) (l).nEff
#define makanan(l) (l).makanan
#define elmtLDM(l, i) (l).makanan[i]
#define capacityLDM(l) (l).capacity

/* ********** KONSTRUKTOR ********** */

/**
 * @brief Konstruktor : Membuat list makanan kosong
 *
 * @param l alamat list makanan
 * @param capacity kapasitas list dinamis l
 */
void buatLDinMakanan(LDinMakanan *l, int capacity);

/**
 * @brief men-dealokasi memori list l
 *
 * @param l list makanan l yang mula-mula terdefinisi
 */
void dealokasiLDinMakanan(LDinMakanan *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/**
 * @brief mengembalikan banyaknya elemen list makanan l
 *
 * @param l list makanan yang terdefinisi (bisa kosong)
 * @return int : banyaknya elemen dalam list l
 */
int panjangLDinMakanan(LDinMakanan l);

/* *** Selektor INDEKS *** */

/**
 * @brief mengembalikan indeks elemen l terakhir
 *
 * @param l prekondisi : l tidak kosong
 * @return IdxType : indeks elemen l terakhir
 */
IdxType lastIdxLDinMakanan(LDinMakanan l);

/* ********** Test Indeks yang valid ********** */

/**
 * @brief Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxValidLDinMakanan(LDinMakanan l, IdxType i);

/**
 * @brief Mengirimkan true jika i adalah indeks yang terdefinisi utk list, yaitu antara 0..NEff-1
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxEffLDinMakanan(LDinMakanan l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * @brief Mengirimkan true jika list kosong, false jika list tidak kosong.
 *
 * @param l
 * @return boolean
 */
boolean isEmptyLDinMakanan(LDinMakanan l);

/**
 * @brief  Mengirimkan true jika list l penuh, mengirimkan false jika tidak
 *
 * @param l
 * @return boolean
 */
boolean isFullLDinMakanan(LDinMakanan l);

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
// void readLDinMakanan(LDinMakanan *l);

/**
 * @brief Menampilkan isi list makanan dengan format
 * " ID makanan :
 * Nama makanan :
 * Waktu kadaluarsa :
 * Lama pengiriman :
 * Lokasi aksi : "
 * @param l boleh kosong
 */
void printLDinMakanan(LDinMakanan l);

/* ********** OPERASI LAIN ********** */
/**
 * @brief Menyalin isi lIn ke lOut
 *
 * @param lIn lIn terdefinisi
 * @param lOut sembarang
 */
void copyLDinMakanan(LDinMakanan lIn, LDinMakanan *lOut);

/**
 * @brief Mengeluarkan elemen pertama dari l lalu menyimpannya ke dalam X
 *
 * @param l
 * @param X
 */
void removeFirstLDinMakanan(LDinMakanan *l, LDinMakananEl *X);

/**
 * @brief menghapus nilai pada indeks idx list din l dan menyimpannya dalam val
 *
 * @param l list yang akan dihapus elemennya
 * @param val penyimpanan nilai yang dihapus dari list
 * @param idx indeks yang akan dihapus elemennya
 */
void removeAtLDinMakanan(LDinMakanan *l, LDinMakananEl *val, IdxType idx);

/**
 * @brief menghapus elemen terakhir pada list dan menyimpannya dalam val
 *
 * @param l list yang akan dihapus elemen terakhirnya
 * @param val penyimpanan nilai yang dihapus dari list
 */
void removeLastLDinMakanan(LDinMakanan *l, LDinMakananEl *val);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertFirstLDinMakanan(LDinMakanan *l, LDinMakananEl val);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertLastLDinMakanan(LDinMakanan *l, LDinMakananEl val);

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/**
 * @brief Menambahkan val sebagai elemen list pada index idx. Jika list penuh, maka list akan diexpand. Jika idx tidak valid, akan dicetak pesan error.
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan pada list
 * @param idx index tempat pengisian val
 */
void insertAtLDinMakanan(LDinMakanan *l, LDinMakananEl val, IdxType idx);

/**
 * @brief Menambahkan capacity l sebanyak num
 * @param l
 * @param num Tambahan capacity l
 */

void expandLDinMakanan(LDinMakanan *l, int num);

/**
 * @brief mengecek apakah makanan dengan nama namaMakanan ada dalam list
 *
 * @param l list Makanan yang ingin ditraverse
 * @param namaMakanan nama Makanan yang ingin dicari
 * @return boolean
 */
boolean isMakananInList(LDinMakanan *l, Teks namaMakanan);
#endif