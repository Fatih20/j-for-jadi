#include "mKFile.h"
#include "../MCFile/mCFile.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKF;
boolean EOP;
Teks currentWord;

boolean isBlankF(char c)
{
    switch (c)
    {
    case '\n':
        return true;
        return false;
        break;
    case ' ':
        return true;
        break;

    default:
        return false;
        break;
    }
}

void ignoreBlanksF()
{
    /* Mengabaikan satu atau beberapa BLANK
       I.S. : currentChar sembarang
       F.S. : currentChar ≠ BLANK atau currentChar = MARK */
    while (isBlankF(currentChar) && !EOP)
    {
        advMCFile();
    }
}

void startMKFile(char namaFile[])
{
    endMKF = false;

    startMCFile(namaFile);
    advMKFile();
}

void advMKFile()
{
    ignoreBlanksF();
    if (EOP)
    {
        endMKF = true;
    }
    else
    {

        saveKataF();
    }
}

void saveKataF()
{
    buatTeks("", &currentWord);
    boolean actualLetter = true;
    while (actualLetter)
    {
        if (isBlankF(currentChar) || EOP)
        {
            actualLetter = false;
        }
        else if (panjangT(currentWord) < NMax)
        {
            plusKar(&currentWord, currentChar);
            // currentWord.Length++;
            // currentWord.TabWord[currentWord.Length - 1] = currentChar;
            advMCFile();
        }
        else
        {
            advMCFile();
        }
    }
}
