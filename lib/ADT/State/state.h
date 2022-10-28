#ifndef STATE_H
#define STATE_H

#include "../boolean.h"
#include "../Point/Point.h"
#include "../FoodQueue/foodQueue.h"

/**
 * @brief Tipedata State
 * @param posisi: ADT Point tempat aksi tersebut dilakukan
 * @param waktu: ADT Waktu penunjuk waktu sebuah state
 * @param inventory: ADT FoodQueue sebagai inventory
 */
typedef struct
{
    POINT posisi;
    Waktu waktu;
    FoodQueue inventory;
} State;

/**
 * @brief Notasi Akses: Selektor AksiLokasi
 */
#define posisiState(S) (S).posisi
#define waktuState(S) (S).waktu
#define inventoryState(S) (S).inventory

/**
 * @brief Membuat state baru dengan mengcopy inventory ke inventoryBaru
 * @param x : absis posisi
 * @param y : ordinat posisi
 * @param HH : hari dari waktu state
 * @param JJ : jam dari waktu state
 * @param MM : menit dari waktu state
 * @param DD : detik dari waktu state
 * @param inventory: ADT FoodQueue sebagai inventory
 */
void buatState(State *S, int x, int y, int HH, int JJ, int MM, int DD, FoodQueue inventory);

/**
 * @brief Menampilkan Tipedata State
 * @param S: Tipedata State yang akan ditampilkan
 */
void cetakState(State S);

#endif