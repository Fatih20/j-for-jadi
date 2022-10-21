#include "teks.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Teks t1;
    buatTeks("Brurhruhr", &t1);
    cetakTeks(t1);
    delKar(&t1);
    delKar(&t1);
    delKar(&t1);
    delKar(&t1);
    cetakTeks(t1);

    Teks t2;
    buatTeks("Dgklg", &t2);
    cetakTeks(t2);
    plusKar(&t2, 'o');
    cetakTeks(t2);

    Teks t3;
    gabungkanTeks(t1, t2, &t3);
    cetakTeks(t3);

    return 0;
}
