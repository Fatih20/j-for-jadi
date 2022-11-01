#include "output.h"
#include "stdio.h"

void displayCondition(State cState, Matriks peta)
{
    printf("\n===================================================\n");
    printf("\n");
    printf("BNMO di posisi: ");
    TulisPOINT(posisiState(cState));
    printf("\n");
    printf("Waktu: ");
    tulisWaktuDot(waktuState(cState));
    printf("\n");
    displayMatriks(peta);
    printf("\n");
};
