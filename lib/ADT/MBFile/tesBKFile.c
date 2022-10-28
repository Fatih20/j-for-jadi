#include "mBFile.h"
#include "../Teks/teks.h"
#include "../ListDinTeks/ldinteks.h"
#include <stdio.h>

boolean endMBF;
Teks currentWord;

int main(int argc, char const *argv[])
{
    int i = 0;
    startMBFile("test.txt");
    while (!endMBF)
    {
        printf("panjang: %d ", panjangLDinTeks(currentRow));
        printLDinTeks(currentRow);
        advMBFile();
        i++;
    }

    return 0;
}
