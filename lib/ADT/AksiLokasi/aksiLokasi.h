#ifndef AKSILOKASI_H
#define AKSILOKASI_H

#include "../boolean.h"
#include "../Point/Point.h"
#include "../Teks/teks.h"
#include "../Waktu/waktu.h"

/**
 * @brief Tipe Data AksiLokasi
 * @param aksi: Nama aksi yang bisa dilakukan
 * @param lokasi: ADT Point tempat aksi tersebut dilakukan
 * @param waktu: ADT Waktu lama pengerjaan
 */
typedef struct
{
    Teks aksi;
    POINT lokasi;
    Waktu durasi;

} AksiLokasi;

/**
 * @brief Notasi Akses: Selektor AksiLokasi
 */
#define aksi(AL) (AL).aksi
#define lokasi(AL) (AL).lokasi
#define durasi(AL) (AL).durasi

/**
 * @brief Membentuk Tipedata AksiLokasi
 * @param aksi: Nama aksi yang bisa dilakukan
 * @param x : absis lokasi
 * @param y : ordinat lokasi
 * @param HH : hari dari durasi aksiLokasi
 * @param JJ : jam dari durasi aksiLokasi
 * @param MM : menit dari durasi aksiLokasi
 * @param DD : detik dari durasi aksiLokasi
 */
void buatAksiLokasi(AksiLokasi *AL, Teks aksi, int x, int y, int HH, int JJ, int MM, int DD);

/**
 * @brief Menampilkan Tipedata Aksilokasi
 * @param AL: Tipedata AksiLokasi yang akan ditampilkan
 */
void displayAksiLokasi(AksiLokasi AL);

/**
 * @brief Mengembalikan tempat aksi lokasi yang sesuai untuk teks AL yang diberikan
 *
 * @param aLT Teks dari aLT yang ingin dicari aksi lokasinya
 * @param aLArray
 * @return POINT
 */
POINT aksiLokasiDiMana(Teks aLT, AksiLokasi aLArray[]);

#endif