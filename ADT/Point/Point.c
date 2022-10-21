#include <stdio.h>
#include "point.h"

void CreatePoint(Point *P, int X, int Y)
{
    Absis(*P) = X;
    Ordinat(*P) = Y;
}

void moveWest(Point *P)
{
    Absis(*P)--;
}

void moveNorth(Point *P)
{
    Ordinat(*P)++;
}

void moveEast(Point *P)
{
    Absis(*P)++;
}

void moveSouth(Point *P)
{
    Ordinat(*P)--;
}