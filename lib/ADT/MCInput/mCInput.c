/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "mCInput.h"
#include <stdio.h>

char currentCharI;
boolean EOPI;

static FILE *pita;
static int retval;

void startMCInput()
{
    EOPI = false;
    pita = stdin;
    advMCInput();
}

void advMCInput()
{
    retval = fscanf(pita, "%c", &currentCharI);
    EOPI = (currentCharI == MARKI);
}