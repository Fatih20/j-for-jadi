#include "../boolean.h"
#include "../ListDinKar/ldinkar.h"
#include "../../Utility/Printc/printc.h"

#ifndef teks_H
#define teks_H

/**
 * @brief String pengganti string yang memiliki batas 100 karakter
 * @param karArray array berisi karakter dari String
 */
typedef struct
{
    LDinKar karArray;
} Teks;

#define panjangT(T) nEffLDC((T).karArray)
#define karArrayT(T) (T).karArray
#define nthChar(T, i) elmtLDC(karArrayT(T), i)

/**
 * @brief Fungsi untuk membuat Teks dari string
 * @param string string yang ingin dijadikan Teks
 * @param teks Teks yang ingin diisi string yang diberikan
 *  *
 * @return Teks yang diberikan diisi karakter pada string bersangkutan
 */
void buatTeks(char string[], Teks *teks);

/**
 * @brief Fungsi untuk membuat Teks kosong
 * @param teks Teks yang ingin diinisialisasi
 *  *
 * @return teks memiliki panjang 0
 */
void buatTeksKosong(Teks *teks);

/**
 * @brief Mencetak isi teks dengan tidak diakhiri apapun
 * @param t teks yang ingin dicetak
 * @param color warna teks yang ingin dicetak
 * r = red
 * g = green
 * b = blue
 * y = yellow
 * c = cyan
 * m = magenta
 * p = purple
 * n or else = none
 *  *
 * @return t tercetak
 */
void cetakTeks(Teks t, char color);

/**
 * @brief Fungsi untuk menambahkan karakter ke akhir Teks. Tidak melakukan apa-apa jika panjang sudah penuh.
 * @param teks pointer ke teks yang ingin dioperasikan
 * @param kar karakter yang ingin ditambahkan
 *  *
 * @return Teks yang diberikan ditambahkan karakter yang diberikan
 */
void plusKar(Teks *teks, char kar);

/**
 * @brief Fungsi untuk menambahkan karakter ke awal Teks. Tidak melakukan apa-apa jika panjang sudah penuh.
 * @param teks pointer ke teks yang ingin dioperasikan
 * @param kar karakter yang ingin ditambahkan
 *  *
 * @return Teks yang diberikan ditambahkan karakter yang diberikan
 */
void prefixKar(Teks *teks, char kar);

/**
 * @brief Fungsi untuk menghapus karakter terakhir teks
 * @param teks Teks yang ingin dihapus karakter terakhirnya
 *  *
 * @return Teks yang diberikan length-nya berkurang 1 sehingga karakter terakhir sebelumnya siap di-override
 */
void delKar(Teks *teks);

/**
 * @brief mengubah t menjadi string. String harus lebih dahulu diinisialisasikan dengan panjang minimal panjang t ditambah 1
 *
 * @param t teks yang akan diubah menjadi string
 * @param string string yang sudah diinisialisasi dengan panjang panjangT ditambah 1
 */
void teksKeString(char string[], Teks teks);

/**
 * @brief Fungsi untuk membandingkan dua teks dan mengecek kesamaannya
 * @param t1 teks yang ingin dibandingkan
 * @param t2 teks yang ingin dibandingkan
 *  *
 * @return boolean apakah teks yang diberikan sama atau tidak
 */
boolean teksSama(Teks t1, Teks t2);

/**
 * @brief Fungsi untuk membandingkan dua teks dan mengecek kesamaannya tanpa membandingkan kapital
 * @param t1 teks yang ingin dibandingkan
 * @param t2 teks yang ingin dibandingkan
 *  *
 * @return boolean apakah teks yang diberikan sama atau tidak
 */
boolean teksSamaCI(Teks t1, Teks t2);
/**
 * @brief Fungsi untuk mengecek teks pertama lebih pendek dari yang kedua. Return false jika sama
 * @param t1 teks yang ingin dibandingkan
 * @param t2 teks yang ingin dibandingkan
 *  *
 * @return boolean apakah teks pertama lebih pendek atau tidak
 */
boolean teksLPendek(Teks t1, Teks t2);

/**
 * @brief Mengembalikan duplikat t1 yang semua karakternya diubah menjadi uppercase.
 *
 * @param t1
 * @return Teks
 */
Teks toUpper(Teks t1);

/**
 * @brief Mengembalikan duplikat t1 yang semua karakternya diubah menjadi lowercase
 *
 * @param t1
 * @return Teks
 */
Teks toLower(Teks t1);

/**
 * @brief Fungsi untuk mengecek teks pertama sama panjang dengan yang kedua
 * @param t1 teks yang ingin dibandingkan
 * @param t2 teks yang ingin dibandingkan
 *  *
 * @return boolean apakah teks yang diberikan sama panjang atau tidak
 */
boolean teksSamaP(Teks t1, Teks t2);

/**
 * @brief Fungsi untuk mengecek teks pertama lebih panjang dari yang kedua. Return false jika sama
 * @param t1 teks yang ingin dibandingkan
 * @param t2 teks yang ingin dibandingkan
 *  *
 * @return boolean apakah teks pertama lebih panjang atau tidak
 */
boolean teksLPanjang(Teks t1, Teks t2);

/**
 * @brief Fungsi untuk menggabungkan 2 teks. t1 lebih dulu lalu t2.
 * @param t1 teks yang ingin digabungkan
 * @param t2 teks yang ingin digabungkan
 * @param t3 pointer ke teks hasil penggabungan
 *
 *  *
 * @return teks baru yang merupakan penggabungan kedua teks
 */
void gabungkanTeks(Teks t1, Teks t2, Teks *t3);

/**
 * @brief Fungsi untuk menambahkan t2 ke depan t1. t1 harus sudah terdefinisi.
 * @param t1 target teks
 * @param t2 source teks
 */
void tambahkanTeks(Teks *t1, Teks t2);

/**
 * @brief Fungsi untuk menambahkan t2 ke awal t1. t1 harus sudah terdefinisi.
 * @param t1 target teks
 * @param t2 source teks
 */
void prependTeks(Teks *t1, Teks t2);

/**
 * @brief mengembalikan true jika teks t adalah sebuah integer
 *
 * @param t
 * @return boolean
 */
boolean isTeksInt(Teks t);

/**
 * @brief mengembalikan integer yang direpresentasikan oleh teks t
 *
 * @param t teks yang akan diubah menjadi integer
 * @return integer yang direpresentasikan oleh teks t
 */
int teksToInt(Teks t);

/**
 * @brief Mengubah int menjadi teks dengan leading zero ditambahkan sampai setidaknya tiga digit panjangnya
 *
 * @param i
 * @return Teks
 */
Teks intToTeks(int i);

#endif