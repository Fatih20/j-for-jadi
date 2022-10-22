/* File : prioqueue.h */
/* Definisi ADT Priority Queue Char dengan representasi array secara eksplisit dan alokasi dinamik */
/* Model Implementasi Versi III dengan circular buffer */
/* Elemen queue terurut membesar berdasarkan elemen time */

#ifndef deliveryQueue
#define deliveryQueue

#include "../boolean.h"
#include "../ListDinMakanan/ldinmakanan.h"
#include "../Makanan/makanan.h"

/**
 * @brief Konstanta untuk address tak terdefinisi
 *
 */
#define Nil -1

typedef int address; /* indeks tabel */
typedef LDinMakananEl DeliveryQueueEl;

typedef struct
{
    LDinMakanan content; /* tabel penyimpan elemen */
    address headDQ;      /* alamat penghapusan */
    address tailDQ;      /* alamat penambahan */
} DeliveryQueue;

/**
 * @brief Indeks head dari DQ
 *
 */
#define headDQ(DQ) (DQ).headDQ

/**
 * @brief Indeks tail dari DQ
 *
 */
#define tailDQ(DQ) (DQ).tailDQ

/**
 * @brief Elemen pada indeks head dari DQ
 *
 * @param DQ
 * @return DeliveryQueueEl
 */
DeliveryQueueEl headElDQ(DeliveryQueue DQ);

/**
 * @brief Elemen pada indeks tail dari DQ
 *
 * @param DQ
 * @return DeliveryQueueEl
 */
DeliveryQueueEl tailElDQ(DeliveryQueue DQ);

/**
 * @brief Elemen pada indeks ke-i dari DQ
 *
 * @param DQ
 * @return DeliveryQueueEl
 */
DeliveryQueueEl elmtDQ(DeliveryQueue DQ, int i);

/**
 *
 * @brief Mengirim true jika DQ kosong
 *
 * @param DQ DeliveryQueue yang ingin dicek kekosongannya
 * @return boolean
 */
void buatDQKosong(DeliveryQueue *DQ, int max);

/**
 * @brief Mengirim jumlah elemen pada DQ
 *
 * @param DQ DeliveryQueue yang ingin dicek jumlah elemennnya
 * @return integer
 */
int nElmt(DeliveryQueue DQ);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika DQ kosong. */

/**
 * @brief Mengembalikan elemen ke-i pada DQ
 *
 * @param DQ
 * @param i
 * @return DeliveryQueueEl
 */
DeliveryQueueEl elmt(DeliveryQueue DQ, address i);
/* Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika DQ kosong. */

/**
 * @brief Membuat DeliveryQueue kosong dengan kapasitas awal max
 *
 * @param DQ Alamat ke DeliveryQueue yang ingin didefinisikan
 * @param max Kapasitas maksimum awal dari DeliveryQueue
 * todo Yeah I'm pretty sure list din should be wary of failing to allocate memory
 */
void makeEmpty(DeliveryQueue *DQ, int max);

/**
 * @brief Mendealokasikan DQ
 *
 * @param DQ
 */
void deAlokasi(DeliveryQueue *DQ);
/* Proses: Mengembalikan memori DQ */
/* I.S. DQ pernah dialokasi */
/* F.S. DQ menjadi tidak terdefinisi lagi, MaxEl(DQ) diset 0 */

/**
 * @brief Memasukkan X ke DQ sesuai aturan prioritas delivery time. Yaitu makanan yang paling cepat sampai terlebih dahulu dan jika sama, maka dimasukkan sesuai urutan masuknya yang lebih dulu. Tail mundur satu.
 *
 * @param DQ
 * @param X
 */
void enqueue(DeliveryQueue *DQ, DeliveryQueueEl X);

/**
 * @brief Menghapus elemen teratas DQ dengan aturan FIFO. Menyimpan elemen yang dihapus ke address X. Head mundur
 *
 * @param DQ
 * @param X
 */
void dequeue(DeliveryQueue *DQ, DeliveryQueueEl *X);

/**
 * @brief Mencetak seluruh elemen di dalam DQ dengan cetakMakanan
 *
 * @param DQ
 */
void cetakDeliveryQueue(DeliveryQueue DQ);

#endif
