#include "aksiLokasi.h"

int main()
{
    AksiLokasi CHOP;
    Teks aksi;
    POINT lokasi;
    int waktu = 180;
    buatTeks("CHOP", &aksi);
    buatAksiLokasi(&CHOP, aksi, 2, 5, waktu);
    displayAksiLokasi(CHOP);
    return 0;
}

/**
 * gcc -o main ADT\AksiLokasi\aksiLokasi.c ADT\AksiLokasi\ALDriver.c ADT\Point\Point.c ADT\Teks\teks.c ADT\Waktu\waktu.c ADT\ListDinKar\ldinkar.c
 * output :
 * Aksi   : CHOP
 * Lokasi : (2,5)
 * Waktu  : 3 menit
 */