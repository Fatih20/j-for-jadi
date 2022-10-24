#ifndef foodQueue
#define foodQueue

#include "../boolean.h"
#include "../ListDinMakanan/ldinmakanan.h"
#include "../Makanan/makanan.h"

/**
 * @brief Konstanta untuk address tak terdefinisi
 *
 */
#define Nil -1

typedef int address; /* Indeks tabel */
typedef LDinMakananEl FoodQueueEl;

typedef struct
{
    LDinMakanan content; /* tabel penyimpan elemen */
    address headFQ;      /* alamat penghapusan */
    address tailFQ;      /* alamat penambahan */
} FoodQueue;

/**
 * @brief Indeks head dari FQ
 *
 */
#define headFQ(FQ) (FQ).headFQ

/**
 * @brief Indeks tail dari FQ
 *
 */
#define tailFQ(FQ) (FQ).tailFQ

/**
 * @brief Elemen pada indeks head dari FQ
 *
 * @param FQ
 * @return FoodQueueEl
 */
FoodQueueEl headElFQ(FoodQueue FQ);

/**
 * @brief Elemen pada indeks tail dari FQ
 *
 * @param FQ
 * @return FoodQueueEl
 */
FoodQueueEl tailElFQ(FoodQueue FQ);

/**
 * @brief Elemen pada indeks ke-i dari FQ
 *
 * @param FQ
 * @return FoodQueueEl
 */
FoodQueueEl elmtFQ(FoodQueue FQ, int i);

/**
 *
 * @brief Mengirim true jika FQ kosong
 *
 * @param FQ FoodQueue yang ingin dicek kekosongannya
 * @return boolean
 */
void buatFQKosong(FoodQueue *FQ, int max);

/**
 * @brief Mengirim jumlah elemen pada FQ
 *
 * @param FQ FoodQueue yang ingin dicek jumlah elemennnya
 * @return integer
 */
int nElmt(FoodQueue FQ);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika FQ kosong. */

/**
 * @brief Mengembalikan elemen ke-i pada FQ
 *
 * @param FQ
 * @param i
 * @return FoodQueueEl
 */
FoodQueueEl elmt(FoodQueue FQ, address i);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika FQ kosong. */

/**
 * @brief Membuat FoodQueue kosong dengan kapasitas awal max
 *
 * @param FQ Alamat ke FoodQueue yang ingin didefinisikan
 * @param max Kapasitas maksimum awal dari FoodQueue
 * todo Yeah I'm pretty sure list din should be wary of failing to allocate memory
 */
void makeEmpty(FoodQueue *FQ, int max);

/**
 * @brief Mendealokasikan FQ
 *
 * @param FQ
 */
void deAlokasi(FoodQueue *FQ);
/* Proses: Mengembalikan memori FQ */
/* I.S. FQ pernah dialokasi */
/* F.S. FQ menjadi tidak terdefinisi lagi, MaxEl(FQ) diset 0 */

/**
 * @brief Memasukkan X ke FQ sesuai aturan prioritas waktu sampai. Yaitu makanan yang paling cepat sampai terlebih dahulu dan jika sama, maka dimasukkan sesuai urutan masuknya yang lebih dulu. Tail mundur satu.
 *
 * @param FQ
 * @param X
 */
void enqueueDelivery(FoodQueue *FQ, FoodQueueEl X);

/**
 * @brief Memasukkan X ke FQ sesuai aturan prioritas waktu basi. Yaitu makanan yang paling cepat basi terlebih dahulu dan jika sama, maka dimasukkan sesuai urutan masuknya yang lebih dulu. Tail mundur satu.
 *
 * @param FQ
 * @param X
 */
void enqueueInventory(FoodQueue *FQ, FoodQueueEl X);

/**
 * @brief Menghapus elemen teratas FQ dengan aturan FIFO. Menyimpan elemen yang dihapus ke address X. Head mundur
 *
 * @param FQ
 * @param X
 */
void dequeue(FoodQueue *FQ, FoodQueueEl *X);

/**
 * @brief Mencetak seluruh elemen di dalam FQ dengan cetakMakanan
 *
 * @param FQ
 */
void cetakFoodQueue(FoodQueue FQ);

/**
 * @brief Menggandakan isi FQ1 ke FQ2
 *
 * @param FQ1
 * @param FQ2 tujuan penggandaan. Harus sudah terdefinisi.
 *
 */
void copyFoodQueue(FoodQueue FQ1, FoodQueue *FQ2);

/**
 * @brief Menghapus sebuah elemen berdasar id tipe makanannya. Menghapus kemunculan pertama makanan dengan id tipe tersebut. Jika makanan tidak ada di queue, tidak ada yang terjadi.
 *
 * @param FQ Queue yang ingin dihapus salah elemennya
 * @param idTipe id dari tipe yang ingin dihapus dari queue
 * @param deletedVal alamat tempat makanan yang dihapus akan disimpan
 *
 */
void deleteByID(FoodQueue *FQ, Teks idTipe, Makanan *deletedVal);

/**
 * @brief Mengembalikan indeks makanan paling awal dari tipe yang diberikan
 *
 * @param FQ
 * @param idTipe id dari tipe makanan yang ingin dicari
 * @return int indeks dari tipe makanan yang diberikan yang paling awal dalam queue. -1 jika makanan tidak ada.
 */
int idxMakanan(FoodQueue *FQ, Teks idTipe);
#endif
