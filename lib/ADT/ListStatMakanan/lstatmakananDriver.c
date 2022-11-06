#include "lstatmakanan.h"
#include <stdio.h>

int main()
{
    LStatMakanan daftarMakanan;
    AksiLokasi al;
    buatLStatMakanan(&daftarMakanan);
    readLStatMakanan(&daftarMakanan, "../../../config/tc1/makanan.txt", &al);
    printLStatMakanan(daftarMakanan);
    Teks temp;
    buatTeks("37", &temp);
    printf("Makanan dengan ID 37: ");
    cetakTeks(namaMakanan(getMakananFromID(daftarMakanan, temp)), 'b');
    printf("\n");
}