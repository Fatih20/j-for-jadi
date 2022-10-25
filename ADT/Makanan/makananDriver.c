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
    Teks aLT;
    buatTeks("Bruh", &aLT);
    buatAksiLokasi(&aL, aLT, 2, 2, 0, 1, 5, 0);
    buatMakanan(&m1, "bruh", "95", "100", wB, wS, aL);
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
