#include "lstatmakanan.h"
#include <stdio.h>

int main()
{
    LStatMakanan daftarMakanan;
    buatLStatMakanan(&daftarMakanan);
    readLStatMakanan(&daftarMakanan, "../../config/makanancfg.txt");
    printLStatMakanan(daftarMakanan);
    Teks temp;
    buatTeks("37", &temp);
    printf("Makanan dengan ID 37: ");
    cetakTeks(getNameFromID(daftarMakanan, temp));
    printf("\n");
}