#include <stdio.h>
#include "state.h"

void buatState(State *S, int x, int y, int HH, int JJ, int MM, int DD, FoodQueue inventory)
{
    FoodQueue inventoryBaru;
    copyFoodQueue(inventory, &inventoryBaru);
    inventoryState(*S) = inventoryBaru;
    POINT posisi;
    Absis(posisi) = x;
    Ordinat(posisi) = y;
    posisiState(*S) = posisi;
    waktuState(*S) = buatWaktu(HH, JJ, MM, DD);
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