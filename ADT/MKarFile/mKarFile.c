/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "mKarFile.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void startMKFile(char namaFile[])
{
    pita = fopen(namaFile, "r");
    advMKFile();
}

void advMKFile()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP)
    {
        fclose(pita);
    }
}