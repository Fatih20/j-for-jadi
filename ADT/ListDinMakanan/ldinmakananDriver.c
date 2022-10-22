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
    printLDinMakanan(l);
    /* UJI insertAtLDinMakanan */
    printf("*****Insert At*****\n");
    insertAtLDinMakanan(&l, temp1, 1);
    printLDinMakanan(l);
    /* UJI insertLastLDinMakanan */
    printf("*****Insert Last*****\n");
    insertLastLDinMakanan(&l, temp2);
    printLDinMakanan(l);

    /* UJI copyLDinMakanan*/
    printf("*****Copy*****\n");
    copyLDinMakanan(l, &ltemp);
    printf("*****Copied List*****\n");
    printLDinMakanan(ltemp);

    dealokasiLDinMakanan(&l);
    dealokasiLDinMakanan(&ltemp);
}