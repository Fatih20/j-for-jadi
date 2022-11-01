#include "mKInput.h"
#include "../MCInput/mCInput.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKI;
Teks currentWordI;

void ignoreBlanksI()
{
    while (currentCharI == BLANK)
    {
        advMCInput();
    }
}

void startMKInput()
{
    endMKI = false;
    startMCInput();
    advMKInput();
}

void advMKInput()
{
    ignoreBlanksI();
    if (currentCharI == MARKI)
    {
        endMKI = true;
    }
    else
    {

        saveKataI();
        endMKI = currentCharI == MARKI;
    }
}

void saveKataI()
{
    buatTeks("", &currentWordI);
    boolean actualLetter = true;
    while (actualLetter)
    {
        if (currentCharI == BLANK || currentCharI == MARKI)
        {
            actualLetter = false;
        }
        else
        {
            plusKar(&currentWordI, currentCharI);
            advMCInput();
        }
    }
}
