#include "../boolean.h"
#include "mCFile.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char test[] = "test.txt";
    startMCFile(test);
    while (!EOP)
    {
        printf("%c", currentChar);
        advMCFile();
    }
    return 0;
}
