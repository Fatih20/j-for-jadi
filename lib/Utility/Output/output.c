#include "output.h"
#include <stdio.h>

void displayCondition(Simulator cSimulator, Matriks peta, boolean justUndo, Stack *undoStack, boolean showNotification)
{
    printSCyan("\n============================================================\n\n");
    printf("\n");
    cetakTeks(userNameSimulator(cSimulator), 'n');
    printf(" di posisi: ");
    TulisPOINT(posisiSimulator(cSimulator));
    printf("\n");
    printf("Waktu: ");
    tulisWaktuDot(waktuSimulator(cSimulator));
    printf("\n");
    if (IsEmptyStack(*undoStack) || !showNotification)
    {
        printf("Notifikasi: -\n");
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
    printf("\n");
    displayMatriks(peta);
    printf("\n");
};
