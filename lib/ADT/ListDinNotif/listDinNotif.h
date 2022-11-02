#ifndef LDINNOTIF
#define LDINNOTIF

#include "../boolean.h"
#include "../Teks/teks.h"
#include "../Notification/notification.h"
#include <stdio.h>

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef Notif LDinNtfEl; /* type elemen list */
typedef int IdxType;
/**
 * @brief ADT LDinNotif yang merupakan list dinamis rata kiri dengan LDinNtfEl char
 * @param nEff >=0, banyak elemen efektif
 * @param capacity kapasitas/ukuran list
 */
typedef struct
{
    LDinNtfEl *notif;
    int nEff;
    int capacity;
} LDinNotif;

/* ********** SELEKTOR ********** */
#define nEffLDN(l) (l).nEff
#define notif(l) (l).notif
#define elmtLDN(l, i) (l).notif[i]
#define capacityLDN(l) (l).capacity

/* ********** KONSTRUKTOR ********** */

/**
 * @brief Konstruktor : Membuat list notif kosong
 *
 * @param l alamat list notif
 * @param capacity kapasitas list dinamis l
 */
void buatLDinNotif(LDinNotif *l, int capacity);

/**
 * @brief men-dealokasi memori list l
 *
 * @param l list notif l yang mula-mula terdefinisi
 */
void dealokasiLDinNotif(LDinNotif *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/**
 * @brief mengembalikan banyaknya elemen list notif l
 *
 * @param l list makanan yang terdefinisi (bisa kosong)
 * @return int : banyaknya elemen dalam list l
 */
int panjangLDinNotif(LDinNotif l);

/* *** Selektor INDEKS *** */

/**
 * @brief mengembalikan indeks elemen l terakhir
 *
 * @param l prekondisi : l tidak kosong
 * @return IdxType : indeks elemen l terakhir
 */
IdxType lastIdxLDinNotif(LDinNotif l);

/* ********** Test Indeks yang valid ********** */

/**
 * @brief Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxValidLDinNotif(LDinNotif l, IdxType i);

/**
 * @brief Mengirimkan true jika i adalah indeks yang terdefinisi utk list, yaitu antara 0..NEff-1
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxEffLDinNotif(LDinNotif l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * @brief Mengirimkan true jika list kosong, false jika list tidak kosong.
 *
 * @param l
 * @return boolean
 */
boolean isEmptyLDinNotif(LDinNotif l);

/**
 * @brief  Mengirimkan true jika list l penuh, mengirimkan false jika tidak
 *
 * @param l
 * @return boolean
 */
boolean isFullLDinNotif(LDinNotif l);

// /**
//  * @brief membaca list notif
//  *
//  * @param l sudah dialokasikan sebelumnya
//  */
// void readLDinNotif(LDinNotif *l);

/**
 * @brief Menampilkan isi list notif sesuai spesifikasi tubes
 * @param l boleh kosong
 */
void printLDinNotif(LDinNotif l);

/* ********** OPERASI LAIN ********** */
/**
 * @brief Menyalin isi lIn ke lOut
 *
 * @param lIn lIn terdefinisi
 * @param lOut sembarang
 */
void copyLDinNotif(LDinNotif lIn, LDinNotif *lOut);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertFirstLDinNotif(LDinNotif *l, LDinNtfEl val);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertLastLDinNotif(LDinNotif *l, LDinNtfEl val);

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/**
 * @brief Menambahkan val sebagai elemen list pada index idx. Jika list penuh, maka list akan diexpand. Jika idx tidak valid, akan dicetak pesan error.
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan pada list
 * @param idx index tempat pengisian val
 */
void insertAtLDinNotif(LDinNotif *l, LDinNtfEl val, IdxType idx);

/**
 * @brief memasukkan sebagai elemen terakhir l sebuah notif dengan subject subject dan kodeNotif kode
 *
 * @param l
 * @param kode
 * @param subject
 */
void insertLastLDinNotifRaw(LDinNotif *l, char kode, Teks subject);

/**
 * @brief memasukkan sebagai elemen pertama l sebuah notif dengan subject subject dan kodeNotif kode
 *
 * @param l
 * @param kode
 * @param subject
 */
void insertFirstLDinNotifRaw(LDinNotif *l, char kode, Teks subject);

/**
 * @brief memasukkan sebagai elemen ke-idx l sebuah notif dengan subject subject dan kodeNotif kode
 *
 * @param l
 * @param kode
 * @param subject
 * @param idx
 */
void insertAtLDinNotifRaw(LDinNotif *l, char kode, Teks subject, int idx);

/**
 * @brief Mengeluarkan elemen pertama dari l lalu menyimpannya ke dalam X
 *
 * @param l
 * @param X
 */
void removeFirstLDinNotif(LDinNotif *l, LDinNtfEl *val);

/**
 * @brief menghapus nilai pada indeks idx list din l dan menyimpannya dalam val
 *
 * @param l list yang akan dihapus elemennya
 * @param val penyimpanan nilai yang dihapus dari list
 * @param idx indeks yang akan dihapus elemennya
 */
void removeAtLDinNotif(LDinNotif *l, LDinNtfEl *val, IdxType idx);

/**
 * @brief menghapus elemen terakhir pada list dan menyimpannya dalam val
 *
 * @param l list yang akan dihapus elemen terakhirnya
 * @param val penyimpanan nilai yang dihapus dari list
 */
void removeLastLDinNotif(LDinNotif *l, LDinNtfEl *val);

/**
 * @brief Menambahkan capacity l sebanyak num
 * @param l
 * @param num Tambahan capacity l
 */
void expandLDinNotif(LDinNotif *l, int num);

#endif