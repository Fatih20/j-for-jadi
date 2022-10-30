#include <stdio.h>
#include <stdlib.h>
#include "..lib/ADT/Teks/teks.h"

int main(int argc, char const *argv[])
{
    /* Splash screen */
    /* Convert gambar ke txt, baca per baris, diprint ke layar */
    int i;
    char baris[200];
    FILE *fpointer = fopen("robot.txt", "r");

    printf("\n");
    printf("\n");
    for (i = 0; i < 117; i++)
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