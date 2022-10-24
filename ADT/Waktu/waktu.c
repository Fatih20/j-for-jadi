#include "waktu.h"

#include <stdio.h>
#include "../boolean.h"

boolean isWaktuValid(int H, int J, int M, int D)
{
    return ((H >= 0) && (J >= 0 && J <= 23) && (M >= 0 && M <= 59) && (D >= 0 && D <= 59));
}

Waktu buatWaktu(int HH, int JJ, int MM, int DD)
{
    Waktu W;

    Hari(W) = HH;
    Jam(W) = JJ;
    Menit(W) = MM;
    Detik(W) = DD;
    return W;
}

void bacaWaktu(Waktu *W)
{
    int H, J, M, D;

    do
    {
        scanf("%d %d %d %d", &H, &J, &M, &D);
        if (!isWaktuValid(H, J, M, D))
        {
            printf("Waktu tidak valid\n");
        }
    } while (!isWaktuValid(H, J, M, D));
    *W = buatWaktu(H, J, M, D);
}

void tulisWaktu(Waktu W)
{
    if (Hari(W) > 0)
    {
        printf("%d hari ", Hari(W));
    }

    if (Jam(W) > 0)
    {
        printf("%d jam ", Jam(W));
    }

    if (Menit(W) > 0)
    {
        printf("%d menit ", Menit(W));
    }

    if (Detik(W) > 0)
    {
        printf("%d detik", Detik(W));
    }

    if ((Hari(W) == 0) && (Jam(W) == 0) && (Menit(W) == 0) && (Detik(W) == 0))
    {
        printf("%d detik", Detik(W));
    }

    printf("\n");
}

long waktuToDetik(Waktu W)
{
    return (86400 * Hari(W) + 3600 * Jam(W) + 60 * Menit(W) + Detik(W));
}

Waktu detikToWaktu(long N)
{
    Waktu W;

    Hari(W) = N / 86400;
    N %= 86400;
    Jam(W) = N / 3600;
    N %= 3600;
    Menit(W) = N / 60;
    Detik(W) = N % 60;
    return W;
}

boolean WEQ(Waktu W1, Waktu W2)
{
    return (waktuToDetik(W1) == waktuToDetik(W2));
}

boolean WNEQ(Waktu W1, Waktu W2)
{
    return (waktuToDetik(W1) != waktuToDetik(W2));
}

boolean WLT(Waktu W1, Waktu W2)
{
    return (waktuToDetik(W1) < waktuToDetik(W2));
}

boolean WGT(Waktu W1, Waktu W2)
{
    return (waktuToDetik(W1) > waktuToDetik(W2));
}

Waktu nextNDetik(Waktu W, int N)
{
    return (detikToWaktu(waktuToDetik(W) + N));
}

Waktu nextDetik(Waktu W)
{
    return (nextNDetik(W, 1));
}

Waktu prevNDetik(Waktu W, int N)
{
    return (nextNDetik(W, -N));
}

Waktu prevDetik(Waktu W)
{
    return (prevNDetik(W, 1));
}

long durasi(Waktu WAw, Waktu WAkh)
{
    long detikAw, detikAkh, durasi;

    detikAkh = waktuToDetik(WAkh);
    detikAw = waktuToDetik(WAw);

    if (detikAkh >= detikAw)
    {
        durasi = detikAkh - detikAw;
    }
    else
    {
        durasi = detikAw - detikAkh;
    }

    return (durasi);
}