/* File: charmachine.c */
/* Implementasi Mesin Karakter */

#include "mCInput.h"
#include "../../Utility/Printc/printc.h"
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
    printf("%s", CYAN);
    retval = fscanf(pita, "%c", &currentCharI);
    printf("%s", NORMAL);
    EOPI = (currentCharI == MARKI);
}