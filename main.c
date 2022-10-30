#include <stdio.h>
#include <stdlib.h>
#include "lib/ADT/MKInput/mKInput.h"
#include "lib/Utility/Loader/Loader.h"

Teks currentWord;

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
    do
    {
        printf("Masukkan command (START atau EXIT) : \n");
        startMKInput();
        entering = teksSama(currentWord, startTeks);
        exiting = teksSama(currentWord, exitTeks);
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
    }
    // while (!teksSama(currentWord, exitTeks))
    // {
    //     if (teksSama(currentWord, startTeks))
    //     {
    //         /* Proses */
    //     }
    //     else if (!teksSama(currentWord, startTeks) && !teksSama(currentWord, exitTeks))
    //     {
    //         printf("Command yang dimasukkan salah\n");
    //     }
    //     scanf("%s", inputString);
    //     buatTeks(inputString, &currentWord);
    //     startMKInput();
    // }
    return 0;
}