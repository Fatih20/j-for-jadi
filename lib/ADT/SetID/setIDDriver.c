#include "setID.h"
#include <stdio.h>

int main()
{
    SetID s1, s2, s3, s4, s5, s6, s7, s8;
    char string1[] = "100";
    char string2[] = "200";
    char string3[] = "300";
    char string4[] = "400";
    char string5[] = "500";
    char string6[] = "600";
    char string7[] = "700";
    Teks teks1;
    Teks teks2;
    Teks teks3;
    Teks teks4;
    Teks teks5;
    Teks teks6;
    Teks teks7;

    createSet(&s1);
    if (isEmptySet(s1))
    {
        printf("Set s1 kosong\n");
    }
    printf("Panjang set s1 = %d\n", lengthSet(s1));

    buatTeks(string1, &teks1);
    addElmtSet(&s1, teks1);
    printf("Set s1 setelah ditambahkan teks1: ");
    printSetID(s1);
    printf("\n");

    buatTeks(string2, &teks2);
    buatTeks(string3, &teks3);
    addElmtSet(&s1, teks2);
    addElmtSet(&s1, teks3);
    removeElmtSet(&s1, teks2);
    printf("Set s1 setelah ditambahkan teks2 dan teks3, serta dihapuskan teks2: ");
    printSetID(s1);
    printf("\n");

    if (isElmtInSet(s1, teks3))
    {
        printf("teks3 merupakan elemen set s1\n");
    }
    if (!isElmtInSet(s1, teks2))
    {
        printf("teks2 bukan merupakan elemen set s1\n");
    }

    createSet(&s2);
    addElmtSet(&s2, teks1);
    addElmtSet(&s2, teks3);
    if (isSetEqual(s1, s2))
    {
        printf("Set s1 dan s2 sama\n");
    }

    createSet(&s3);
    buatTeks(string4, &teks4);
    buatTeks(string5, &teks5);
    addElmtSet(&s3, teks1);
    addElmtSet(&s3, teks2);
    addElmtSet(&s3, teks3);
    addElmtSet(&s3, teks4);
    addElmtSet(&s3, teks5);

    printf("Set s3: ");
    printSetID(s3);
    printf("\n");
    if (!isSetEqual(s1, s3))
    {
        printf("Set s1 dan s3 tidak sama\n");
    }

    createSet(&s4);
    buatTeks(string6, &teks6);
    buatTeks(string7, &teks7);
    addElmtSet(&s4, teks3);
    addElmtSet(&s4, teks6);
    addElmtSet(&s4, teks7);
    printf("Set s4: ");
    printSetID(s4);
    printf("\n");

    s5 = setUnion(s1, s4);
    printf("Union s1 dengan s4: ");
    printSetID(s5);
    printf("\n");

    s6 = setIntersection(s1, s4);
    printf("Irisan s1 dengan s4: ");
    printSetID(s6);
    printf("\n");

    s7 = setDifference(s4, s1);
    printf("s4-s1 = ");
    printSetID(s7);
    printf("\n");

    s8 = copySet(s4);
    printf("Salinan s4: ");
    printSetID(s8);
    printf("\n");

    if (isSubset(s1, s3))
    {
        printf("Set s1 adalah subset dari s3");
    }

    return 0;
}