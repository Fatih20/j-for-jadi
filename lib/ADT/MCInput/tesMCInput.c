#include "../boolean.h"
#include "mCInput.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    startMCInput();
    while (currentCharI != MARKI)
    {
        printf("%c\n", currentCharI);
        advMCInput();
    }
    return 0;
}
