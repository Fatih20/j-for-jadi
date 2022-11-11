#include "foodSet.h"
#include <stdio.h>

void buatIdLFSKosong(FoodSet *fs, Teks nama)
{
    Teks id;
    buatTeks("0", &id);
    buatFSKosong(fs, nama, id);
};

void buatFSKosong(FoodSet *FS, Teks nama, Teks idTipe)
{
    NameFS(*FS) = nama;
    IdFS(*FS) = teksToInt(idTipe);
    for (int i = 0; i < capacityFS; i++)
    {
        ElmtFS(*FS, i) = false;
    }
};

FoodSet unionFoodSet(FoodSet FSa, FoodSet FSb)
{
    FoodSet fsu;
    Teks namaB;
    Teks unionT;
    buatTeks(" Union ", &unionT);
    gabungkanTeks(NameFS(FSa), unionT, &namaB);
    gabungkanTeks(namaB, NameFS(FSb), &namaB);
    Teks idB;
    buatTeks("0", &idB);
    buatFSKosong(&fsu, namaB, idB);
    for (int i = 0; i < capacityFS; i++)
    {
        ElmtFS(fsu, i) = ElmtFS(FSa, i) || ElmtFS(FSb, i);
    }
    return fsu;
};

FoodSet intersectionFoodSet(FoodSet FSa, FoodSet FSb)
{
    FoodSet fsu;
    Teks namaB;
    Teks unionT;
    buatTeks(" Intersect ", &unionT);
    gabungkanTeks(NameFS(FSa), unionT, &namaB);
    gabungkanTeks(namaB, NameFS(FSb), &namaB);
    Teks idB;
    buatTeks("0", &idB);
    buatFSKosong(&fsu, namaB, idB);
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
    cetakTeks(NameFS(FS), 'e');
    printf("\n");
    printf("%03d\n", IdFS(FS));
    for (int i = 0; i < capacityFS; i++)
    {
        printf("%03d -> %d\n", i, ElmtFS(FS, i));
    }
};
