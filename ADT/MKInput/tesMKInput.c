#include "mKInput.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKI;
Teks currentWord;

int main(int argc, char const *argv[])
{
    startMKInput();
    while (!endMKI)
    {
        cetakTeks(currentWord);
        printf("\n");
        advMKInput();
    }

    return 0;
}
