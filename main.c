#include <stdio.h>
#include <stdlib.h>
#include "lib/ADT/MKInput/mKInput.h"
#include "lib/ADT/MBInput/mBInput.h"
#include "lib/ADT/FoodQueue/foodQueue.h"
#include "lib/Utility/Loader/Loader.h"
#include "lib/Utility/String/String.h"
#include "lib/Utility/Commands/commands.h"
#include "lib/Utility/String/String.h"

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
        Teks iInput = elmtLDT(currentRowI, 0);
        entering = teksSama(iInput, start);
        exiting = teksSama(iInput, exit);
        exitFirstLoop = entering || exiting;
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

    if (entering)
    {
        printf("Masukkan lokasi folder config relatif terhadap root folder :\n");
        startMBInput();
        Teks inputFolder = elmtLDT(currentRowI, 0);
        loader(&peta, &lSMakanan, &lResep, &lokasiSimulator, &MIX, &BOIL, &CHOP, &FRY, &TELEPON, inputFolder);
        buatFQKosong(&inventoryQ, 20);
        buatFQKosong(&deliveryQ, 20);
        buatSimulator(&BNMO, userName, Absis(lokasiSimulator), Ordinat(lokasiSimulator), inventoryQ);
        buatState(&cState, Absis(lokasiSimulator), Ordinat(lokasiSimulator), 0, 0, 0, 0, inventoryQ, deliveryQ);
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
    Teks waitT;
    buatTeks("WAIT", &waitT);

    while (!exiting)
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
        boolean isCommandValid = false;
        boolean isChangeState = true;
        boolean isUndoRedo = false;
        State salinanState;
        Stack stackUndo, stackRedo;
        // Inisialisasi
        CreateEmptyStack(&stackUndo, 10);
        CreateEmptyStack(&stackRedo, 10);
        LDinTeks command;
        do
        {
            printf("Enter command: ");
            startMBInput();
            command = currentRowI;
            copyState(cState, &salinanState);
            if (panjangLDinTeks(command) == 1 && teksSama(buyT, elmtLDT(command, 0)))
            {
                buyFood(&deliveryQ, lSMakanan, &cState, TELEPON, &isChangeState);
                isCommandValid = true;
                isUndoRedo = false;
            }
            else if (stringSame(command, "FRY") || stringSame(command, "BOIL") || stringSame(command, "MIX") || stringSame(command, "CHOP"))
            {
                Teks temp;
                buatTeks(command, &temp);
                olahMakanan(temp, &inventoryQ, &deliveryQ, &lResep, &lSMakanan, &cState, &isChangeState);
                isCommandValid = true;
                isUndoRedo = false;
            }
            else if (stringSame(command, "COOKBOOK"))
            {
                displayCookbook(&lResep);
                isCommandValid = true;
                isUndoRedo = false;
                isChangeState = false;
            }
            else if (stringSame(command, "CATALOG"))
            {
                displayCatalog(&lSMakanan);
                isCommandValid = true;
                isUndoRedo = false;
                isChangeState = false;
            }
            else if (stringSame(command, "MOVE NORTH") || stringSame(command, "MOVE EAST") || stringSame(command, "MOVE SOUTH") || stringSame(command, "MOVE WEST"))
            {
                Teks direction;
                if (stringSame(command, "MOVE NORTH"))
                {
                    buatTeks("NORTH", &direction);
                }
                else if (stringSame(command, "MOVE EAST"))
                {
                    buatTeks("EAST", &direction);
                }
                else if (stringSame(command, "MOVE SOUTH"))
                {
                    buatTeks("SOUTH", &direction);
                }
                else if (stringSame(command, "MOVE WEST"))
                {
                    buatTeks("WEST", &direction);
                }

                moveS(&cState, &peta, &BNMO, &isChangeState, direction, 1, MIX, BOIL, CHOP, FRY, TELEPON);
                isCommandValid = true;
                isUndoRedo = false;
            }
            else if (stringSame(command, "UNDO"))
            {
                isCommandValid = true;
                isUndoRedo = true;
                undo(&cState, &stackUndo, &stackRedo, salinanState);
            }
            else if (stringSame(command, "REDO"))
            {
                isCommandValid = true;
                isUndoRedo = true;
                redo(&cState, &stackUndo, &stackRedo, salinanState);
            }
            else if (stringSame(command, "0"))
            {
                isCommandValid = true;
                isChangeState = false;
                exiting = true;
            }

            else // untuk kasus command lebih dari satu kata atau command tak valid
            {
                Teks teksCommand, move, wait, teksParsing;
                int i;
                buatTeks(command, &teksCommand);
                buatTeks("MOVE", &move);
                buatTeks("WAIT", &wait);
                buatTeksKosong(&teksParsing);

                // Pengecekan kata pertama
                i = 0;
                while (nthChar(teksCommand, i) != ' ')
                {
                    plusKar(&teksParsing, nthChar(teksCommand, i));
                    i++;
                }
                // Telah selesai mengambil kata pertama
                i++;                             // skip blank pertama
                if (teksSama(teksParsing, move)) // Jika command move
                {
                    Teks direction, tDisplacement;
                    int displacement;
                    isCommandValid = true;

                    buatTeksKosong(&direction);
                    buatTeksKosong(&tDisplacement);
                    // Mengambil direction
                    while (nthChar(teksCommand, i) != ' ')
                    {
                        plusKar(&direction, nthChar(teksCommand, i));
                        i++;
                    }
                    i++; // Skip blank kedua
                    // Mengambil displacement

                    while (i < panjangT(teksCommand))
                    {
                        plusKar(&tDisplacement, nthChar(teksCommand, i));
                        i++;
                    }

                    displacement = teksToInt(tDisplacement);

                    // Mengubah lokasi simulator
                    moveS(&cState, &peta, &BNMO, &isChangeState, direction, displacement, MIX, BOIL, CHOP, FRY, TELEPON);
                }
                else if (teksSama(teksParsing, wait)) // Jika command wait
                {
                    Teks tHH, tMM;
                    int HH, MM;
                    Waktu time;

                    buatTeksKosong(&tHH);
                    buatTeksKosong(&tMM);
                    isCommandValid = true;

                    // Mengambil durasi jam
                    while (nthChar(teksCommand, i) != ' ')
                    {
                        plusKar(&tHH, nthChar(teksCommand, i));
                        i++;
                    }
                    HH = teksToInt(tHH);
                    i++; // Skip blank kedua

                    // Mengambil durasi menit
                    while (i < panjangT(teksCommand))
                    {
                        plusKar(&tMM, nthChar(teksCommand, i));
                        i++;
                    }
                    MM = teksToInt(tMM);

                    // Memajukan waktu state
                    time = buatWaktu(0, HH, MM, 0);
                    majukanWaktuState(&cState, time);
                }
                else
                {
                    isCommandValid = false;
                }
            }

            if (!isCommandValid)
            {
                printf("Command tidak dikenali!\n");
            }
            else
            {
                // Push stack undo dan delete All stack redo jika terjadi perubahan state dan bukan undo redo
                if (isChangeState && !isUndoRedo)
                {
                    dealocateStack(&stackRedo);
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