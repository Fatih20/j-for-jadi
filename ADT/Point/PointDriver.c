#include <stdio.h>
#include "point.h"

int main()
{
    Point p1, p2;
    CreatePoint(&p1, 1, 2);
    CreatePoint(&p2, 10, 11);

    printf("p1: (%d,%d)\n", Absis(p1), Ordinat(p1));
    printf("p2: (%d,%d)\n", Absis(p2), Ordinat(p2));

    moveEast(&p1);
    moveNorth(&p2);
    printf("p1: (%d,%d)\n", Absis(p1), Ordinat(p1));
    printf("p2: (%d,%d)\n", Absis(p2), Ordinat(p2));

    moveWest(&p1);
    moveSouth(&p2);
    printf("p1: (%d,%d)\n", Absis(p1), Ordinat(p1));
    printf("p2: (%d,%d)\n", Absis(p2), Ordinat(p2));
    return 0;
}