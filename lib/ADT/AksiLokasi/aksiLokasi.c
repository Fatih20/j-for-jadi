#include <stdio.h>
#include "aksiLokasi.h"

void buatAksiLokasi(AksiLokasi *AL, Teks aksi, int x, int y, int HH, int JJ, int MM, int DD)
{
    aksi(*AL) = aksi;
    POINT lokasi;
    Absis(lokasi) = x;
    Ordinat(lokasi) = y;
    lokasiAL(*AL) = lokasi;
    durasi(*AL) = buatWaktu(HH, JJ, MM, DD);
}

void displayAksiLokasi(AksiLokasi AL)
{
    printf("Aksi   : ");
    cetakTeks(aksi(AL),'n');
    printf("\nLokasi : ");
    TulisPOINT(lokasiAL(AL));
    printf("\nDurasi : ");
    tulisWaktu(durasi(AL));
}

POINT aksiLokasiDiMana(Teks aLT, AksiLokasi aLArray[])
{
    for (int i = 0; i < 5; i++)
    {
        if (teksSama(aLT, aksi(aLArray[i])))
        {
            return lokasiAL(aLArray[i]);
        }
    }
    return lokasiAL(aLArray[0]);
};
