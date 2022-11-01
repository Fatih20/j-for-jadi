#ifndef COMMANDS_H
#define COMMANDS_H
#include "../../ADT/Tree/tree.h"
#include <stdio.h>
#include "../../ADT/State/state.h"
#include "../../ADT/FoodQueue/foodQueue.h"
#include "../../ADT/AksiLokasi/aksiLokasi.h"
#include "../../ADT/Stack/stack.h"
#include "../../ADT/Matriks/matriks.h"
#include "../../ADT/Simulator/simulator.h"
#include "../../ADT/MBInput/mBInput.h"

void olahMakanan(Teks command, FoodQueue *inventory, FoodQueue *delivery, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState, boolean *isChangeStack);

void displayCookbook(ListNode *daftarResep);

void displayCatalog(LStatMakanan *daftarMakanan);

/**
 * @brief Menunjukkan makanan apa yang sedang dalam proses pengiriman ke pengguna
 *
 * @param dQ
 */
void displayDelivery(FoodQueue dQ);

/**
 * @brief Menunjukkan makanan apa yang sudah ada dalam inventory pengguna
 *
 * @param iQ
 */
void displayInventory(FoodQueue iQ);

/**
 * @brief Fungsi yang meng-handle pembelian makanan. Panggil ketika command BUY dimasukkan
 *
 * @param DQ
 * @param daftarMakanan
 * @param currState
 * @param Telepon aksiLokasi telepon
 * @param isChangeStack Apakah state berubah atau tidak
 */
void buyFood(FoodQueue *DQ, LStatMakanan lMakanan, State *currState, AksiLokasi telepon, boolean *isChangeStack);

/**
 * @brief Prosedur Undo, Mengubah currState menjadi state satu action sebelumnya
 * @param currState: State saat ini
 * @param stackUndo: Stack of State Undo
 * @param stackRedo: Stack of State Redo
 * @param salinanState: Salinan state sebelum aksi
 */
void undo(State *currState, Stack *stackUndo, Stack *stackRedo, State salinanState);

/**
 * @brief Prosedur Redo, Mengubah currState menjadi state satu action setelahnya
 * @param currState: State saat ini
 * @param stackUndo: Stack of State Undo
 * @param stackRedo: Stack of State Redo
 * @param salinanState: Salinan state sebelum aksi
 */
void redo(State *currState, Stack *stackUndo, Stack *stackRedo, State salinanState);
/**
 *@brief Prosedur untuk memindahkan simulator
 *@param currState: State Saat ini
 *@param peta
 *@param S : Simulator
 *@param isChangeState: Apakah state berubah atau tidak
 *@param direction : Arah perpindahan
 *@param displacement : Besar perpindahan
 *@param MIX : AksiLokasi mix
 *@param BOIL : AksiLokasi boil
 *@param CHOP : AksiLokasi chop
 *@param FRY : AksiLokasi fry
 *@param TELEPON : AksiLokasi telepon
 * /
 */
void moveS(State *currState, Matriks *peta, Simulator *S, boolean *isChangeState, Teks direction, int displacement, AksiLokasi MIX, AksiLokasi BOIL, AksiLokasi CHOP, AksiLokasi FRY, AksiLokasi TELEPON);

#endif