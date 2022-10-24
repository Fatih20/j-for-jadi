#include <stdio.h>
#include <math.h>
#include "point.h"

void CreatePoint(POINT *P, int X, int Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void BacaPOINT(POINT *P)
{
    /* KAMUS LOKAL*/
    int X, Y;
    /* ALGORITMA */
    scanf("%d %d", &X, &Y);
    CreatePoint(P, X, Y);
}

void TulisPOINT(POINT P)
{
    /* KAMUS LOKAL*/
    int X, Y;
    /* ALGORITMA*/
    X = Absis(P);
    Y = Ordinat(P);
    printf("(%d,%d)", X, Y);
}

boolean EQ(POINT P1, POINT P2)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    return (Absis(P1) == Absis(P2)) && (Ordinat(P1) == Ordinat(P2));
}

boolean NEQ(POINT P1, POINT P2)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    return !EQ(P1, P2);
}

boolean IsAdjacent(POINT P1, POINT P2)
{
    return (EQ(PlusDelta(P1, -1, -1), P2) || EQ(PlusDelta(P1, 0, -1), P2) || EQ(PlusDelta(P1, 1, -1), P2) || EQ(PlusDelta(P1, -1, 0), P2) || EQ(PlusDelta(P1, 1, 0), P2) || EQ(PlusDelta(P1, -1, 1), P2) || EQ(PlusDelta(P1, 0, 1), P2) || EQ(PlusDelta(P1, 1, 1), P2));
}

boolean IsOrigin(POINT P)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    return (Absis(P) == 0 && Ordinat(P) == 0);
}

boolean IsOnSbX(POINT P)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    return (Ordinat(P) == 0);
}

boolean IsOnSbY(POINT P)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    return (Absis(P) == 0);
}

int Kuadran(POINT P)
{
    /*KAMUS LOKAL*/
    int X, Y;
    /*ALGORITMA*/
    X = Absis(P);
    Y = Ordinat(P);
    if (X > 0 && Y > 0)
    {
        return 1;
    }
    else if (X < 0 && Y > 0)
    {
        return 2;
    }
    else if (X < 0 && Y < 0)
    {
        return 3;
    }
    else if (X > 0 && Y < 0)
    {
        return 4;
    }
}

POINT NextX(POINT P)
{
    /*KAMUS LOKAL*/
    POINT PC;
    /*ALGORITMA*/
    Absis(PC) = Absis(P) + 1;
    Ordinat(PC) = Ordinat(P);
    return PC;
}

POINT NextY(POINT P)
{
    /*KAMUS LOKAL*/
    POINT PC;
    /*ALGORITMA*/
    Absis(PC) = Absis(P);
    Ordinat(PC) = Ordinat(P) + 1;
    return PC;
}

POINT PlusDelta(POINT P, int deltaX, int deltaY)
{
    /*KAMUS LOKAL*/
    POINT PC;
    /*ALGORITMA*/
    Absis(PC) = Absis(P) + deltaX;
    Ordinat(PC) = Ordinat(P) + deltaY;
    return PC;
}

POINT MirrorOf(POINT P, boolean SbX)
{
    /*KAMUS LOKAL*/
    POINT PC;
    /*ALGORITMA*/
    if (SbX)
    {
        /*Absis Tetap Ordinat dicerminkan*/
        Absis(PC) = Absis(P);
        Ordinat(PC) = (-1) * Ordinat(P);
    }
    else
    {
        /*Ordinat Tetap Absis dicerminkan*/
        Absis(PC) = (-1) * Absis(P);
        Ordinat(PC) = Ordinat(P);
    }
    return PC;
}

float Jarak0(POINT P)
{
    /*KAMUS LOKAL*/
    int X, Y;
    /*ALGORITMA*/
    X = Absis(P);
    Y = Ordinat(P);
    return sqrt(pow(X, 2) + pow(Y, 2)); /*Rumus Jarak*/
}

float Panjang(POINT P1, POINT P2)
{
    /*KAMUS LOKAL*/
    int deltaX, deltaY;
    /*ALGORITMA*/
    deltaX = Absis(P1) - Absis(P2);
    deltaY = Ordinat(P1) - Ordinat(P2);
    return sqrt(pow(deltaX, 2) + pow(deltaY, 2)); /*Rumus Jarak*/
}

void Geser(POINT *P, int deltaX, int deltaY)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    Absis(*P) += deltaX;
    Ordinat(*P) += deltaY;
}

void GeserKeSbX(POINT *P)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    Ordinat(*P) = 0;
}

void GeserKeSbY(POINT *P)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    Absis(*P) = 0;
}

void Mirror(POINT *P, boolean SbX)
{
    /*KAMUS LOKAL*/
    /*ALGORITMA*/
    if (SbX)
    {
        /*Absis Tetap Ordinat dicerminkan*/
        Ordinat(*P) *= (-1);
    }
    else
    {
        /*Ordinat Tetap Absis dicerminkan*/
        Absis(*P) *= (-1);
    }
}