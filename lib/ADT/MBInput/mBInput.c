#include "mBInput.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMBI;
LDinTeks currentRowI;

void startMBInput()
{
    endMBI = false;
    startMKInput();
    advMBInput();
}

void advMBInput()
{

    saveBarisI();
    endMBI = endMKI;
}

void saveBarisI()
{
    buatLDinTeks(&currentRowI, 5);
    while (!endMKI)
    {
        insertLastLDinTeks(&currentRowI, currentWordI);
        advMKInput();
    };
    insertLastLDinTeks(&currentRowI, currentWordI);
}
