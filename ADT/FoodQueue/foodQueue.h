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
 * @param DQ
 * @param X
 */
void enqueueDelivery(FoodQueue *DQ, FoodQueueEl X);

/**
 * @brief Memasukkan X ke FQ sesuai aturan prioritas waktu basi. Yaitu makanan yang paling cepat basi terlebih dahulu dan jika sama, maka dimasukkan sesuai urutan masuknya yang lebih dulu. Tail mundur satu.
 *
 * @param IQ
 * @param X
 */
void enqueueInventory(FoodQueue *IQ, FoodQueueEl X);

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
 * @param idTipeS id dari tipe yang ingin dihapus dari queue
 * @param deletedVal alamat tempat makanan yang dihapus akan disimpan
 *
 */
void deleteByIdTipe(FoodQueue *FQ, char idTipeS[], Makanan *deletedVal);

/**
 * @brief Mengembalikan indeks makanan paling awal dari tipe yang diberikan
 *
 * @param FQ
 * @param idTipe id dari tipe makanan yang ingin dicari
 * @return int indeks dari tipe makanan yang diberikan yang paling awal dalam queue. -1 jika makanan tidak ada.
 */
int idxMakanan(FoodQueue FQ, char idTipeS[]);

/**
 * @brief Men-dequeue elemen di-head yang memiliki waktu basi 0 sampai elemen di-head belum basi. Gunakan sesuai spek parameter.
 *
 * @param FQ Inventory queue yang ingin dihapus elemennya yang sudah basi
 */
void hapusBasi(FoodQueue *FQ);

/**
 * @brief Men-dequeue elemen di-head queue pertama yang memiliki waktu sampai 0 sampai elemen di-head belum sampai. Elemen yang di-dequeue dimasukkan ke queue kedua. Gunakan sesuai spek parameter.
 *
 * @param DQ Delivery queue yang makanan sampainya akan dikeluarkan
 * @param IQ Inventory queue yang akan menerima elemen yang dikeluarkan dari DQ
 *
 */
void hapusSampai(FoodQueue *DQ, FoodQueue *IQ);

/**
 * @brief Memajukan waktu untuk delivery queue. Mengurangi waktu sampai semua makanan di dalamnya. Kemudian menjalankan hapusSampai.
 *
 * @param DQ Delivery queue yang dimajukan waktunya kemudian dipindah ke IQ makanannya yang sudah sampai
 * @param IQ Inventory queue yang menerima makanan yang sampai setelah waktu dimajukan
 */
void majukanWSampai(FoodQueue *DQ, FoodQueue *IQ);

/**
 * @brief Memajukan waktu untuk inventory queue. Mengurangi waktu basi semua makanan di dalamnya. Kemudian menjalankan hapusBasi
 *
 * @param IQ yang ingin dimajukan waktunya lalu dihapus elemennya yang basi setelah waktu dimajukan
 */
void majukanWBasi(FoodQueue *IQ);

/**
 * @brief Lakukan majukanWBasi ke IQ lalu lakukan majukanWSampai kepada DQ dan IQ
 *
 * @param DQ Delivery queue
 * @param IQ Inventory queue
 */
void majukanWFQ(FoodQueue *DQ, FoodQueue *IQ);

#endif
