#include "ldinkar.h"
#include <stdio.h>
#include <string.h>

int main()
{
    LDinKar l, ltemp;
    LDinKarEl temp1 = '$';
    LDinKarEl temp2 = '#';

    buatLDinKar(&l, 1);
    readLDinKar(&l);
    printLDinKar(l);

    /* Uji insertFirstLDinKar*/
    printf("*****Insert First*****\n");
    insertFirstLDinKar(&l, temp1);
    printLDinKar(l);
    /* UJI insertAtLDinKar */
    printf("*****Insert At*****\n");
    insertAtLDinKar(&l, temp1, 1);
    printLDinKar(l);
    /* UJI insertLastLDinKar */
    printf("*****Insert Last*****\n");
    insertLastLDinKar(&l, temp2);
    printLDinKar(l);

    /* UJI copyLDinKar*/
    printf("*****Copy*****\n");
    copyLDinKar(l, &ltemp);
    printf("*****Copied List*****\n");
    printLDinKar(ltemp);

    dealokasiLDinKar(&l);
    dealokasiLDinKar(&ltemp);
}