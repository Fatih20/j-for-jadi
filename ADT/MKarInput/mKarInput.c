/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "mKarInput.h"
#include <stdio.h>

char currentChar;
boolean EOP;

static FILE *pita;
static int retval;

void startMKInput()
{
    pita = stdin;
    advMKInput();
}

void advMKInput()
{
    retval = fscanf(pita, "%c", &currentChar);
    EOP = (currentChar == MARK);
    if (EOP)
    {
        fclose(pita);
    }
}