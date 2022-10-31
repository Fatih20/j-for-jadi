#ifndef COMMANDS_H
#define COMMANDS_H
#include "../../ADT/Tree/tree.h"
#include <stdio.h>
#include "../../ADT/State/state.h"
#include "../../ADT/FoodQueue/foodQueue.h"
#include "../../ADT/AksiLokasi/aksiLokasi.h"
#include "../../ADT/Stack/stack.h"

void olahMakanan(Teks command, FoodQueue *inventory, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState);

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
 * @brief Prosedur Undo, Mengubah currState menjadi state satu action sebelumnya
 * @param currState: State saat ini
 * @param stackUndo: Stack of State Undo
 * @param stackRedo: Stack of State Redo
 */
void undo(State *currState, Stack *stackUndo, Stack *stackRedo);

/**
 * @brief Prosedur Redo, Mengubah currState menjadi state satu action setelahnya
 * @param currState: State saat ini
 * @param stackUndo: Stack of State Undo
 * @param stackRedo: Stack of State Redo
 */
void redo(State *currState, Stack *stackUndo, Stack *stackRedo);
#endif