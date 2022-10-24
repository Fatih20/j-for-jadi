#include "mKFile.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKF;
Teks currentWord;

int main(int argc, char const *argv[])
{
    startMKFile("test.txt");
    while (!endMKF)
    {
        cetakTeks(currentWord);
        printf("\n");
        advMKFile();
    }

    return 0;
}
