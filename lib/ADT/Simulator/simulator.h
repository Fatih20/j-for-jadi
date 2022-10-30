#ifndef SIMULATOR_H
#define SIMULATOR_H

#include "../Point/Point.h"
#include "../FoodQueue/foodQueue.h"
#include "../Teks/teks.h"

/**
 * @brief Tipe Data Simulator
 * @param userName: ADT Teks untuk nama pengguna
 * @param lokasi: ADT Point tempat aksi tersebut dilakukan
 * @param inventory: ADT FoodQueue untuk menyimpan makanan yang ada
 */
typedef struct
{
    Teks userName;
    POINT lokasi;
    FoodQueue inventory;
} Simulator;

/**
 * @brief Notasi Akses: Selektor AksiLokasi
 */
#define userNameS(Simulator) (Simulator).userName
#define lokasiS(Simulator) (Simulator).lokasi
#define inventoryS(Simulator) (Simulator).inventory

/**
 * @brief Membentuk Tipedata buatSimulator
 * @param S : ADT Simulator yang akan diisi nilainya dengan parameter selannjutnya
 * @param userName : ADT Teks berisi nama pengguna
 * @param x : Absis lokasi
 * @param y : Ordinat lokasi
 * @param inventory: ADT FoodQueue
 */
void buatSimulator(Simulator *S, Teks userName, int x, int y, FoodQueue inventory);

/**
 * @brief Mencetak tipedata Simulator ke layar
 * @param S : ADT Simulator yang akan dicetak
 */
void cetakSimulator(Simulator S);

#endif