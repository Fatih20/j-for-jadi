#include <stdio.h>
#include "simulator.h"

void buatSimulator(Simulator *S, Teks userName, int x, int y, FoodQueue inventory)
{
    userName(*S) = userName;
    POINT lokasi;
    Absis(lokasi) = x;
    Ordinat(lokasi) = y;
    lokasi(*S) = lokasi;
    inventory(*S) = inventory;
}

void cetakSimulator(Simulator S)
{
    printf("Username :");
    cetakTeks(userName(S));
    printf("\nLokasi   :");
    TulisPOINT(lokasi(S));
    printf("\nInvetory :\n");
    cetakFoodQueue(inventory(S));
}