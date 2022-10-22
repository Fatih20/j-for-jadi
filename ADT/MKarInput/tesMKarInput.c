#include "../boolean.h"
#include "mKarInput.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    startMKInput();
    while (currentChar != MARK)
    {
        printf("%c\n", currentChar);
        advMKInput();
    }
    return 0;
}
