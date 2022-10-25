#include <stdio.h>
#include "aksiLokasi.h"

void buatAksiLokasi(AksiLokasi *AL, Teks aksi, int x, int y, int HH, int JJ, int MM, int DD)
{
    aksi(*AL) = aksi;
    POINT lokasi;
    Absis(lokasi) = x;
    Ordinat(lokasi) = y;
    lokasi(*AL) = lokasi;
    durasi(*AL) = buatWaktu(HH, JJ, MM, DD);
}

void displayAksiLokasi(AksiLokasi AL)
{
    printf("Aksi   : ");
    cetakTeks(aksi(AL));
    printf("\nLokasi : ");
    TulisPOINT(lokasi(AL));
    printf("\nDurasi : ");
    tulisWaktu(durasi(AL));
}