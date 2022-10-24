#include "../boolean.h"

#ifndef waktu_H
#define waktu_H

/**
 * @brief tipe data waktu
 * @param HH komponen hari dari waktu
 * @param JJ komponen jam dari waktu
 * @param MM komponen menit dari waktu
 * @param DD komponen detik dari waktu
 *
 */
typedef struct
{
    int HH; /* integer [>=0] */
    int JJ; /* integer [0..23] */
    int MM; /* integer [0..59] */
    int DD; /* integer [0..59] */
} Waktu;

#define Hari(W) (W).HH
#define Jam(W) (W).JJ
#define Menit(W) (W).MM
#define Detik(W) (W).DD

/**
 * @brief Fungsi untuk menguji apakah H,J,M,D dapat membentuk W yang valid
 * @param H komponen hari dari waktu yang dibuat
 * @param J komponen jam dari waktu yang dibuat
 * @param M komponen menit dari waktu yang dibuat
 * @param D komponen detik dari waktu yang dibuat
 *
 * @return boolean apakah H,J,M,D dapat membentuk W yang valid
 */
boolean isWaktuValid(int H, int J, int M, int D);

/**
 * @brief Fungsi untuk menginisialisasi waktu
 * @param HH komponen hari dari waktu yang dibuat
 * @param JJ komponen jam dari waktu yang dibuat
 * @param MM komponen menit dari waktu yang dibuat
 * @param DD komponen detik dari waktu yang dibuat
 *
 * @return waktu terdefinisi dengan parameter yang diberikan
 */
Waktu buatWaktu(int HH, int JJ, int MM, int);

/**
 * @brief Prosedur untuk membuat waktu berdasarkan masukan yang dibaca
 * @param W waktu yang terbentuk dari hasil pembacaan komponen-komponennya
 *
 * @return waktu terdefinisi dan merupakan waktu yang valid
 */
void bacaWaktu(Waktu *W);

/**
 * @brief Prosedur untuk menuliskan waktu
 * @param W waktu yang akan dituliskan
 *
 * @return waktu dituliskan dengan format HH hari JJ jam MM menit DD detik
 */
void tulisWaktu(Waktu W);

/**
 * @brief Fungsi untuk mengubah Waktu menjadi detik
 * @param W waktu yang akan ditentukan nilai detiknya
 *
 * @return nilai detik dari suatu Waktu
 */
long waktuToDetik(Waktu W);

/**
 * @brief Fungsi untuk mengubah detik ke Waktu
 * @param N detik yang akan diubah menjadi Waktu
 *
 * @return Waktu yang bernilai sama dengan masukan detik
 */
Waktu detikToWaktu(long N);

/**
 * @brief Fungsi untuk membandingkan dua Waktu
 * @param W1 waktu yang dibandingkan
 * @param W2 waktu yang dibandingkan
 *
 * @return boolean apakah W1 = W2
 */
boolean WEQ(Waktu W1, Waktu W2);

/**
 * @brief Fungsi untuk membandingkan dua Waktu
 * @param W1 waktu yang dibandingkan
 * @param W2 waktu yang dibandingkan
 *
 * @return boolean apakah W1 != W2
 */
boolean WNEQ(Waktu W1, Waktu W2);

/**
 * @brief Fungsi untuk membandingkan dua Waktu
 * @param W1 waktu yang dibandingkan
 * @param W2 waktu yang dibandingkan
 *
 * @return boolean apakah W1 < W2
 */
boolean WLT(Waktu W1, Waktu W2);

/**
 * @brief Fungsi untuk membandingkan dua Waktu
 * @param W1 waktu yang dibandingkan
 * @param W2 waktu yang dibandingkan
 *
 * @return boolean apakah W1 > W2
 */
boolean WGT(Waktu W1, Waktu W2);

/**
 * @brief Fungsi untuk mendapatkan nilai waktu N detik setelah waktu masukan
 * @param W waktu yang ingin ditentukan N detik setelahnya
 * @param N banyak detik yang ditambahkan ke waktu W
 *
 * @return waktu N detik setelah W
 */
Waktu nextNDetik(Waktu W, int N);

/**
 * @brief Fungsi untuk menghitung selisih dari dua Waktu
 * @param WAw waktu awal
 * @param Wakh waktu akhir
 *
 * @return nilai dari durasi antara waktu awal dengan waktu akhir
 */
long durasi(Waktu WAw, Waktu WAkh);

#endif