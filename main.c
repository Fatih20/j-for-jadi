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
        // exitFirstLoop = exiting;

        if (!exitFirstLoop)
        {
            printf("Command yang dimasukkan salah\n");
        }
    } while (!exitFirstLoop);

    Matriks peta;
    LStatMakanan lSMakanan;
    ListNode lNMakanan;
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
        printf("Test\n");
        loader(&peta, &lSMakanan, &lNMakanan, &lokasiSimulator, &MIX, &BOIL, &CHOP, &FRY, &TELEPON);
        buatFQKosong(&inventoryQ, 20);
        buatFQKosong(&deliveryQ, 20);
        buatState(&cState, Absis(lokasiSimulator), Ordinat(lokasiSimulator), 0, 0, 0, 0, inventoryQ);
        displayMatriks(peta);
    }

    while (!exiting)
    {
        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // buyFood(&deliveryQ, lSMakanan, &cState, TELEPON);
        // cetakFoodQueue(deliveryQ);

        exiting = true;
    }
    return 0;
}