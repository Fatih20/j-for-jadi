#include "teks.h"
#include "../ListDinKar/ldinkar.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{

    Teks t1;
    buatTeks("jvndjnjvnvdhjhbbhhjbhjbhj", &t1);
    // cetakTeks(t1);
    char s1[panjangT(t1) + 1];
    teksKeString(s1, t1);
    printf("%s", s1);

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
