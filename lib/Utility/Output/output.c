#include "output.h"
#include <stdio.h>

void displayCondition(Simulator cSimulator, Matriks peta, boolean justUndo, Stack *undoStack, boolean showNotification)
{
    printSCyan("\n============================================================\n\n");
    printf("\n");
    printf("You're playing as ");
    cetakTeks(userNameSimulator(cSimulator), 'g');
    printf("\n");
    Teks positionT;
    buatTeks("Posisi", &positionT);
    cetakTeks(positionT, 'c');
    printf("\n");
    TulisPOINT(posisiSimulator(cSimulator));
    printf("\n");
    Teks waktuT;
    buatTeks("Waktu", &waktuT);
    cetakTeks(waktuT, 'p');
    printf("\n");
    tulisWaktuDot(waktuSimulator(cSimulator));
    printf("\n");
    if (IsEmptyStack(*undoStack) || !showNotification)
    {
        Teks notifT;
        buatTeks("Notifikasi", &notifT);
        printf("\n-\n");
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
