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
    Waktu waktu;

} AksiLokasi;

/**
 * @brief Notasi Akses: Selektor AksiLokasi
 */
#define aksi(AL) (AL).aksi
#define lokasi(AL) (AL).lokasi
#define waktu(AL) (AL).waktu

/**
 * @brief Membentuk Tipedata AksiLokasi
 * @param aksi: Nama aksi yang bisa dilakukan
 * @param x : absis lokasi
 * @param y : ordinat lokasi
 * @param waktu: Lama waktu pengolahan dalam detik
 */
void buatAksiLokasi(AksiLokasi *AL, Teks aksi, int x, int y, int waktu);

/**
 * @brief Menampilkan Tipedata Aksilokasi
 * @param AL: Tipedata AksiLokasi yang akan ditampilkan
 */
void displayAksiLokasi(AksiLokasi AL);

#endif