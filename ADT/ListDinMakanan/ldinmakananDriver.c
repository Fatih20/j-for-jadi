#include "ldinmakanan.h"
#include <stdio.h>
#include <string.h>

int main()
{
    LDinMakanan l, ltemp;
    Makanan temp1, temp2;
    char susu[] = "susu";
    char tahu[] = "tahu";
    char idSusu[] = "010";
    char idTahu[] = "012";
    buatMakanan(&temp1, susu, 2, 3, idSusu, idSusu);
    buatMakanan(&temp2, tahu, 2, 3, idTahu, idTahu);
    buatLDinMakanan(&l, 1);
    readLDinMakanan(&l);

    /* Uji insertFirstLDinMakanan*/
    printf("*****Insert First*****\n");
    insertFirstLDinMakanan(&l, temp1);
    insertFirstLDinMakanan(&l, temp2);
    printLDinMakanan(l);
    printf("\n");
    /* UJI insertAtLDinMakanan */
    printf("*****Insert At*****\n");
    insertAtLDinMakanan(&l, temp1, 1);
    printLDinMakanan(l);
    printf("\n");
    /* UJI insertLastLDinMakanan */
    printf("*****Insert Last*****\n");
    insertLastLDinMakanan(&l, temp2);
    printLDinMakanan(l);
    printf("\n");

    /* UJI copyLDinMakanan*/
    printf("*****Copy*****\n");
    copyLDinMakanan(l, &ltemp);
    printf("*****Copied List*****\n");
    printLDinMakanan(ltemp);
    printf("\n");

    /* UJI removeFirstLDinMakanan*/
    printf("*****List With First Element Removed*****\n");
    removeFirstLDinMakanan(&l, &temp1);
    printLDinMakanan(l);
    printf("\n");

    /* Uji removeLastLDinMakanan*/
    printf("*****List With Last Element Removed*****\n");
    Makanan val;
    removeLastLDinMakanan(&l, &val);
    printLDinMakanan(l);
    printf("\n");

    /* Uji removeAtLDinMakanan*/
    printf("*****List With Element At Idx Removed*****\n");
    removeAtLDinMakanan(&l, &val, 1);
    printLDinMakanan(l);
    printf("\n");
    cetakMakanan(val);
    dealokasiLDinMakanan(&l);
    dealokasiLDinMakanan(&ltemp);
}