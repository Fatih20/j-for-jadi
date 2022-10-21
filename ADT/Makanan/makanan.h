#include "../boolean.h"

#ifndef makanan_H
#define makanan_H

typedef char *makananID;

/**
 * @brief Makanan yang menjadi fokus dari tubes ini
 * @param nama nama makanan yang dibatasi 100 karakter
 * @param idUnik id yang berbeda untuk tiap makanan
 * @param idTipe id yang berbeda untuk makanan dengan tipe yang berbeda
 * @param waktuSampai waktu sebuah makanan sampai pada BNMO. Jika makanan ada di inventory, memiliki nilai 0.
 * @param waktuBasi waktu sebuah makanan basi. Jika makanan ada di queue pengiriman, makanan memiliki waktuBasi default sesuai
 *
 */
typedef struct
{
    char nama[100];
    makananID idUnik;
    makananID idTipe;
    int waktuBasi;
    int waktuSampai;
} Makanan;

#define namaMakanan(S) (S).nama
#define basiDalam(S) (S).waktuBasi
#define sampaiDalam(S) (S).waktuSampai
#define idUnik(S) (S).idUnik
#define idTipe(S) (S).idTipe

/**
 * @brief Fungsi untuk menginisialisasi makanan
 * @param makanan pointer ke makanan yang ingin dibuat
 * @param waktuBasi waktuBasi yang akan diberikan ke makanan yang dibuat
 * @param waktuSampai waktuSampai yang akan diberikan ke makanan yang dibuat
 * @param idTipe id dari tipe makanan yang dibuat
 * @param idUnik id unik dari makanan yang dibuat
 *
 * @return Makanan pada address yang diberikan terdefinisi dengan parameter yang diberikan
 */
void buatMakanan(Makanan *makanan, char *namaMakanan, int waktuBasi, int waktuSampai, char *idUnik, char *idTipe);

/**
 * @brief Fungsi untuk menginisialisasi makanan
 * @param makanan makanan yang ingin dicetak
 *
 * @return Tercetak nama makanan, id, waktu basi, dan waktu sampai
 */
void cetakMakanan(Makanan makanan);

/**
 * @brief Fungsi untuk membandingkan nama makanan
 * @param m1 makanan yang namanya ingin dibandingkan
 * @param m2 makanan yang namanya ingin dibandingkan
 *
 * @return boolean apakah nama m1 sama dengan m2
 */
boolean namaMakananSama(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan tipe makanan dari 3 id pertama
 * @param m1 makanan yang namanya ingin dibandingkan
 * @param m2 makanan yang namanya ingin dibandingkan
 *
 * @return boolean apakah tipe m1 sama dengan m2
 */
boolean tipeMakananSama(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk mengecek apakah waktu basi 2 makanan sama
 * @param m1 makanan yang ingin dibandingkan
 * @param m2 makanan yang ingin dibandingkan
 *
 * @return boolean apakah m1 basi bersamaan dengan m2
 */
boolean basiBersamaan(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu basi 2 makanan
 * @brief Jika sama maka akan return false
 * @param m1 makanan yang waktu basinya ingin dibandingkan
 * @param m2 makanan yang waktu basinya ingin dibandingkan
 *
 * @return boolean apakah m1 basi duluan dibanding m2
 */
boolean basiDuluan(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu basi 2 makanan
 * @param m1 makanan yang waktu basinya ingin dibandingkan
 * @param m2 makanan yang waktu basinya ingin dibandingkan
 *
 * @return boolean apakah m1 basi duluan atau bersamaan dengan m2
 */
boolean basiDuluanAtauSama(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu basi 2 makanan
 * @param m1 makanan yang waktu basinya ingin dibandingkan
 * @param m2 makanan yang waktu basinya ingin dibandingkan
 *
 * @return boolean apakah m1 basi setelah atau bersamaan dengan m2
 */
boolean basiSetelahAtauSama(Makanan m1, Makanan m2);
/**
 * @brief Fungsi untuk mengecek apakah waktu sampai 2 makanan sama
 * @param m1 makanan yang ingin dibandingkan
 * @param m2 makanan yang ingin dibandingkan
 *
 * @return boolean apakah m1 sampai bersamaan dengan m2
 */
boolean sampaiBersamaan(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu sampai 2 makanan. Jika sama maka akan return false
 * @param m1 makanan yang waktu sampainya ingin dibandingkan
 * @param m2 makanan yang waktu sampainya ingin dibandingkan
 *
 * @return boolean apakah m1 sampai duluan dibanding m2
 */
boolean sampaiDuluan(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu sampai 2 makanan
 * @param m1 makanan yang waktu sampainya ingin dibandingkan
 * @param m2 makanan yang waktu sampainya ingin dibandingkan
 *
 * @return boolean apakah m1 sampai duluan atau bersamaan dengan m2
 */
boolean sampaiDuluanAtauSama(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu sampai 2 makanan
 * @param m1 makanan yang waktu sampainya ingin dibandingkan
 * @param m2 makanan yang waktu sampainya ingin dibandingkan
 *
 * @return boolean apakah m1 sampai setelah atau bersamaan dengan m2
 */
boolean sampaiSetelahAtauSama(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk mengecek apakah waktu sampai 2 makanan sama
 * @param m1 makanan yang ingin dibandingkan
 * @param m2 makanan yang ingin dibandingkan
 *
 * @return boolean apakah m1 sampai bersamaan dengan m2
 */
boolean sampaiBersamaan(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu sampai 2 makanan
 * @brief Jika sama maka akan return false
 * @param m1 makanan yang waktu sampainya ingin dibandingkan
 * @param m2 makanan yang waktu sampainya ingin dibandingkan
 *
 * @return boolean apakah m1 sampai duluan dibanding m2
 */
boolean sampaiDuluan(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu sampai 2 makanan
 * @param m1 makanan yang waktu sampainya ingin dibandingkan
 * @param m2 makanan yang waktu sampainya ingin dibandingkan
 *
 * @return boolean apakah m1 sampai duluan atau bersamaan dengan m2
 */
boolean sampaiDuluanAtauSama(Makanan m1, Makanan m2);

/**
 * @brief Fungsi untuk membandingkan waktu sampai 2 makanan
 * @param m1 makanan yang waktu sampainya ingin dibandingkan
 * @param m2 makanan yang waktu sampainya ingin dibandingkan
 *
 * @return boolean apakah m1 sampai setelah atau bersamaan dengan m2
 */
boolean sampaiSetelahAtauSama(Makanan m1, Makanan m2);

#endif