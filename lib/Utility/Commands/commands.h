#ifndef COMMANDS_H
#define COMMANDS_H
#include "../../ADT/Tree/tree.h"
#include <stdio.h>
#include "../../ADT/FoodQueue/foodQueue.h"
#include "../../ADT/AksiLokasi/aksiLokasi.h"
#include "../../ADT/Stack/stack.h"
#include "../../ADT/Matriks/matriks.h"
#include "../../ADT/Simulator/simulator.h"
#include "../../ADT/MBInput/mBInput.h"

/**
 * @brief prosedur untuk melakukan pengolahan makanan. Mencatat yang terjadi ke notifS
 *
 * @param command command yang hendak dilakukan (FRY, MIX, BOIL, atau CHOP)
 * @param daftarResep daftar resep yang ada
 * @param daftarMakanan daftar makanan yang ada
 * @param currSimulator current simulator
 * @param isChangeSimulator boolean untuk menyimpan apakah terjadi perubahan simulator atau tidak
 * @param notifS
 *
 */
void olahMakanan(Teks command, ListNode *daftarResep, Simulator *currSimulator, boolean *isChangeSimulator, NotifState *notifS);

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
 * @brief Fungsi yang meng-handle pembelian makanan. Panggil ketika command BUY dimasukkan. Menyimpan record hal yang terjadi ke notifState.
 *
 * @param DQ
 * @param daftarMakanan
 * @param currState
 * @param Telepon aksiLokasi telepon
 * @param isChangeSimulator Apakah simulator berubah atau tidak
 * @param notifState
 *
 */
void buyFood(LStatMakanan lMakanan, Simulator *currSimulator, AksiLokasi telepon, boolean *isChangeSimulator, NotifState *notifS);

/**
 * @brief Prosedur Undo, Mengubah currSimulator menjadi simulator satu action sebelumnya
 * @param currSimulator: Simulator saat ini
 * @param stackUndo: Stack of Simulator Undo
 * @param stackRedo: Stack of Simulator Redo
 * @param salinanSimulator: Salinan simulator sebelum aksi
 * @param peta
 */
void undo(Simulator *currSimulator, Stack *stackUndo, Stack *stackRedo, Simulator salinanSimulator, Matriks *peta);

/**
 * @brief Prosedur Redo, Mengubah currSimulator menjadi simulator satu action setelahnya
 * @param currSimulator: Simulator saat ini
 * @param stackUndo: Stack of Simulator Undo
 * @param stackRedo: Stack of Simulator Redo
 * @param salinanSimulator: Salinan simulator sebelum aksi
 * @param peta
 */
void redo(Simulator *currSimulator, Stack *stackUndo, Stack *stackRedo, Simulator salinanSimulator, Matriks *peta);
/**
 *@brief Prosedur untuk memindahkan simulator
 *@param currSimulator: Simulator Saat ini
 *@param peta
 *@param isChangeSimulator: Apakah simulator berubah atau tidak
 *@param direction : Arah perpindahan
 *@param displacement : Besar perpindahan
 *@param MIX : AksiLokasi mix
 *@param BOIL : AksiLokasi boil
 *@param CHOP : AksiLokasi chop
 *@param FRY : AksiLokasi fry
 *@param TELEPON : AksiLokasi telepon
 * /
 */
void moveS(Simulator *currSimulator, Matriks *peta, boolean *isChangeState, Teks direction, int displacement, AksiLokasi MIX, AksiLokasi BOIL, AksiLokasi CHOP, AksiLokasi FRY, AksiLokasi TELEPON, AksiLokasi KULKAS, NotifState *notifS);

/**
 * @brief Fungsi yang meng-handle operasi Kulkas. Panggil ketika command KULKAS dimasukkan. Menyimpan record hal yang terjadi ke notifState.
 *
 * @param kulkas
 * @param currSimulator
 * @param isChangeSimulator
 * @param notifS
 */
void openKulkas(Simulator *currSimulator, boolean *isChangeSimulator, NotifState *notifS);

#endif