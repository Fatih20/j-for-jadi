#include <stdio.h>
#include <stdlib.h>
#include "lib/ADT/MKInput/mKInput.h"
#include "lib/Utility/Loader/Loader.h"
#include "lib/Utility/String/String.h"

int main(int argc, char const *argv[])
{
    /* Splash screen */
    /* Convert gambar ke txt, baca per baris, diprint ke layar */
    int i;
    char baris[200];
    FILE *fpointer = fopen("pic.txt", "r");

    for (i = 0; i < 28; i++)
    {
        fgets(baris, 200, fpointer);
        printf("%s", baris);
    }
    printf("\n");

    /* Struktur main */
    Teks inputTeks;
    Teks startTeks;
    Teks exitTeks;

    buatTeks("START", &startTeks);
    buatTeks("EXIT", &exitTeks);

    boolean exitFirstLoop;
    boolean entering = false;
    boolean exiting = true;
    char iInput[10];
    do
    {
        printf("Masukkan command (START atau EXIT) : \n");
        scanf("%s", &iInput);
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
    ListNode lNMakanan;
    POINT lokasiSimulator;
    AksiLokasi MIX;
    AksiLokasi BOIL;
    AksiLokasi CHOP;
    AksiLokasi FRY;
    AksiLokasi TELEPON;

    if (entering)
    {
        loader(&peta, &lSMakanan, &lNMakanan, &lokasiSimulator, &MIX, &BOIL, &CHOP, &FRY, &TELEPON);
    }

    while (!exiting)
    {
        // displayListNode(lNMakanan);
        // printf("\n");
        // displayMatriks(peta);
        // printf("\n");

        exiting = true;
    }
    return 0;
}