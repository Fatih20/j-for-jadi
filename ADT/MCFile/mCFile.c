/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "mCFile.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void startMCFile(char namaFile[])
{
    pita = fopen(namaFile, "r");
    advMCFile();
}

void advMCFile()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (retval != 1);
    if (EOP)
    {
        fclose(pita);
    }
}