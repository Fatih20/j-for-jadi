#include "lstatmakanan.h"
#include <stdio.h>

int main()
{
    LStatMakanan daftarMakanan;
    buatLStatMakanan(&daftarMakanan);
    readLStatMakanan(&daftarMakanan);
    printLStatMakanan(daftarMakanan);
}