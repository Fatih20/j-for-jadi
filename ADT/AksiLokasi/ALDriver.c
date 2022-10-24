#include "aksiLokasi.h"

int main()
{
    AksiLokasi CHOP;
    Teks aksi;
    POINT lokasi;
    int waktu;

    buatTeks("CHOP", &aksi);
    CreatePoint(&lokasi, 2, 5);
    buatAksiLokasi(&CHOP, aksi, lokasi, waktu);
    displayAksiLokasi(CHOP);
    return 0;
}

/**
 * gcc -o main ADT\AksiLokasi\aksiLokasi.c ADT\AksiLokasi\ALDriver.c ADT\Point\Point.c ADT\Teks\teks.c
 * output :
 * Aksi   : CHOP
 * Lokasi : (2,5)
 * Waktu  : 0
 */