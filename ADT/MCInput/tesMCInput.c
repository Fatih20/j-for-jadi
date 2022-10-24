#include "../boolean.h"
#include "mCInput.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    startMCInput();
    while (currentChar != MARKI)
    {
        printf("%c\n", currentChar);
        advMCInput();
    }
    return 0;
}
