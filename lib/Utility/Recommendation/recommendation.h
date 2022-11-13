#include "../../ADT/ListDinFoodSet/ldinfoodset.h"
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
 * @brief Menghasilkan list teks id bahan dari makanan dengan id yang dimasukkan.
 *
 * @param resep
 * @param id
 */
void ingredientGenerator(ListNode resep, int id);

void printRecommendation(Teks idMakanan, ListNode resep, FoodSet inventorySet);
