#include "../boolean.h"
#include "mKarFile.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    char test[] = "test.txt";
    startMKFile(test);
    while (currentChar != MARK)
    {
        printf("%c", currentChar);
        advMKFile();
    }
    return 0;
}
