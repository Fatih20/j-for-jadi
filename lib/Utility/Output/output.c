#include "output.h"
#include <stdio.h>

void displayCondition(Simulator cSimulator, Matriks peta, boolean justUndo, Stack *undoStack)
{
    printf("\n===================================================\n");
    printf("\n");
    printf("BNMO di posisi: ");
    TulisPOINT(posisiSimulator(cSimulator));
    printf("\n");
    printf("Waktu: ");
    tulisWaktuDot(waktuSimulator(cSimulator));
    printf("\n");
    if (IsEmptyStack(*undoStack))
    {
        printf("Notifikasi : -\n");
    }
    else
    {
        if (justUndo)
        {
            printLDinNotif(backNS(notifSimulator(InfoTop(*undoStack))));
        }
        else
        {
            // printf("Printing notif");
            printLDinNotif(forNS(notifSimulator(InfoTop(*undoStack))));
        }
    }
    displayMatriks(peta);
    printf("\n");
};
