#include "mBInput.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMBI;
LDinTeks currentRowI;

int main(int argc, char const *argv[])
{
    startMBInput();
    printLDinTeks(currentRowI);

    startMBInput();
    printLDinTeks(currentRowI);

    startMBInput();
    printLDinTeks(currentRowI);

    // do
    // {
    //     printLDinTeks(currentRowI);
    //     advMBInput();
    // } while (!endMBI);

    return 0;
}
