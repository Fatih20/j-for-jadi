#ifndef ldinfoodset
#define ldinfoodset

#include "../FoodSet/foodSet.h"

/*  Kamus Umum */
#define IDX_MIN 0
/* Indeks minimum list */
#define IDX_UNDEF -1
/* Indeks tak terdefinisi*/

/* Definisi elemen dan koleksi objek */
typedef FoodSet LDinFoodSetEl; /* type elemen list */
typedef int IdxType;
/**
 * @brief ADT LDinMakanan yang merupakan list dinamis rata kiri dengan LDinFoodSetEl Makanan
 * @param nEff >=0, banyak elemen efektif
 * @param capacity kapasitas/ukuran list
 */
typedef struct
{
    LDinFoodSetEl *content;
    int nEff;
    int capacity;
} LDinFoodSet;

/* ********** SELEKTOR ********** */
#define nEffLDFS(l) (l).nEff
#define contentLDFS(l) (l).content
#define elmtLDFS(l, i) (l).content[i]
#define capacityLDFS(l) (l).capacity

/* ********** KONSTRUKTOR ********** */

/**
 * @brief Konstruktor : Membuat list food set kosong
 *
 * @param l alamat list food set
 * @param capacity kapasitas list dinamis l
 */
void buatLDinFoodSet(LDinFoodSet *l, int capacity);

/**
 * @brief men-dealokasi memori list l
 *
 * @param l list makanan l yang mula-mula terdefinisi
 */
void dealokasiLDinFoodSet(LDinFoodSet *l);

/* ********** SELEKTOR (TAMBAHAN) ********** */
/**
 * @brief mengembalikan banyaknya elemen list food set l
 *
 * @param l list food set yang terdefinisi (bisa kosong)
 * @return int : banyaknya elemen dalam list l
 */
int panjangLDinFoodSet(LDinFoodSet l);

/* *** Selektor INDEKS *** */

/**
 * @brief mengembalikan indeks elemen l terakhir
 *
 * @param l prekondisi : l tidak kosong
 * @return IdxType : indeks elemen l terakhir
 */
IdxType lastIdxLDinFoodSet(LDinFoodSet l);

/* ********** Test Indeks yang valid ********** */

/**
 * @brief Mengirimkan true jika i adalah indeks yang valid utk kapasitas list l
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxValidLDinFoodSet(LDinFoodSet l, IdxType i);

/**
 * @brief Mengirimkan true jika i adalah indeks yang terdefinisi utk list, yaitu antara 0..NEff-1
 *
 * @param l
 * @param i indeks yang akan dicek
 * @return boolean
 */
boolean isIdxEffLDinFoodSet(LDinFoodSet l, IdxType i);

/* ********** TEST KOSONG/PENUH ********** */
/**
 * @brief Mengirimkan true jika list kosong, false jika list tidak kosong.
 *
 * @param l
 * @return boolean
 */
boolean isEmptyLDinFoodSet(LDinFoodSet l);

/**
 * @brief  Mengirimkan true jika list l penuh, mengirimkan false jika tidak
 *
 * @param l
 * @return boolean
 */
boolean isFullLDinFoodSet(LDinFoodSet l);

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
// void readLDinFoodSet(LDinFoodSet *l);

/**
 * @brief Menampilkan isi list makanan dengan format
 * " ID makanan :
 * Nama makanan :
 * Waktu kadaluarsa :
 * Lama pengiriman :
 * Lokasi aksi : "
 * @param l boleh kosong
 */
void printLDinFoodSet(LDinFoodSet l);

/* ********** OPERASI LAIN ********** */
/**
 * @brief Menyalin isi lIn ke lOut
 *
 * @param lIn lIn terdefinisi
 * @param lOut sembarang
 */
void copyLDinFoodSet(LDinFoodSet lIn, LDinFoodSet *lOut);

/**
 * @brief Mengeluarkan elemen pertama dari l lalu menyimpannya ke dalam X
 *
 * @param l
 * @param X
 */
void removeFirstLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl *X);

/**
 * @brief menghapus nilai pada indeks idx list din l dan menyimpannya dalam val
 *
 * @param l list yang akan dihapus elemennya
 * @param val penyimpanan nilai yang dihapus dari list
 * @param idx indeks yang akan dihapus elemennya
 */
void removeAtLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl *val, IdxType idx);

/**
 * @brief menghapus elemen terakhir pada list dan menyimpannya dalam val
 *
 * @param l list yang akan dihapus elemen terakhirnya
 * @param val penyimpanan nilai yang dihapus dari list
 */
void removeLastLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl *val);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertFirstLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl val);

/**
 * @brief memasukkan val sebagai elemen pertama l, jika l penuh maka akan diexpand
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan ke dalam l
 */
void insertLastLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl val);

/* ********** MENAMBAH DAN MENGHAPUS ELEMEN DI AKHIR ********** */
/**
 * @brief Menambahkan val sebagai elemen list pada index idx. Jika list penuh, maka list akan diexpand. Jika idx tidak valid, akan dicetak pesan error.
 *
 * @param l l bisa kosong
 * @param val elemen yang akan dimasukkan pada list
 * @param idx index tempat pengisian val
 */
void insertAtLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl val, IdxType idx);

/**
 * @brief Menambahkan capacity l sebanyak num
 * @param l
 * @param num Tambahan capacity l
 */

void expandLDinFoodSet(LDinFoodSet *l, int num);

/**
 * @brief Mengecek apakah ada set di l dengan nama namaMakanan
 *
 * @param l
 * @param namaMakanan
 * @return boolean
 */
boolean isMakananInLDFS(LDinFoodSet *l, Teks namaMakanan);

/**
 * @brief Indeks elemen l sebelum elemen yang idTipe-nya lebih tinggi dari idTipe yang diberikan
 *
 * @param l
 * @param idTipeI
 * @return int
 */
int indexBeforeHigher(LDinFoodSet l, int idTipeI);

/**
 * @brief Menyisipkan fs sebelum elemen yang lebih tinggi idTipe-nya daripada fs.
 *
 * @param l
 * @param fs
 */
void insertOrderedLDFS(LDinFoodSet *l, FoodSet fs);

/**
 * @brief Mencari di indeks keberapa foodSet dengan id sesuai ditemukan
 *
 * @param l
 * @param id
 * @return int
 */
int searchOrderedLDFS(LDinFoodSet l, Teks id);

/**
 * @brief Fungsi yang sebenarnya dipanggil oleh search ordered
 *
 * @param l
 * @param id
 * @param hi
 * @param lo
 * @return int
 */
int searchOrderedWLDFS(LDinFoodSet l, int id, int lo, int hi);

#endif