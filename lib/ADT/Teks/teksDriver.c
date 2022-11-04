#include "teks.h"
#include "../ListDinKar/ldinkar.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    Teks t1;
    buatTeks("this is lowercase", &t1);
    // cetakTeks(t1);

    Teks t2;
    buatTeks("1%^6&*FATIHGAY1", &t2);

    cetakTeks(toUpper(t1), 'r');

    // printf("%d\n", teksSamaCI(t1, t2));
    // char tString[100];
    // scanf("%[^\n]", tString);
    // buatTeks(tString, &t1);
    // cetakTeks(t1);
    // cetakTeks(t1);
    // printf("\n");
    // delKar(&t1);
    // delKar(&t1);
    // delKar(&t1);
    // delKar(&t1);
    // cetakTeks(t1);
    // printf("\n");

    // Teks t2;
    // buatTeks("Dgklg", &t2);
    // cetakTeks(t2);
    // printf("\n");
    // plusKar(&t2, 'o');
    // plusKar(&t2, 'o');
    // plusKar(&t2, 'o');
    // cetakTeks(t2);
    // printf("\n");

    // Teks t3;
    // gabungkanTeks(t1, t2, &t3);
    // cetakTeks(t3);
    // printf("\n");

    return 0;
}
