#include "makanan.h"
#include "../boolean.h"
#include "../AksiLokasi/aksiLokasi.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Makanan m1;
    Waktu wB;
    Waktu wS;
    wB = buatWaktu(0, 0, 20, 0);
    wS = buatWaktu(0, 0, 20, 0);

    AksiLokasi aL;
    Teks namaM1, idTM1, idUM1, aLT1;
    buatTeks("Bruh", &aLT1);
    buatTeks("bruh", &namaM1);
    buatTeks("095", &idTM1);
    buatTeks("100", &idUM1);
    buatAksiLokasi(&aL, aLT1, 2, 2, 0, 1, 5, 0);
    buatMakanan(&m1, namaM1, idTM1, idUM1, wB, wS, aL);
    cetakMakanan(m1);
    printf("\n");
    TulisPOINT(getFInPlace(m1));
    tulisWaktu(getFInTime(m1));
    cetakTeks(getFHow(m1));

    // Makanan m2;
    // buatMakanan(&m2, "bruh", 101, 100, "12", "101");
    // cetakMakanan(m2);

    // printf("%d\n", basiBersamaan(m2, m1));

    return 0;
}
