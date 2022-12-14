#include "ldinteks.h"
#include <stdio.h>
#include <string.h>

int main()
{
    LDinTeks l, ltemp;
    char temp1[] = "temp1";
    char temp2[] = "temp2";
    LDinTeksEl teks1, teks2;
    buatTeks(temp1, &teks1);
    buatTeks(temp2, &teks2);
    buatLDinTeks(&l, 1);
    readLDinTeks(&l);
    printLDinTeks(l);
    /* Uji insertFirstLDinTeks*/
    printf("*****Insert First*****\n");
    insertFirstLDinTeks(&l, teks1);
    printLDinTeks(l);
    /* UJI insertAtLDinTeks */
    printf("*****Insert At*****\n");
    insertAtLDinTeks(&l, teks1, 1);
    printLDinTeks(l);
    /* UJI insertLastLDinTeks */
    printf("*****Insert Last*****\n");
    insertLastLDinTeks(&l, teks2);
    printLDinTeks(l);

    /* UJI copyLDinTeks*/
    printf("*****Copy*****\n");
    copyLDinTeks(l, &ltemp);
    printf("*****Copied List*****\n");
    printLDinTeks(ltemp);

    /* UJI removeFirst */
    printf("****First Element Removed*****\n");
    Teks val;
    removeFirstLDinTeks(&l, &val);
    printLDinTeks(l);

    /* UJI removeLast */
    printf("****Last Element Removed*****\n");
    removeLastLDinTeks(&l, &val);
    printLDinTeks(l);

    printf("****Element at Idx 1 Removed*****\n");
    removeAtLDinTeks(&l, &val, 1);
    printLDinTeks(l);
    dealokasiLDinTeks(&l);
    dealokasiLDinTeks(&ltemp);
}