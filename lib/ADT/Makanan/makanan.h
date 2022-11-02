#include "../boolean.h"
#include "../Teks/teks.h"
#include "../Waktu/waktu.h"
#include "../AksiLokasi/aksiLokasi.h"

#ifndef makanan_H
#define makanan_H

typedef Teks makananID;

/**
 * @brief Makanan yang menjadi fokus dari tubes ini
 * @param nama nama makanan yang dibatasi 100 karakter
 * @param idUnik id yang berbeda untuk tiap makanan
 * @param idTipe id yang berbeda untuk makanan dengan tipe yang berbeda
 * @param waktuSampai waktu sebuah makanan sampai pada BNMO. Jika makanan ada di inventory, memiliki nilai 0.
 * @param waktuBasi waktu sebuah makanan basi. Jika makanan ada di queue pengiriman, makanan memiliki waktuBasi default sesuai
 * @param panjang ukuran panjang dari makanan untuk ADT Kulkas
 * @param lebar ukuran lebar dari makanan untuk ADT Kulkas
 *
 */
typedef struct
{
    Teks nama;
    makananID idUnik;
    makananID idTipe;
    Waktu waktuBasi;
    Waktu waktuSampai;
    AksiLokasi aksiLokasi;
    int panjang;
    int lebar;

} Makanan;

#define namaMakanan(S) (S).nama
#define basiDalam(S) (S).waktuBasi
#define sampaiDalam(S) (S).waktuSampai
#define idUnik(S) (S).idUnik
#define idTipe(S) (S).idTipe
#define aksiLokasi(S) (S).aksiLokasi
#define panjang(S) (S).panjang
#define lebar(S) (S).lebar
#define getFHow(S) aksi(aksiLokasi(S))
#define getFInPlace(S) lokasiAL(aksiLokasi(S))
#define getFInTime(S) durasi(aksiLokasi(S))

/**
 * @brief Fungsi untuk menginisialisasi makanan
 * @param makanan pointer ke makanan yang ingin dibuat
 * @param namaMakanan nama dari makanan yang ingin dibuat
 * @param idTipe id dari tipe makanan yang dibuat
 * @param idUnik id unik dari makanan yang dibuat
 * @param waktuBasi waktu ketika makanan akan basi. Default ketika di dalam delivery queue.
 * @param waktuSampai waktu ketika makanan akan sampai. 0 di dalam inventory queue.
 * @param aksiLokasi bagaimana, di mana, berapa lama makanan bisa didapatkan
 * @param panjang ukuran panjang dari makanan untuk ADT Kulkas
 * @param lebar ukuran lebar dari makanan untuk ADT Kulkas
 *
 * @return Makanan pada address yang diberikan terdefinisi dengan parameter yang diberikan
 */
void buatMakanan(Makanan *makanan, Teks namaMakanan, Teks idTipe, Teks idUnik, Waktu waktuBasi, Waktu waktuSampai, AksiLokasi aksiLokasi, int panjang, int lebar);

/**
 * @brief Fungsi untuk mendapatkan id gabungan makanan
 * @param makanan makanan yang ingin didapatkan id-nya
 * @return id gabungan dalam ADT Teks
 */
Teks idMakanan(Makanan makanan);

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

/**
 * @brief Fungsi untuk mengecek apakah 2 makanan sama (nama, id, waktu kadaluarsa, lama pengiriman sama)
 *
 * @param m1 makanan yang ingin dicek infonya
 * @param m2 makanan yang ingin dicek infonya
 * @return boolean apakah m1 == m2
 */
boolean isMakananEqual(Makanan m1, Makanan m2);

/**
 * @brief Majukan waktu dari makanan di dalam inventory m sebesar w. Jika waktu basi kurang dari w maka jadikan 0.
 *
 * @param m
 * @param w
 */
void majukanWMInventory(Makanan *m, Waktu w);

/**
 * @brief Majukan waktu dari makanan di dalam delivery m sebesar w. Lingkup fungsi termasuk seluruh lifecycle makanan, bukan hanya dari delivery ke inventory saja (waktu basi juga bisa dikurangkan).
 *
 * @param m
 * @param w
 * @param newPosisi char d, i, b apakah makanan w akan tetap di delivery, pindah ke inventory, atau ke inventory lalu basi. Masukkan c jika ingin fungsinya menghitung sendiri
 */
void majukanWMDelivery(Makanan *m, Waktu w, char newPosisi);

/**
 * @brief Menentukan apakah suatu makanan m di delivery queue setelah waktu w akan masih ada di delivery queue, sampai ke inventory queue, atau sampai ke inventory queue lalu basi
 *
 * @param m
 * @param w
 * @return char d untuk delivery, i untuk inventory, b untuk basi
 */
char newPosisiMDelivery(Makanan m, Waktu w);

/**
 * @brief Menentukan luas dari makanan untuk ADT Kulkas
 *
 * @param m
 */
int luasMakanan(Makanan m);

#endif