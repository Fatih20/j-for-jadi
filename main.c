#include <stdio.h>
#include <stdlib.h>
#include "lib/ADT/MKInput/mKInput.h"
#include "lib/ADT/MBInput/mBInput.h"
#include "lib/ADT/FoodQueue/foodQueue.h"
#include "lib/Utility/Loader/Loader.h"
#include "lib/Utility/String/String.h"
#include "lib/Utility/Commands/commands.h"
#include "lib/Utility/String/String.h"
#include "lib/Utility/Output/output.h"

int main(int argc, char const *argv[])
{

    /* Splash screen */
    /* Convert gambar ke txt, baca per baris, diprint ke layar */
    int i;
    char baris[200];
    FILE *fpointer = fopen("robot.txt", "r");

    for (i = 0; i < 19; i++)
    {
        fgets(baris, 200, fpointer);
        printSBlue(baris);
    }
    printSCyan("\n\n                         Hai! Aku BNMO                      \n\n");
    printSCyan("============================================================\n");
    printSYellow("          SELAMAT DATANG DI PROGRAM SIMULASI MASAK         \n");
    printSCyan("============================================================\n");
    printf("\n");
    printf("Berikut adalah cara menjalankan program simulasi ini\n");
    printf("1. Ketik ");
    printSGreen("START");
    printf(" dan tekan enter untuk mulai menjalankan program simulasi\n");
    printf("2. Ketik ");
    printSRed("EXIT");
    printf(" dan tekan enter mengakhiri program simulasi\n");
    printf("\n");

    /* Struktur main */
    Teks startTeks;
    Teks exitTeks;

    buatTeks("START", &startTeks);
    buatTeks("EXIT", &exitTeks);

    boolean exitFirstLoop = false;
    boolean entering = false;
    boolean exiting = true;
    Teks start;
    buatTeks("START", &start);
    Teks exit;
    buatTeks("EXIT", &exit);

    do
    {
        printf("Masukkan command (");
        printSGreen("START");
        printf(" atau ");
        printSRed("EXIT");
        printf("): ");
        startMBInput();
        if (panjangLDinTeks(currentRowI) != 1)
        {
            exitFirstLoop = false;
        }
        else
        {
            Teks iInput = elmtLDT(currentRowI, 0);
            entering = teksSamaCI(iInput, start);
            exiting = teksSamaCI(iInput, exit);
            exitFirstLoop = entering || exiting;
        }
        if (!exitFirstLoop)
        {
            printf("Command yang dimasukkan salah\n");
        }
    } while (!exitFirstLoop);

    Matriks peta;
    LStatMakanan lSMakanan;
    ListNode lResep;
    POINT lokasiSimulator;
    Teks userName;
    AksiLokasi MIX;
    AksiLokasi BOIL;
    AksiLokasi CHOP;
    AksiLokasi FRY;
    AksiLokasi TELEPON;
    FoodQueue inventoryQ;
    FoodQueue deliveryQ;
    Simulator currSimulator;
    Simulator salinanSimulator;
    Kulkas kulkas;
    Stack stackUndo, stackRedo;
    // Inisialisasi
    CreateEmptyStack(&stackUndo, 10);
    CreateEmptyStack(&stackRedo, 10);
    buatKulkas(&kulkas);
    boolean isCommandValid = true;
    boolean isChangeSimulator = true;
    boolean isUndoRedo = false;

    if (entering)
    {
        // Load config
        printf("\nMasukkan lokasi folder config relatif terhadap root folder: ");
        startMBInput();
        Teks inputFolder = elmtLDT(currentRowI, 0);
        Teks fulan;
        buatTeks("Fulan", &fulan);
        loader(&peta, &lSMakanan, &lResep, &lokasiSimulator, &MIX, &BOIL, &CHOP, &FRY, &TELEPON, inputFolder);
        buatFQKosong(&inventoryQ, 20);
        buatFQKosong(&deliveryQ, 20);
        buatSimulator(&currSimulator, fulan, Absis(lokasiSimulator), Ordinat(lokasiSimulator), 0, 0, 0, 0, inventoryQ, deliveryQ, kulkas);
        Simulator initialSimulator;
        copySimulator(currSimulator, &initialSimulator);
        Absis(posisiSimulator(initialSimulator)) = -1;
        Ordinat(posisiSimulator(initialSimulator)) = -1;
        Push(&stackUndo, initialSimulator);
        // Load username
        boolean unameFilled = false;
        do
        {
            printf("\nUsername (without space): ");
            startMBInput();
            int panjangU = panjangLDinTeks(currentRowI);
            unameFilled = panjangU == 1;
            if (!unameFilled)
            {
                if (panjangU > 1)
                {

                    printf("Username tidak boleh mengandung spasi!\n");
                }
                else
                {
                    printf("Username tidak boleh kosong!\n");
                }
            }
            else
            {
                userName = elmtLDT(currentRowI, 0);
                userNameSimulator(currSimulator) = userName;
            }
        } while (!unameFilled);

        printSCyan("============================================================\n\n");
        printSYellow("                          HI,  ");
        cetakTeks(elmtLDT(currentRowI, 0), 'y');
        printf("                 \n");
    }
    Teks fryT;
    buatTeks("FRY", &fryT);
    Teks chopT;
    buatTeks("CHOP", &chopT);
    Teks boilT;
    buatTeks("BOIL", &boilT);
    Teks mixT;
    buatTeks("MIX", &mixT);
    Teks cookBT;
    buatTeks("COOKBOOK", &cookBT);
    Teks ctlgT;
    buatTeks("CATALOG", &ctlgT);
    Teks buyT;
    buatTeks("BUY", &buyT);
    Teks moveT;
    buatTeks("MOVE", &moveT);
    Teks northT;
    buatTeks("NORTH", &northT);
    Teks southT;
    buatTeks("SOUTH", &southT);
    Teks eastT;
    buatTeks("EAST", &eastT);
    Teks westT;
    buatTeks("WEST", &westT);
    Teks undoT;
    buatTeks("UNDO", &undoT);
    Teks redoT;
    buatTeks("REDO", &redoT);
    Teks waitT;
    buatTeks("WAIT", &waitT);
    Teks zeroT;
    buatTeks("0", &zeroT);
    Teks inventoryT;
    buatTeks("INVENTORY", &inventoryT);
    Teks deliveryT;
    buatTeks("DELIVERY", &deliveryT);

    boolean justUndo = false;
    while (!exiting)
    {
        displayCondition(currSimulator, peta, justUndo, &stackUndo);
        Teks command;
        NotifState currentNS;
        buatNotifStateR(&currentNS);
        do
        {
            justUndo = false;
            isCommandValid = true;
            printf("Enter command: ");
            startMBInput();
            printf("\n");
            if (panjangLDinTeks(currentRowI) < 1)
            {
                isCommandValid = false;
            }
            else
            {
                command = elmtLDT(currentRowI, 0);
                copySimulator(currSimulator, &salinanSimulator);
            }
            if (panjangLDinTeks(currentRowI) == 1)
            {
                if (teksSamaCI(command, buyT))
                {
                    buyFood(lSMakanan, &currSimulator, TELEPON, &isChangeSimulator, &currentNS);
                    isUndoRedo = false;
                }
                else if (teksSamaCI(command, fryT) || teksSamaCI(command, boilT) || teksSamaCI(command, mixT) || teksSamaCI(command, chopT))
                {
                    olahMakanan(command, &lResep, &currSimulator, &isChangeSimulator, &currentNS);
                    isUndoRedo = false;
                }
                else if (teksSamaCI(command, cookBT))
                {
                    displayCookbook(&lResep);
                    isUndoRedo = false;
                    isChangeSimulator = false;
                }
                else if (teksSamaCI(command, ctlgT))
                {
                    displayCatalog(&lSMakanan);
                    isUndoRedo = false;
                    isChangeSimulator = false;
                }
                else if (teksSamaCI(command, undoT))
                {
                    isUndoRedo = true;
                    justUndo = true;
                    undo(&currSimulator, &stackUndo, &stackRedo, salinanSimulator, &peta);
                }
                else if (teksSamaCI(command, redoT))
                {
                    isUndoRedo = true;
                    redo(&currSimulator, &stackUndo, &stackRedo, salinanSimulator, &peta);
                }
                else if (teksSamaCI(command, inventoryT))
                {
                    displayInventory(inventorySimulator(currSimulator));
                    isChangeSimulator = false;
                }
                else if (teksSamaCI(command, deliveryT))
                {
                    displayDelivery(deliverySimulator(currSimulator));
                    isChangeSimulator = false;
                }
                else if (teksSamaCI(command, exitTeks))
                {
                    isChangeSimulator = false;
                    exiting = true;
                }
                else
                {
                    isCommandValid = false;
                }
            }
            else if (panjangLDinTeks(currentRowI) == 2)
            {
                if (teksSamaCI(command, moveT))
                {
                    Teks direction = elmtLDT(currentRowI, 1);
                    if (teksSamaCI(direction, southT) || teksSamaCI(direction, northT) || teksSamaCI(direction, westT) || teksSamaCI(direction, eastT))
                    {
                        moveS(&currSimulator, &peta, &isChangeSimulator, direction, 1, MIX, BOIL, CHOP, FRY, TELEPON, &currentNS);
                        isUndoRedo = false;
                    }
                    else
                    {
                        isCommandValid = false;
                    }
                }
                else
                {
                    isCommandValid = false;
                }
            }
            else if (panjangLDinTeks(currentRowI) == 3)
            {
                if (teksSamaCI(command, waitT))
                {
                    int JJ, MM;
                    Waktu time;
                    Teks x = elmtLDT(currentRowI, 1);
                    Teks y = elmtLDT(currentRowI, 2);
                    isCommandValid = isTeksInt(x) && isTeksInt(y);
                    if (isCommandValid)
                    {
                        JJ = teksToInt(x);
                        MM = teksToInt(y);
                        time = buatWaktu(0, JJ, MM, 0);
                        majukanWaktuSimulator(&currSimulator, time, &currentNS);
                        isChangeSimulator = true;
                    }
                }
                else
                {
                    isCommandValid = false;
                }
            }
            else
            {
                isCommandValid = false;
            }
            if (!isCommandValid)
            {
                printSRed("\nCommand tidak dikenali!\n");
            }
            else
            {
                // Push stack undo dan delete all stack redo jika terjadi perubahan state dan bukan undo redo
                if (isChangeSimulator && !isUndoRedo)
                {
                    if (!IsEmptyStack(stackRedo))
                    {
                        dealocateStack(&stackRedo);
                        CreateEmptyStack(&stackRedo, 5);
                    }
                    if (IsFullStack(stackUndo))
                    {
                        expandStack(&stackUndo, 10);
                    }
                    backNS(notifSimulator(InfoTop(stackUndo))) = backNS(currentNS);
                    forNS(notifSimulator(salinanSimulator)) = forNS(currentNS);
                    Push(&stackUndo, salinanSimulator);
                }
            }
        } while (!isCommandValid);
    }
    printSCyan("\n============================================================\n");
    printSGreen("      Terima kasih telah memasak bersama BNMO ");
    printSRed("<3 <3 <3     \n");
    printSCyan("============================================================\n");
    return 0;
}