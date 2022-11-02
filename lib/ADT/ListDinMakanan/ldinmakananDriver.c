#include "ldinmakanan.h"
#include <stdio.h>
#include <string.h>

int main()
{
    LDinMakanan l, ltemp;

    Makanan temp1, temp2;
    Waktu wB1, wB2, wB3, wB4, wS1, wS2, wS3, wS4;
    int panjang = 6;
    int lebar = 4;
    wB1 = buatWaktu(0, 0, 3, 0);
    wB2 = buatWaktu(0, 0, 2, 0);
    wB3 = buatWaktu(0, 0, 2, 0);
    wB4 = buatWaktu(0, 0, 1, 0);

    wS1 = buatWaktu(0, 0, 1, 0);
    wS2 = buatWaktu(0, 0, 2, 0);
    wS3 = buatWaktu(0, 0, 2, 0);
    wS4 = buatWaktu(0, 0, 3, 0);

    AksiLokasi aL1, aL2, aL3, aL4;
    Teks namaM1, idTM1, idUM1, aLT1;
    Teks namaM2, idTM2, idUM2, aLT2;
    Teks namaM3, idTM3, idUM3, aLT3;
    Teks namaM4, idTM4, idUM4, aLT4;

    buatTeks("BUY", &aLT1);
    buatTeks("Susu", &namaM1);
    buatTeks("010", &idTM1);
    buatTeks("000", &idUM1);
    buatAksiLokasi(&aL1, aLT1, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT2);
    buatTeks("Tempe", &namaM2);
    buatTeks("011", &idTM2);
    buatTeks("000", &idUM2);
    buatAksiLokasi(&aL2, aLT2, 2, 2, 0, 1, 5, 0);

    buatMakanan(&temp1, namaM1, idTM1, idUM1, wB1, wS1, aL1, panjang, lebar);
    buatMakanan(&temp2, namaM2, idTM2, idUM2, wB2, wS2, aL2, panjang, lebar);

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