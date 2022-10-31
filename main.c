#include <stdio.h>
#include <stdlib.h>
#include "lib/ADT/MKInput/mKInput.h"
#include "lib/ADT/FoodQueue/foodQueue.h"
#include "lib/Utility/Loader/Loader.h"
#include "lib/Utility/String/String.h"
#include "lib/Utility/Commands/commands.h"

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
    char iInput[10];
    do
    {
        printf("Masukkan command (START atau EXIT) : \n");
        scanf("%s", iInput);
        entering = stringSame(iInput, "START");
        exiting = stringSame(iInput, "EXIT");
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
        loader(&peta, &lSMakanan, &lResep, &lokasiSimulator, &MIX, &BOIL, &CHOP, &FRY, &TELEPON);
        buatFQKosong(&inventoryQ, 20);
        buatFQKosong(&deliveryQ, 20);
        buatState(&cState, Absis(lokasiSimulator), Ordinat(lokasiSimulator), 0, 0, 0, 0, inventoryQ);
        printf("===================================================\n");
        printf("                   BNMO MASAK-MASAK                \n");
        printf("===================================================\n");
    }

    while (!exiting)
    {
        printf("BNMO di posisi: ");
        TulisPOINT(posisiState(cState));
        printf("\n");
        printf("Waktu: ");
        tulisWaktu(waktuState(cState));
        printf("\n");
        displayMatriks(peta);
        printf("\n");
        char command[100];
        boolean isCommandValid = false;
        do
        {
            printf("Enter command: ");
            scanf("%s", command);
            if (stringSame(command, "BUY"))
            {
                buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
                isCommandValid = true;
            }
            else if (stringSame(command, "FRY") || stringSame(command, "BOIL") || stringSame(command, "MIX") || stringSame(command, "CHOP"))
            {
                Teks temp;
                buatTeks(command, &temp);
                olahMakanan(temp, &inventoryQ, &lResep, &lSMakanan, &cState);
                cetakState(cState);
                isCommandValid = true;
                exiting = false;
            }
            else if (stringSame(command, "COOKBOOK"))
            {
                displayCookbook(&lResep);
                isCommandValid = true;
            }
            else if (stringSame(command, "CATALOG"))
            {
                displayCatalog(&lSMakanan);
                isCommandValid = true;
            }
            else if (stringSame(command, "0"))
            {
                isCommandValid = true;
                exiting = true;
            }
            if (!isCommandValid)
            {
                printf("Command tidak dikenali!\n");
            }
        } while (!isCommandValid);

        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // cetakFoodQueue(deliveryQ);
    }
    return 0;
}