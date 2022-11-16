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

int nElmtFS(FoodSet fs)
{
    int i = 0;
    int count = 0;
    while (i < capacityFS)
    {
        count += ElmtFS(fs, i);
        i++;
    }
    return count;
};

FoodSet unionFoodSet(FoodSet fsa, FoodSet fsb)
{
    FoodSet fsu;
    Teks namaB;
    Teks unionT;
    buatTeks(" Union ", &unionT);
    gabungkanTeks(NameFS(fsa), unionT, &namaB);
    gabungkanTeks(namaB, NameFS(fsb), &namaB);
    Teks idB;
    buatTeks("0", &idB);
    buatFSKosong(&fsu, namaB, idB);
    for (int i = 0; i < capacityFS; i++)
    {
        int aNum = ElmtFS(fsa, i);
        int bNum = ElmtFS(fsb, i);
        ElmtFS(fsu, i) = aNum > bNum ? aNum : bNum;
    }
    return fsu;
};

FoodSet intersectionFoodSet(FoodSet fsa, FoodSet fsb)
{
    FoodSet fsu;
    Teks namaB;
    Teks unionT;
    buatTeks(" Intersect ", &unionT);
    gabungkanTeks(NameFS(fsa), unionT, &namaB);
    gabungkanTeks(namaB, NameFS(fsb), &namaB);
    Teks idB;
    buatTeks("0", &idB);
    buatFSKosong(&fsu, namaB, idB);
    for (int i = 0; i < capacityFS; i++)
    {
        int aNum = ElmtFS(fsa, i);
        int bNum = ElmtFS(fsb, i);
        ElmtFS(fsu, i) = aNum < bNum ? aNum : bNum;
    }
    return fsu;
};

FoodSet differenceFoodSet(FoodSet fsa, FoodSet fsb)
{
    FoodSet fsu;
    Teks namaB;
    Teks unionT;
    buatTeks(" Difference ", &unionT);
    gabungkanTeks(NameFS(fsa), unionT, &namaB);
    gabungkanTeks(namaB, NameFS(fsb), &namaB);
    Teks idB;
    buatTeks("0", &idB);
    buatFSKosong(&fsu, namaB, idB);
    for (int i = 0; i < capacityFS; i++)
    {
        int difference = ElmtFS(fsa, i) - ElmtFS(fsb, i);
        ElmtFS(fsu, i) = difference > 0 ? difference : 0;
    }
    return fsu;
};

FoodSet addFoodSet(FoodSet fsa, FoodSet fsb)
{
    FoodSet fsu;
    Teks namaB;
    Teks unionT;
    buatTeks(" _ ", &unionT);
    gabungkanTeks(NameFS(fsa), unionT, &namaB);
    gabungkanTeks(namaB, NameFS(fsb), &namaB);
    Teks idB;
    buatTeks("0", &idB);
    buatFSKosong(&fsu, namaB, idB);
    for (int i = 0; i < capacityFS; i++)
    {
        ElmtFS(fsu, i) = ElmtFS(fsa, i) + ElmtFS(fsb, i);
    }
    return fsu;
};

boolean isSubsetfs(FoodSet fsa, FoodSet fsb)
{
    int i = 0;
    boolean foundNot = false;
    while (!foundNot && i < capacityFS)
    {
        foundNot = ElmtFS(fsa, i) > ElmtFS(fsb, i);
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

int incrementIFS(FoodSet *fs, int i, int inc)
{
    ElmtFS(*fs, i) += inc;
};
int incrementFS(FoodSet *fs, int i)
{
    incrementIFS(fs, i, 1);
};
