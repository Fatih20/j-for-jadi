#ifndef foodSet
#define foodSet

#include "../boolean.h"
#include "../Teks/teks.h"
#include "../FoodQueue/foodQueue.h"
#include "../ListDinTeks/ldinteks.h"

/**
 * @brief Konstanta untuk address tak terdefinisi
 *
 */
#define Nil -1
#define capacityFS 101

/**
 * @brief Set makanan yang bisa menampung sampai 100 makanan
 *
 */
typedef struct
{
    Teks nama;
    int idTipe;
    int content[capacityFS];
} FoodSet;

/**
 * @brief Isi dari set
 *
 */
#define ContentFS(FS) (FS).content

/**
 * @brief Nama dari set
 *
 */
#define NameFS(FS) (FS).nama

/**
 * @brief idTipe dari set
 *
 */
#define IdFS(FS) (FS).idTipe

/**
 * @brief id ke-i dari set
 *
 */
#define ElmtFS(FS, i) (FS).content[i]

/**
 *
 * @brief Membuat set makanan kosong yang semua makanannya dari 0-100 inklusif di-set false.
 *
 * @param FS FoodSet yang ingin dibuat
 * @param name nama FoodSet yang ingin dibuat
 * @param idTipe id dari FoodSet yang ingin dibuat
 */
void buatFSKosong(FoodSet *fs, Teks nama, Teks id);

/**
 * @brief Mengembalikan jumlah elemen yang true di fs
 *
 * @param fs
 * @return int
 */
int nElmtFS(FoodSet fs);

/**
 * @brief Meng-increment elemen dengan id i sebanyak inc
 *
 * @param fs
 * @param i
 * @param inc
 * @return int
 */
int incrementIFS(FoodSet *fs, int i, int inc);

/**
 * @brief Meng-increment elemen dengan id i sebanyak 1
 *
 * @param fs
 * @param i
 * @param inc
 * @return int
 */
int incrementFS(FoodSet *fs, int i);

/**
 * @brief Membuat Food Set dengan id 0
 *
 * @param fs
 * @param nama
 */
void buatIdLFSKosong(FoodSet *fs, Teks nama);

/**
 * @brief Menghasilkan set baru yang merupakan multiset union dari fsa dan fsb
 *
 * @param fsa
 * @param fsb
 * @return FoodSet
 */
FoodSet unionFoodSet(FoodSet fsa, FoodSet fsb);

/**
 * @brief Menghasilkan set baru yang merupakan multiset intersection dari fsa dan fsb
 *
 * @param fsa
 * @param fsb
 * @return FoodSet
 */
FoodSet intersectionFoodSet(FoodSet fsa, FoodSet fsb);

/**
 * @brief Menghasilkan set baru yang merupakan multiset difference fsa - fsb
 *
 * @param fsa
 * @param fsb
 * @return FoodSet
 */
FoodSet differenceFoodSet(FoodSet fsa, FoodSet fsb);

/**
 * @brief Menghasilkan set baru yang merupakan penjumlahan multiset fsa dan fsb
 *
 * @param fsa
 * @param fsb
 * @return FoodSet
 */
FoodSet addFoodSet(FoodSet fsa, FoodSet fsb);

/**
 * @brief Apakah fsa subset dari fsb
 *
 * @param fsa
 * @param fsb
 * @return boolean
 */
boolean isSubsetfs(FoodSet fsa, FoodSet fsb);

/**
 * @brief Mencetak isi dari fs
 *
 * @param fs
 */
void cetakFoodSet(FoodSet fs);

/**
 * @brief Menambahkan elemen ke-i di fs sebanyak inc
 *
 * @param fs
 * @param i
 * @param inc
 * @return int
 */
int incrementIFS(FoodSet *fs, int i, int inc);

/**
 * @brief Menambahkan elemen ke-i di fs sebanyak 1
 *
 * @param fs
 * @param i
 * @return int
 */
int incrementFS(FoodSet *fs, int i);

/**
 * @brief Mengembalikan semua elemen yang tidak 0 di foodSet
 *
 * @param fs
 * @return LDinTeks
 */
LDinTeks setToList(FoodSet fs);

#endif
