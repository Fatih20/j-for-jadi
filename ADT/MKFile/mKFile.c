#include "mKFile.h"
#include "../MCFile/mCFile.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKF;
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
    while (isBlankF(currentChar))
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
    if (currentChar == MARKF)
    {
        endMKF = true;
    }
    else
    {

        saveKata();
    }
}

void saveKata()
{
    buatTeks("", &currentWord);
    boolean actualLetter = true;
    while (actualLetter)
    {
        if (isBlankF(currentChar) || currentChar == MARKF)
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
