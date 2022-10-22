#include <stdio.h>
#include "aksiLokasi.h"

AksiLokasi buatAksiLokasi(AksiLokasi *AL, Teks aksi, POINT lokasi, int waktu)
{
    aksi(*AL) = aksi;
    lokasi(*AL) = lokasi;
    waktu(*AL) = waktu;
}

void displayAksiLokasi(AksiLokasi AL)
{
    printf("Aksi   : ");
    cetakTeks(aksi(AL));
    printf("\nLokasi : ");
    TulisPOINT(lokasi(AL));
    printf("\nWaktu  : %d\n", waktu(AL));
}