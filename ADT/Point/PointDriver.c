#include <stdio.h>
#include "point.h"

int main()
{
    POINT P1, P2, P3, P4;
    printf("Masukkan Titik 1:\n");
    BacaPOINT(&P1);
    printf("Masukkan Titik 2:\n");
    BacaPOINT(&P2);
    printf("Masukkan Titik 3:\n");
    BacaPOINT(&P3);
    printf("Masukkan Titik 4:\n");
    BacaPOINT(&P4);

    printf("\n");
    TulisPOINT(P1);
    printf("\n");
    TulisPOINT(P2);
    printf("\n");

    printf("EQ dan NEQ\n");
    printf("%d\n", EQ(P1, P2));
    printf("%d\n", NEQ(P1, P2));

    printf("EQ dan NEQ\n");
    printf("%d\n", EQ(P1, P2));
    printf("%d\n", NEQ(P1, P2));
    printf("Is Origin\n");
    printf("%d\n", IsOrigin(P1));
    printf("%d\n", IsOrigin(P2));
    printf("Is OnSbY\n");
    printf("%d\n", IsOnSbY(P1));
    printf("%d\n", IsOnSbY(P2));
    printf("Is OnSbX\n");
    printf("%d\n", IsOnSbX(P1));
    printf("%d\n", IsOnSbX(P2));
    printf("Kuadran\n");
    printf("%d\n", Kuadran(P1));
    printf("%d\n", Kuadran(P2));
    printf("NextX\n");
    TulisPOINT(NextX(P1));
    printf("\n");
    TulisPOINT(NextX(P2));
    printf("\n");
    printf("NextY\n");
    TulisPOINT(NextY(P1));
    printf("\n");
    TulisPOINT(NextY(P2));
    printf("\n");
    printf("Plus Delta\n");
    TulisPOINT(PlusDelta(P1, 1, -1));
    printf("\n");
    TulisPOINT(PlusDelta(P2, 2, 1));
    printf("\n");
    printf("MirrorOf\n");
    TulisPOINT(MirrorOf(P1, true));
    printf("\n");
    TulisPOINT(MirrorOf(P1, false));
    printf("\n");
    printf("Jarak0\n");
    printf("%f\n", Jarak0(P1));
    printf("%f\n", Jarak0(P2));
    printf("Panjang\n");
    printf("%f\n", Panjang(P1, P2));
    printf("%f\n", Panjang(P2, P1));
    printf("Geser\n");
    Geser(&P1, -1, 2);
    Geser(&P2, -1, 3);
    TulisPOINT(P1);
    printf("\n");
    TulisPOINT(P2);
    printf("\n");
    printf("GeserKeSbX\n");
    GeserKeSbX(&P1);
    TulisPOINT(P1);
    printf("\n");
    printf("GeserKeSbY\n");
    GeserKeSbY(&P2);
    TulisPOINT(P2);
    printf("\n");
    printf("Mirror\n");
    Mirror(&P1, false);
    Mirror(&P2, true);
    TulisPOINT(P1);
    printf("\n");
    TulisPOINT(P2);
    printf("\n");

    printf("IsAdjacent\n");
    printf("%d\n", IsAdjacent(P3, P4));
    return 0;
}
