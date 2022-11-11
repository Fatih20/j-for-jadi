#include "foodSet.h"
#include <stdio.h>

void buatFSKosong(FoodSet *FS)
{
    for (int i = 0; i < capacityFS; i++)
    {
        ElmtFS(*FS, i) = false;
    }
};

FoodSet unionFoodSet(FoodSet FSa, FoodSet FSb)
{
    FoodSet fsu;
    buatFSKosong(&fsu);
    for (int i = 0; i < capacityFS; i++)
    {
        ElmtFS(fsu, i) = ElmtFS(FSa, i) || ElmtFS(FSb, i);
    }
    return fsu;
};

FoodSet intersectionFoodSet(FoodSet FSa, FoodSet FSb)
{
    FoodSet fsu;
    buatFSKosong(&fsu);
    for (int i = 0; i < capacityFS; i++)
    {
        ElmtFS(fsu, i) = ElmtFS(FSa, i) && ElmtFS(FSb, i);
    }
    return fsu;
};

boolean isSubsetfs(FoodSet fsa, FoodSet fsb)
{
    int i = 0;
    boolean foundNot = false;
    while (!foundNot && i < capacityFS)
    {
        foundNot = ElmtFS(fsa, i) && !ElmtFS(fsb, i);
        i += !foundNot;
    }
    return !foundNot;
};

void cetakFoodSet(FoodSet FS)
{
    for (int i = 0; i < capacityFS; i++)
    {
        printf("%03d -> %d\n", i, ElmtFS(FS, i));
    }
};
