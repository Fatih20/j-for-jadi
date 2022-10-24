#ifndef STATE_H
#define STATE_H

#include "../boolean.h"
#include "../Point/Point.h"
#include "../FoodQueue/foodQueue.h"

/**
 * @brief Tipedata State
 * @param posisi: ADT Point tempat aksi tersebut dilakukan
 * @param waktu: ADT Waktu di-state tertentu
 * @param inventory: ADT FoodQueue sebagai inventory
 */
typedef struct
{
    POINT posisi;
    int waktu;
    FoodQueue inventory;
} State;

/**
 * @brief Notasi Akses: Selektor AksiLokasi
 */
#define posisi(S) (S).posisi
#define inventory(S) (S).inventory
#define waktu(S) (S).waktu

/**
 * @brief Membuat state baru dengan mengcopy inventory ke inventoryBaru
 * @param posisi: ADT Point tempat aksi tersebut dilakukan
 * @param waktu: ADT Waktu di-state tertentu
 * @param inventory: ADT FoodQueue sebagai inventory
 */
void buatState(State *S, POINT posisi, int waktu, FoodQueue inventory);

/**
 * @brief Menampilkan Tipedata State
 * @param S: Tipedata State yang akan ditampilkan
 */
void cetakState(State S);

#endif