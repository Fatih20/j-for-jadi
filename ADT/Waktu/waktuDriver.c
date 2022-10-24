#include "waktu.h"
#include "../boolean.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Waktu w1, w2, w3, w4, w5, w6, w7;
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

    bacaWaktu(&w2);
    tulisWaktu(w2);

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

    w7 = nextNDetik(w1, -90);
    tulisWaktu(w7);

    d2 = durasi(w2, w1);
    printf("w1-w2=%d", d2);

    return 0;
}