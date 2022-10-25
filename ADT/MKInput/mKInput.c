#include "mKInput.h"
#include "../MCInput/mCInput.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKI;
Teks currentWord;

void ignoreBlanksF()
{
    while (currentChar == BLANK)
    {
        advMCInput();
    }
}

void startMKInput(char namaFile[])
{
    endMKI = false;

    startMCInput(namaFile);
    advMKInput();
}

void advMKInput()
{
    ignoreBlanksF();
    if (currentChar == MARKI)
    {
        endMKI = true;
    }
    else
    {

        saveKataI();
    }
}

void saveKataI()
{
    buatTeks("", &currentWord);
    boolean actualLetter = true;
    while (actualLetter)
    {
        if (currentChar == BLANK || currentChar == MARKI)
        {
            actualLetter = false;
        }
        else
        {
            plusKar(&currentWord, currentChar);
            advMCInput();
        }
    }
}
