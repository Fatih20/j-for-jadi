#include "mBFile.h"
#include "../Teks/teks.h"
#include "../ListDinTeks/ldinteks.h"
#include <stdio.h>

boolean endMBF;
Teks currentWord;

int main(int argc, char const *argv[])
{
    startMBFile("test.txt");
    while (!endMBF)
    {
        printLDinTeks(currentRow);
        advMBFile();
    }

    return 0;
}
