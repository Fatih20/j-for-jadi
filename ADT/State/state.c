#include <stdio.h>
#include "state.h"

void buatState(State *S, POINT posisi, int waktu, FoodQueue inventory)
{
    FoodQueue inventoryBaru;
    copyFoodQueue(inventory, &inventoryBaru);
    inventory(*S) = inventoryBaru;
    posisi(*S) = posisi;
    waktu(*S) = waktu;
}

void cetakState(State S)
{
    printf("State saat ini:\n");
    printf("Posisi: ");
    TulisPOINT(posisi(S));
    printf("\nWaktu : %d", waktu(S));
    printf("\nInventory:\n");
    cetakFoodQueue(inventory(S));
    printf("\n");
}