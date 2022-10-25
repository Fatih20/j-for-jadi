#include <stdio.h>
#include "aksiLokasi.h"

void buatAksiLokasi(AksiLokasi *AL, Teks aksi, int x, int y, int waktu)
{
    aksi(*AL) = aksi;
    POINT lokasi;
    Absis(lokasi) = x;
    Ordinat(lokasi) = y;
    lokasi(*AL) = lokasi;
    waktu(*AL) = detikToWaktu(waktu);
}

void displayAksiLokasi(AksiLokasi AL)
{
    printf("Aksi   : ");
    cetakTeks(aksi(AL));
    printf("\nLokasi : ");
    TulisPOINT(lokasi(AL));
    printf("\nWaktu  : ");
    tulisWaktu(waktu(AL));
}