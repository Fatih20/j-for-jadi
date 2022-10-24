#include "mKFile.h"
#include "../MCFile/mCFile.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKF;
boolean EOP;
Teks currentWord;

boolean isIgnoredF(char c)
{
    switch (c)
    {
    case '\n':
        return true;
        break;
    case ' ':
        return true;
        break;

    default:
        return false;
        break;
    }
}

boolean isBlankF(char c)
{
    return c == ' ';
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
    else if (currentChar == '\n')
    {
        buatNewLine();
    }
    else
    {

        saveKataF();
    }
}

void buatNewLine()
{
    buatTeksKosong(&currentWord);
    plusKar(&currentWord, '\n');
    advMCFile();
}

void saveKataF()
{
    buatTeks("", &currentWord);
    boolean actualLetter = true;
    while (actualLetter)
    {
        if (isIgnoredF(currentChar) || EOP)
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
