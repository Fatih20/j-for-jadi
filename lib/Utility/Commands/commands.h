#ifndef COMMANDS_H
#define COMMANDS_H
#include "../../ADT/Tree/tree.h"
#include <stdio.h>
#include "../../ADT/State/state.h"
#include "../../ADT/FoodQueue/foodQueue.h"
#include "../../ADT/AksiLokasi/aksiLokasi.h"
#include "../../ADT/Matriks/matriks.h"
#include "../../ADT/Simulator/simulator.h"

void olahMakanan(Teks command, FoodQueue *inventory, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState);

void displayCookbook(ListNode *daftarResep);

void displayCatalog(LStatMakanan *daftarMakanan);
/**
 * @brief Fungsi yang meng-handle pembelian makanan. Panggil ketika command BUY dimasukkan
 *
 * @param DQ
 * @param daftarMakanan
 * @param currState
 * @param Telepon aksiLokasi telepon
 *
 */
void buyFood(FoodQueue *DQ, LStatMakanan lMakanan, State *currState, AksiLokasi telepon);

/**
 * @brief Prosedur untuk memindahkan simulator
 *
 * @param peta
 * @param S: Simulator
 * @param direction: Arah perpindahan
 * @param MIX: AksiLokasi mix
 * @param BOIL: AksiLokasi boil
 * @param CHOP: AksiLokasi chop
 * @param FRY: AksiLokasi fry
 * @param TELEPON: AksiLokasi telepon
 */
void moveS(State *currState, Matriks *peta, Simulator *S, Teks direction, AksiLokasi MIX, AksiLokasi BOIL, AksiLokasi CHOP, AksiLokasi FRY, AksiLokasi TELEPON);

#endif