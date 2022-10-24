#include "teks.h"
#include "../ListDinKar/ldinkar.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    Teks t1;
    buatTeks("quis auctor elit sed vulputate mi sit amet mauris commodo quis imperdiet massa tincidunt", &t1);
    cetakTeks(t1);
    printf("\n");
    delKar(&t1);
    delKar(&t1);
    delKar(&t1);
    delKar(&t1);
    cetakTeks(t1);
    printf("\n");

    Teks t2;
    buatTeks("Dgklg", &t2);
    cetakTeks(t2);
    printf("\n");
    plusKar(&t2, 'o');
    plusKar(&t2, 'o');
    plusKar(&t2, 'o');
    cetakTeks(t2);
    printf("\n");

    Teks t3;
    gabungkanTeks(t1, t2, &t3);
    cetakTeks(t3);
    printf("\n");

    return 0;
}
