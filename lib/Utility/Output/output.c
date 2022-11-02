#include "output.h"
#include <stdio.h>

void displayCondition(State cState, Matriks peta, boolean justUndo, Stack *undoStack)
{
    printf("\n===================================================\n");
    printf("\n");
    printf("BNMO di posisi: ");
    TulisPOINT(posisiState(cState));
    printf("\n");
    printf("Waktu: ");
    tulisWaktuDot(waktuState(cState));
    printf("\n");
    if (IsEmptyStack(*undoStack))
    {
        printf("Notifikasi : -\n");
    }
    else
    {
        if (justUndo)
        {
            printLDinNotif(backNS(notifS(InfoTop(*undoStack))));
        }
        else
        {
            printLDinNotif(forNS(notifS(InfoTop(*undoStack))));
        }
    }
    displayMatriks(peta);
    printf("\n");
};
