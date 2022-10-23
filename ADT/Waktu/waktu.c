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
    if ((Hari(W) > 0) && (Jam(W) > 0) && (Menit(W) > 0) && (Detik(W) > 0))
    {
        printf("%d hari %d jam %d menit %d detik", Hari(W), Jam(W), Menit(W), Detik(W));
    }
    else if ((Hari(W) > 0) && (Jam(W) > 0) && (Menit(W) > 0) && (Detik(W) == 0))
    {
        printf("%d hari %d jam %d menit", Hari(W), Jam(W), Menit(W));
    }
    else if ((Hari(W) > 0) && (Jam(W) > 0) && (Menit(W) == 0) && (Detik(W) > 0))
    {
        printf("%d hari %d jam %d detik", Hari(W), Jam(W), Detik(W));
    }
    else if ((Hari(W) > 0) && (Jam(W) == 0) && (Menit(W) > 0) && (Detik(W) > 0))
    {
        printf("%d hari %d menit %d detik", Hari(W), Menit(W), Detik(W));
    }
    else if ((Hari(W) > 0) && (Jam(W) > 0) && (Menit(W) == 0) && (Detik(W) == 0))
    {
        printf("%d hari %d jam", Hari(W), Jam(W));
    }
    else if ((Hari(W) > 0) && (Jam(W) == 0) && (Menit(W) > 0) && (Detik(W) == 0))
    {
        printf("%d hari %d menit", Hari(W), Menit(W));
    }
    else if ((Hari(W) > 0) && (Jam(W) == 0) && (Menit(W) == 0) && (Detik(W) > 0))
    {
        printf("%d hari %d detik", Hari(W), Detik(W));
    }
    else if ((Hari(W) > 0) && (Jam(W) == 0) && (Menit(W) == 0) && (Detik(W) == 0))
    {
        printf("%d hari", Hari(W));
    }
    else if ((Hari(W) == 0) && (Jam(W) > 0) && (Menit(W) > 0) && (Detik(W) > 0))
    {
        printf("%d jam %d menit %d detik", Jam(W), Menit(W), Detik(W));
    }
    else if ((Hari(W) == 0) && (Jam(W) > 0) && (Menit(W) > 0) && (Detik(W) == 0))
    {
        printf("%d jam %d menit", Jam(W), Menit(W));
    }
    else if ((Hari(W) == 0) && (Jam(W) > 0) && (Menit(W) == 0) && (Detik(W) > 0))
    {
        printf("%d jam %d detik", Jam(W), Detik(W));
    }
    else if ((Hari(W) == 0) && (Jam(W) > 0) && (Menit(W) == 0) && (Detik(W) == 0))
    {
        printf("%d jam", Jam(W));
    }
    else if ((Hari(W) == 0) && (Jam(W) == 0) && (Menit(W) > 0) && (Detik(W) > 0))
    {
        printf("%d menit %d detik", Menit(W), Detik(W));
    }
    else if ((Hari(W) == 0) && (Jam(W) == 0) && (Menit(W) > 0) && (Detik(W) == 0))
    {
        printf("%d menit", Menit(W));
    }
    else if ((Hari(W) == 0) && (Jam(W) == 0) && (Menit(W) == 0) && (Detik(W) >= 0))
    {
        printf("%d detik", Detik(W));
    }
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

Waktu nextDetik(Waktu W)
{
    return (detikToWaktu(waktuToDetik(W) + 1));
}

Waktu nextNDetik(Waktu W, int N)
{
    return (detikToWaktu(waktuToDetik(W) + N));
}

Waktu prevDetik(Waktu W)
{
    long detik;

    detik = waktuToDetik(W);
    detik -= 1;
    return (detikToWaktu(detik));
}

Waktu prevNDetik(Waktu W, int N)
{
    long detik;

    detik = waktuToDetik(W);
    detik -= N;
    return (detikToWaktu(detik));
}

long durasi(Waktu WAw, Waktu WAkh)
{
    long detikAw, detikAkh, durasi;

    detikAkh = waktuToDetik(WAkh);
    detikAw = waktuToDetik(WAw);
    durasi = detikAkh - detikAw;

    return durasi;
}