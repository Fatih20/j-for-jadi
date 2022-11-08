#include "mBFile.h"
#include "../MCFile/mCFile.h"
#include "../MKFile/mKFile.h"
#include "../ListDinTeks/ldinteks.h"
#include "../Teks/teks.h"
#include <stdio.h>

// char currentChar;
// boolean endMKF;
boolean endMBF;
// Teks currentWord;
LDinTeks currentRow;

boolean isBlankFB(Teks t)
{
    Teks tN;
    buatTeksKosong(&tN);
    plusKar(&tN, '\n');
    return teksSama(t, tN);
}

void ignoreBlanksFB()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (isBlankFB(currentWord))
    {
        advMKFile();
    }
}

void startMBFile(char namaFile[])
{
    endMBF = false;

    startMKFile(namaFile);
    advMBFile();
}

void advMBFile()
{
    ignoreBlanksFB();
    if (endMKF)
    {
        endMBF = true;
    }
    else
    {

        saveBarisF();
    }
}

void saveBarisF()
{
    buatLDinTeks(&currentRow, 5);
    boolean rowEnded = false;
    while (!rowEnded)
    {
        if (isBlankFB(currentWord) || endMKF)
        {
            rowEnded = true;
        }
        else
        {
            insertLastLDinTeks(&currentRow, currentWord);
            advMKFile();
        }
    }
}
