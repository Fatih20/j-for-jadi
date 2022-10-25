#include <stdio.h>
#include "state.h"

void buatState(State *S, int x, int y, int waktu, FoodQueue inventory)
{
    FoodQueue inventoryBaru;
    copyFoodQueue(inventory, &inventoryBaru);
    inventoryState(*S) = inventoryBaru;
    POINT posisi;
    Absis(posisi) = x;
    Ordinat(posisi) = y;
    posisiState(*S) = posisi;
    waktuState(*S) = detikToWaktu(waktu);
}

void cetakState(State S)
{
    printf("State saat ini:\n");
    printf("Posisi: ");
    TulisPOINT(posisiState(S));
    printf("\nWaktu : ");
    tulisWaktu(waktuState(S));
    printf("\nInventory:\n");
    cetakFoodQueue(inventoryState(S));
    printf("\n");
}