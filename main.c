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

    for (i = 0; i < 16; i++)
    {
        fgets(baris, 200, fpointer);
        printf("%s", baris);
    }
    printf("\n");
    printf("Hai! Aku BNMO\n");
    printf("Selamat datang di program simulasi masak\n");
    printf("\n");
    printf("Berikut adalah cara menjalankan program simulasi ini\n");
    printf("1. Ketik START dan tekan enter untuk mulai menjalankan program simulasi\n");
    printf("2. Ketik EXIT dan tekan enter mengakhiri program simulasi\n");
    printf("\n");
    printf("mari kita cobaaa\n");
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
        printf("Masukkan command (START atau EXIT) : \n");
        startMBInput();
        if (panjangLDinTeks(currentRowI) != 1)
        {
            exitFirstLoop = false;
        }
        else
        {
            Teks iInput = elmtLDT(currentRowI, 0);
            entering = teksSama(iInput, start);
            exiting = teksSama(iInput, exit);
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
    Simulator BNMO;
    Teks userName;
    AksiLokasi MIX;
    AksiLokasi BOIL;
    AksiLokasi CHOP;
    AksiLokasi FRY;
    AksiLokasi TELEPON;
    FoodQueue inventoryQ;
    FoodQueue deliveryQ;
    State cState;
    State salinanState;
    Stack stackUndo, stackRedo;
    // Inisialisasi
    CreateEmptyStack(&stackUndo, 10);
    CreateEmptyStack(&stackRedo, 10);
    boolean isCommandValid = true;
    boolean isChangeState = true;
    boolean isUndoRedo = false;

    if (entering)
    {
        // Load config
        printf("Masukkan lokasi folder config relatif terhadap root folder :\n");
        startMBInput();
        Teks inputFolder = elmtLDT(currentRowI, 0);
        loader(&peta, &lSMakanan, &lResep, &lokasiSimulator, &MIX, &BOIL, &CHOP, &FRY, &TELEPON, inputFolder);
        buatFQKosong(&inventoryQ, 20);
        buatFQKosong(&deliveryQ, 20);
        buatSimulator(&BNMO, userName, Absis(lokasiSimulator), Ordinat(lokasiSimulator), inventoryQ);
        buatState(&cState, Absis(lokasiSimulator), Ordinat(lokasiSimulator), 0, 0, 0, 0, inventoryQ, deliveryQ);
        // Load username
        boolean unameFilled = false;
        do
        {
            printf("Username (without space) :\n");
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
                userName = elmtLDT(currentRowI, 1);
                userNameS(BNMO) = userName;
            }
        } while (!unameFilled);

        printf("===================================================\n");
        printf("                   BNMO MASAK-MASAK                \n");
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

    boolean justUndo;
    while (!exiting)
    {
        displayCondition(cState, peta);
        Teks command;
        justUndo = false;
        do
        {
            isCommandValid = true;
            printf("Enter command: ");
            startMBInput();
            if (panjangLDinTeks(currentRowI) < 1)
            {
                isCommandValid = false;
            }
            else
            {
                command = elmtLDT(currentRowI, 0);
                copyState(cState, &salinanState);
            }
            if (panjangLDinTeks(currentRowI) == 1)
            {
                if (teksSama(command, buyT))
                {
                    buyFood(lSMakanan, &cState, TELEPON, &isChangeState);
                    isUndoRedo = false;
                }
                else if (teksSama(command, fryT) || teksSama(command, boilT) || teksSama(command, mixT) || teksSama(command, chopT))
                {
                    olahMakanan(command, &inventoryQ, &deliveryQ, &lResep, &lSMakanan, &cState, &isChangeState);
                    isUndoRedo = false;
                }
                else if (teksSama(command, cookBT))
                {
                    displayCookbook(&lResep);
                    isUndoRedo = false;
                    isChangeState = false;
                }
                else if (teksSama(command, ctlgT))
                {
                    displayCatalog(&lSMakanan);
                    isUndoRedo = false;
                    isChangeState = false;
                }
                else if (teksSama(command, undoT))
                {
                    isUndoRedo = true;
                    justUndo = true;
                    undo(&cState, &stackUndo, &stackRedo, salinanState, &peta);
                }
                else if (teksSama(command, redoT))
                {
                    isUndoRedo = true;
                    redo(&cState, &stackUndo, &stackRedo, salinanState, &peta);
                }
                else if (teksSama(command, inventoryT))
                {
                    displayInventory(inventoryState(cState));
                    isChangeState = false;
                }
                else if (teksSama(command, deliveryT))
                {
                    displayDelivery(deliveryState(cState));
                    isChangeState = false;
                }
                else if (teksSama(command, zeroT))
                {
                    isChangeState = false;
                    exiting = true;
                }
                else
                {
                    isCommandValid = false;
                }
            }
            else if (panjangLDinTeks(currentRowI) == 2)
            {
                if (teksSama(command, moveT))
                {
                    Teks direction = elmtLDT(currentRowI, 1);
                    if (teksSama(direction, southT) || teksSama(direction, northT) || teksSama(direction, westT) || teksSama(direction, eastT))
                    {
                        moveS(&cState, &peta, &BNMO, &isChangeState, direction, 1, MIX, BOIL, CHOP, FRY, TELEPON);
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
                if (teksSama(command, waitT))
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
                        majukanWaktuState(&cState, time);
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
                printf("Command tidak dikenali!\n");
            }
            else
            {
                // Push stack undo dan delete all stack redo jika terjadi perubahan state dan bukan undo redo
                if (isChangeState && !isUndoRedo)
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
                    Push(&stackUndo, salinanState);
                }
            }
        } while (!isCommandValid);
    }
    return 0;
}