#include <stdio.h>
#include "simulator.h"

void buatSimulator(Simulator *S, Teks userName, int x, int y, FoodQueue inventory)
{
    userNameS(*S) = userName;
    POINT lokasi;
    Absis(lokasi) = x;
    Ordinat(lokasi) = y;
    lokasiS(*S) = lokasi;
    inventoryS(*S) = inventory;
}

void cetakSimulator(Simulator S)
{
    printf("Username :");
    cetakTeks(userNameS(S));
    printf("\nLokasi   :");
    TulisPOINT(lokasiS(S));
    printf("\nInvetory :\n");
    cetakFoodQueue(inventoryS(S));
}