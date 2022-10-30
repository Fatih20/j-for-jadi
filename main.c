#include <stdio.h>
#include <stdlib.h>
#include "lib/ADT/Teks/teks.h"

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
    char inputString[10];
    char startString[] = "START";
    char exitString[] = "EXIT";
    Teks inputTeks;
    Teks startTeks;
    Teks exitTeks;

    printf("Masukkan command: START atau EXIT\n");
    buatTeks(startString, &startTeks);
    buatTeks(exitString, &exitTeks);
    scanf("%s", inputString);
    buatTeks(inputString, &inputTeks);
    while (!teksSama(inputTeks, exitTeks))
    {
        if (teksSama(inputTeks, startTeks))
        {
            /* Proses */
        }
        else if (!teksSama(inputTeks, startTeks) && !teksSama(inputTeks, exitTeks))
        {
            printf("Command yang dimasukkan salah\n");
        }
        scanf("%s", inputString);
        buatTeks(inputString, &inputTeks);
    }
    return 0;
}