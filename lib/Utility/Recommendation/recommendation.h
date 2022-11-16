#include "../../ADT/ListDinFoodSet/ldinfoodset.h"
#include "../../ADT/ListDinTeks/ldinteks.h"
#include "../../ADT/Tree/tree.h"

/**
 * @brief Mengkonversi foodQueue menjadi foodSet
 *
 * @param FQ
 * @param nama nama foodSet yang dihasilkan
 * @return FoodSet
 */
FoodSet FQToFS(FoodQueue FQ, Teks nama);

/**
 * @brief Megonversi resep dalam ListNode menjadi LDFS
 *
 * @param resep
 * @return LDinFoodSet
 */
LDinFoodSet resepToLDFS(ListNode resep);

/**
 * @brief Memberikan rekomendasi makanan berdasar makanan di inventory dan resep di resepLDFS
 *
 * @param resepLDFS
 * @param inventory
 * @param resep
 *
 */
void recommend(LDinFoodSet resepLDFS, FoodQueue inventory, ListNode resep);

/**
 * @brief Menghasilkan list makanan bahan dari makanan dengan id yang dimasukkan.
 *
 * @param resep
 * @param id
 */

LDinMakanan ingredientGenerator(Address resepMakanan, int id);

void printRecommendation(LDinTeks iRec, LDinTeks pRec, ListNode resep, FoodSet inventorySet);

/**
 * @brief Algoritma alternatif untuk rekomendasi
 *
 * @param resepLDFS
 * @param inventory
 * @param resep
 */
void recommendTiered(LDinFoodSet resepLDFS, FoodQueue inventory, ListNode resep);
