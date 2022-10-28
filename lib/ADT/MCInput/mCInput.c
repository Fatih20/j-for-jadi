/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "mCInput.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void startMCInput()
{
    pita = stdin;
    advMCInput();
}

void advMCInput()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARKI);
    if (EOP)
    {
        fclose(pita);
    }
}