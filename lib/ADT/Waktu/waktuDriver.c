#include "waktu.h"
#include "../boolean.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Waktu w1, w2, w3, w4, w5, w6, w7, w8, w9, w10, w11, w12, w13, w14, w15, w16, w17, w18, w19, w20, w21;
    long d1, d2;

    if (isWaktuValid(5, 17, 46, 20))
    {
        printf("Waktu valid\n");
    }

    if (isWaktuValid(10, 25, -1, 28))
    {
        printf("waktu valid\n");
    }
    else
    {
        printf("Waktu tidak valid\n");
    }

    w1 = buatWaktu(5, 16, 38, 6);
    tulisWaktu(w1);
    printf("\n");

    bacaWaktu(&w2);
    tulisWaktu(w2);
    printf("\n");

    d1 = waktuToDetik(w1);
    printf("Waktu w1 dalam detik=%d\n", d1);

    w3 = detikToWaktu(waktuToDetik(w1));
    if (WEQ(w1, w3))
    {
        printf("Waktu w1 dan w3 sama\n");
    }

    w4 = buatWaktu(3, 47, 19, 51);
    if (WNEQ(w1, w4))
    {
        printf("Waktu w1 dan w4 tidak sama\n");
    }

    if (WGT(w1, w4))
    {
        printf("Waktu w1 > w4\n");
    }

    if (WLT(w4, w1))
    {
        printf("Waktu w4 < w1\n");
    }

    w6 = nextNDetik(w1, 48);
    tulisWaktu(w6);
    printf("\n");

    w7 = nextDetik(w1);
    tulisWaktu(w7);
    printf("\n");

    w8 = prevNDetik(w1, 3700);
    tulisWaktu(w8);
    printf("\n");

    w9 = prevDetik(w1);
    tulisWaktu(w9);
    printf("\n");

    w10 = nextNMenit(w1, 30);
    tulisWaktu(w10);
    printf("\n");

    w11 = nextMenit(w1);
    tulisWaktu(w11);
    printf("\n");

    w12 = prevNMenit(w1, 652);
    tulisWaktu(w12);
    printf("\n");

    w13 = prevMenit(w1);
    tulisWaktu(w13);
    printf("\n");

    w14 = nextNJam(w1, 57);
    tulisWaktu(w14);
    printf("\n");

    w15 = nextJam(w1);
    tulisWaktu(w15);
    printf("\n");

    w16 = prevNJam(w1, 34);
    tulisWaktu(w16);
    printf("\n");

    w17 = prevJam(w1);
    tulisWaktu(w17);
    printf("\n");

    w18 = nextNHari(w1, 5);
    tulisWaktu(w18);
    printf("\n");

    w19 = nextHari(w1);
    tulisWaktu(w19);
    printf("\n");

    w20 = prevNHari(w1, 2);
    tulisWaktu(w20);
    printf("\n");

    w21 = prevHari(w1);
    tulisWaktu(w21);
    printf("\n");

    d2 = durasi(w2, w1);
    printf("w1-w2=%d", d2);

    return 0;
}