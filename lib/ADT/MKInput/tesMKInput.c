#include "mKInput.h"
#include "../Teks/teks.h"
#include <stdio.h>

boolean endMKI;
Teks currentWord;

int main(int argc, char const *argv[])
{
    startMKInput();
    while (!endMKI)
    {
        cetakTeks(currentWord, 'b');
        printf("\n");
        advMKInput();
    }
    printf("MK Ended\n\n");
    char test[100];
    scanf("%s", test);
    printf("%s", test);
    printf("Restarting MK\n\n");
    startMKInput();
    startMKInput();
    // printf("%d\n", endMKI);
    do
    {
        cetakTeks(currentWord, 'b');
        advMKInput();

    } while (!endMKI);
    // while (!endMKI)
    // {
    //     cetakTeks(currentWord);
    //     printf("\n");
    //     advMKInput();
    // }

    return 0;
}
