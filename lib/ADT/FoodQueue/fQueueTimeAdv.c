#include "foodQueue.h"

void tC1()
{
    printf("TEST CASE 1\n\n");
    FoodQueue dq, iq;
    Makanan temp1, temp2, temp3, temp4, temp5, temp6;
    Waktu wB1, wB2, wB3, wB4, wB5, wB6;
    Waktu wS1, wS2, wS3, wS4, wS5, wS6;
    int panjang = 6;
    int lebar = 4;
    wB1 = buatWaktu(0, 0, 10, 0);
    wB2 = buatWaktu(0, 0, 7, 0);
    wB3 = buatWaktu(0, 0, 1, 0);
    wB4 = buatWaktu(0, 0, 2, 0);
    wB5 = buatWaktu(0, 0, 3, 0);
    wB6 = buatWaktu(0, 0, 4, 0);

    wS1 = buatWaktu(0, 0, 5, 0);
    wS2 = buatWaktu(0, 0, 6, 0);
    wS3 = buatWaktu(0, 0, 6, 0);
    wS4 = buatWaktu(0, 0, 7, 0);
    wS5 = buatWaktu(0, 0, 7, 0);
    wS6 = buatWaktu(0, 0, 8, 0);

    AksiLokasi aL1, aL2, aL3, aL4, aL5, aL6;
    Teks namaM1, idTM1, idUM1, aLT1;
    Teks namaM2, idTM2, idUM2, aLT2;
    Teks namaM3, idTM3, idUM3, aLT3;
    Teks namaM4, idTM4, idUM4, aLT4;
    Teks namaM5, idTM5, idUM5, aLT5;
    Teks namaM6, idTM6, idUM6, aLT6;

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

    buatTeks("BUY", &aLT3);
    buatTeks("Tahu", &namaM3);
    buatTeks("012", &idTM3);
    buatTeks("000", &idUM3);
    buatAksiLokasi(&aL3, aLT3, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT4);
    buatTeks("Geprek", &namaM4);
    buatTeks("013", &idTM4);
    buatTeks("000", &idUM4);
    buatAksiLokasi(&aL4, aLT4, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT5);
    buatTeks("Besthal", &namaM5);
    buatTeks("014", &idTM5);
    buatTeks("000", &idUM5);
    buatAksiLokasi(&aL5, aLT5, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT6);
    buatTeks("AyNus", &namaM6);
    buatTeks("015", &idTM6);
    buatTeks("000", &idUM6);
    buatAksiLokasi(&aL6, aLT6, 2, 2, 0, 1, 5, 0);

    buatMakanan(&temp1, namaM1, idTM1, idUM1, wB1, wS1, aL1, panjang, lebar);
    buatMakanan(&temp2, namaM2, idTM2, idUM2, wB2, wS2, aL2, panjang, lebar);
    buatMakanan(&temp3, namaM3, idTM3, idUM3, wB3, wS3, aL3, panjang, lebar);
    buatMakanan(&temp4, namaM4, idTM4, idUM4, wB4, wS4, aL4, panjang, lebar);
    buatMakanan(&temp5, namaM5, idTM5, idUM5, wB5, wS5, aL5, panjang, lebar);
    buatMakanan(&temp6, namaM6, idTM6, idUM6, wB6, wS6, aL6, panjang, lebar);

    // Uji membuat queue
    buatFQKosong(&dq, 5);
    buatFQKosong(&iq, 5);

    // Enqueue delivery
    printf("DQ Awal\n");
    enqueueDelivery(&dq, temp1);
    enqueueDelivery(&dq, temp2);
    enqueueDelivery(&dq, temp3);
    enqueueDelivery(&dq, temp4);
    enqueueDelivery(&dq, temp5);
    enqueueDelivery(&dq, temp6);

    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ Awal\n");
    cetakFoodQueue(iq);
    printf("\n\n");

    Waktu wOffset = buatWaktu(0, 0, 10, 0);
    majukanWFQ(&dq, &iq, wOffset);

    // Enqueue delivery
    printf("DQ After\n");
    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ After\n");
    cetakFoodQueue(iq);
    printf("\n\n");
}

void tC2()
{
    printf("TEST CASE 2\n\n");
    FoodQueue dq, iq;
    Makanan temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
    Waktu wB1, wB2, wB3, wB4, wB5, wB6, wB7, wB8, wB9;
    Waktu wS1, wS2, wS3, wS4, wS5, wS6, wS7, wS8, wS9;
    int panjang = 6;
    int lebar = 4;
    wB1 = buatWaktu(0, 0, 5, 0);
    wB2 = buatWaktu(0, 0, 6, 0);
    wB3 = buatWaktu(0, 0, 7, 0);
    wB4 = buatWaktu(0, 0, 9, 0);
    wB5 = buatWaktu(0, 0, 10, 0);
    wB6 = buatWaktu(0, 0, 10, 0);
    wB7 = buatWaktu(0, 0, 10, 0);
    wB8 = buatWaktu(0, 0, 1, 0);

    wS1 = buatWaktu(0, 0, 0, 0);
    wS2 = buatWaktu(0, 0, 0, 0);
    wS3 = buatWaktu(0, 0, 0, 0);
    wS4 = buatWaktu(0, 0, 0, 0);
    wS5 = buatWaktu(0, 0, 0, 0);
    wS6 = buatWaktu(0, 0, 5, 0);
    wS7 = buatWaktu(0, 0, 7, 0);
    wS8 = buatWaktu(0, 0, 9, 0);

    AksiLokasi aL1, aL2, aL3, aL4, aL5, aL6, aL7, aL8, aL9;
    Teks namaM1, idTM1, idUM1, aLT1;
    Teks namaM2, idTM2, idUM2, aLT2;
    Teks namaM3, idTM3, idUM3, aLT3;
    Teks namaM4, idTM4, idUM4, aLT4;
    Teks namaM5, idTM5, idUM5, aLT5;
    Teks namaM6, idTM6, idUM6, aLT6;
    Teks namaM7, idTM7, idUM7, aLT7;
    Teks namaM8, idTM8, idUM8, aLT8;

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

    buatTeks("BUY", &aLT3);
    buatTeks("Tahu", &namaM3);
    buatTeks("012", &idTM3);
    buatTeks("000", &idUM3);
    buatAksiLokasi(&aL3, aLT3, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT4);
    buatTeks("Geprek", &namaM4);
    buatTeks("013", &idTM4);
    buatTeks("000", &idUM4);
    buatAksiLokasi(&aL4, aLT4, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT5);
    buatTeks("Besthal", &namaM5);
    buatTeks("014", &idTM5);
    buatTeks("000", &idUM5);
    buatAksiLokasi(&aL5, aLT5, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT6);
    buatTeks("AyNus", &namaM6);
    buatTeks("015", &idTM6);
    buatTeks("000", &idUM6);
    buatAksiLokasi(&aL6, aLT6, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT7);
    buatTeks("NasKor", &namaM7);
    buatTeks("017", &idTM7);
    buatTeks("000", &idUM7);
    buatAksiLokasi(&aL7, aLT7, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT8);
    buatTeks("Sop Iga", &namaM8);
    buatTeks("018", &idTM8);
    buatTeks("000", &idUM8);
    buatAksiLokasi(&aL8, aLT8, 2, 2, 0, 1, 5, 0);

    buatMakanan(&temp1, namaM1, idTM1, idUM1, wB1, wS1, aL1, panjang, lebar);
    buatMakanan(&temp2, namaM2, idTM2, idUM2, wB2, wS2, aL2, panjang, lebar);
    buatMakanan(&temp3, namaM3, idTM3, idUM3, wB3, wS3, aL3, panjang, lebar);
    buatMakanan(&temp4, namaM4, idTM4, idUM4, wB4, wS4, aL4, panjang, lebar);
    buatMakanan(&temp5, namaM5, idTM5, idUM5, wB5, wS5, aL5, panjang, lebar);
    buatMakanan(&temp6, namaM6, idTM6, idUM6, wB6, wS6, aL6, panjang, lebar);
    buatMakanan(&temp7, namaM7, idTM7, idUM7, wB7, wS7, aL7, panjang, lebar);
    buatMakanan(&temp8, namaM8, idTM8, idUM8, wB8, wS8, aL8, panjang, lebar);

    // Uji membuat queue
    buatFQKosong(&dq, 5);
    buatFQKosong(&iq, 5);

    // Enqueue delivery
    printf("DQ Awal\n");
    enqueueDelivery(&dq, temp6);
    enqueueDelivery(&dq, temp7);
    enqueueDelivery(&dq, temp8);

    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ Awal\n");
    enqueueDelivery(&iq, temp1);
    enqueueDelivery(&iq, temp2);
    enqueueDelivery(&iq, temp3);
    enqueueDelivery(&iq, temp4);
    enqueueDelivery(&iq, temp5);
    cetakFoodQueue(iq);
    printf("\n\n");

    Waktu wOffset = buatWaktu(0, 0, 9, 0);
    majukanWFQ(&dq, &iq, wOffset);

    // Enqueue delivery
    printf("DQ After\n");
    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ After\n");
    cetakFoodQueue(iq);
    printf("\n\n");
}

void tC3()
{
    printf("TEST CASE 3\n\n");
    FoodQueue dq, iq;
    Makanan temp1, temp2;
    Waktu wB1, wB2;
    Waktu wS1, wS2;
    int panjang = 6;
    int lebar = 4;

    wB1 = buatWaktu(0, 0, 59, 0);
    wB2 = buatWaktu(0, 0, 1, 0);

    wS1 = buatWaktu(0, 0, 1, 0);
    wS2 = buatWaktu(0, 0, 59, 0);

    AksiLokasi aL1, aL2, aL3, aL4, aL5, aL6, aL7, aL8, aL9;
    Teks namaM1, idTM1, idUM1, aLT1;
    Teks namaM2, idTM2, idUM2, aLT2;
    Teks namaM3, idTM3, idUM3, aLT3;
    Teks namaM4, idTM4, idUM4, aLT4;
    Teks namaM5, idTM5, idUM5, aLT5;
    Teks namaM6, idTM6, idUM6, aLT6;
    Teks namaM7, idTM7, idUM7, aLT7;
    Teks namaM8, idTM8, idUM8, aLT8;

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

    // Uji membuat queue
    buatFQKosong(&dq, 5);
    buatFQKosong(&iq, 5);

    // Enqueue delivery
    printf("DQ Awal\n");
    enqueueDelivery(&dq, temp1);
    enqueueDelivery(&dq, temp2);

    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ Awal\n");
    cetakFoodQueue(iq);
    printf("\n\n");

    Waktu wOffset = buatWaktu(0, 0, 59, 0);
    majukanWFQ(&dq, &iq, wOffset);

    // Enqueue delivery
    printf("DQ After\n");
    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ After\n");
    cetakFoodQueue(iq);
    printf("\n\n");
}

void tC4()
{
    printf("TEST CASE 3\n\n");
    FoodQueue dq, iq;
    Makanan temp1, temp2;
    Waktu wB1, wB2;
    Waktu wS1, wS2;
    int panjang = 6;
    int lebar = 4;

    wB1 = buatWaktu(0, 0, 58, 0);
    wB2 = buatWaktu(0, 0, 2, 0);

    wS1 = buatWaktu(0, 0, 1, 0);
    wS2 = buatWaktu(0, 0, 58, 0);

    AksiLokasi aL1, aL2;
    Teks namaM1, idTM1, idUM1, aLT1;
    Teks namaM2, idTM2, idUM2, aLT2;

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

    // Uji membuat queue
    buatFQKosong(&dq, 5);
    buatFQKosong(&iq, 5);

    // Enqueue delivery
    printf("DQ Awal\n");
    enqueueDelivery(&dq, temp1);
    enqueueDelivery(&dq, temp2);

    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ Awal\n");
    cetakFoodQueue(iq);
    printf("\n\n");

    Waktu wOffset = buatWaktu(0, 0, 58, 0);
    majukanWFQ(&dq, &iq, wOffset);

    // Enqueue delivery
    printf("DQ After\n");
    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ After\n");
    cetakFoodQueue(iq);
    printf("\n\n");
}

void tC5()
{
    printf("TEST CASE 2\n\n");
    FoodQueue dq, iq;
    Makanan temp1, temp2, temp3, temp4, temp5, temp6;
    Waktu wB1, wB2, wB3, wB4, wB5, wB6;
    Waktu wS1, wS2, wS3, wS4, wS5, wS6;
    int panjang = 6;
    int lebar = 4;
    wB1 = buatWaktu(0, 0, 50, 0);
    wB2 = buatWaktu(0, 0, 51, 0);
    wB3 = buatWaktu(0, 0, 52, 0);
    wB4 = buatWaktu(0, 0, 9, 0);
    wB5 = buatWaktu(0, 0, 11, 0);
    wB6 = buatWaktu(0, 0, 10, 0);

    wS1 = buatWaktu(0, 0, 0, 0);
    wS2 = buatWaktu(0, 0, 0, 0);
    wS3 = buatWaktu(0, 0, 0, 0);
    wS4 = buatWaktu(0, 0, 40, 0);
    wS5 = buatWaktu(0, 0, 41, 0);
    wS6 = buatWaktu(0, 0, 42, 0);

    AksiLokasi aL1, aL2, aL3, aL4, aL5, aL6;
    Teks namaM1, idTM1, idUM1, aLT1;
    Teks namaM2, idTM2, idUM2, aLT2;
    Teks namaM3, idTM3, idUM3, aLT3;
    Teks namaM4, idTM4, idUM4, aLT4;
    Teks namaM5, idTM5, idUM5, aLT5;
    Teks namaM6, idTM6, idUM6, aLT6;

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

    buatTeks("BUY", &aLT3);
    buatTeks("Tahu", &namaM3);
    buatTeks("012", &idTM3);
    buatTeks("000", &idUM3);
    buatAksiLokasi(&aL3, aLT3, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT4);
    buatTeks("Geprek", &namaM4);
    buatTeks("013", &idTM4);
    buatTeks("000", &idUM4);
    buatAksiLokasi(&aL4, aLT4, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT5);
    buatTeks("Besthal", &namaM5);
    buatTeks("014", &idTM5);
    buatTeks("000", &idUM5);
    buatAksiLokasi(&aL5, aLT5, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT6);
    buatTeks("AyNus", &namaM6);
    buatTeks("015", &idTM6);
    buatTeks("000", &idUM6);
    buatAksiLokasi(&aL6, aLT6, 2, 2, 0, 1, 5, 0);

    buatMakanan(&temp1, namaM1, idTM1, idUM1, wB1, wS1, aL1, panjang, lebar);
    buatMakanan(&temp2, namaM2, idTM2, idUM2, wB2, wS2, aL2, panjang, lebar);
    buatMakanan(&temp3, namaM3, idTM3, idUM3, wB3, wS3, aL3, panjang, lebar);
    buatMakanan(&temp4, namaM4, idTM4, idUM4, wB4, wS4, aL4, panjang, lebar);
    buatMakanan(&temp5, namaM5, idTM5, idUM5, wB5, wS5, aL5, panjang, lebar);
    buatMakanan(&temp6, namaM6, idTM6, idUM6, wB6, wS6, aL6, panjang, lebar);

    // Uji membuat queue
    buatFQKosong(&dq, 5);
    buatFQKosong(&iq, 5);

    // Enqueue delivery
    printf("DQ Awal\n");
    enqueueDelivery(&dq, temp4);
    enqueueDelivery(&dq, temp5);
    enqueueDelivery(&dq, temp6);

    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ Awal\n");
    enqueueDelivery(&iq, temp1);
    enqueueDelivery(&iq, temp2);
    enqueueDelivery(&iq, temp3);
    cetakFoodQueue(iq);
    printf("\n\n");

    Waktu wOffset = buatWaktu(0, 0, 49, 0);
    majukanWFQ(&dq, &iq, wOffset);

    // Enqueue delivery
    printf("DQ After\n");
    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ After\n");
    cetakFoodQueue(iq);
    printf("\n\n");
}

void tC6()
{
    printf("TEST CASE 6\n\n");
    FoodQueue dq, iq;
    Makanan temp1, temp2, temp3, temp4, temp5, temp6, temp7, temp8, temp9;
    Waktu wB1, wB2, wB3, wB4, wB5, wB6, wB7, wB8, wB9;
    Waktu wS1, wS2, wS3, wS4, wS5, wS6, wS7, wS8, wS9;
    int panjang = 6;
    int lebar = 4;
    wB1 = buatWaktu(0, 5, 3, 0);
    wB2 = buatWaktu(0, 6, 7, 0);
    wB3 = buatWaktu(0, 19, 2, 0);
    wB4 = buatWaktu(0, 23, 3, 0);
    wB5 = buatWaktu(0, 4, 1, 0);
    wB6 = buatWaktu(0, 2, 1, 0);
    wB7 = buatWaktu(0, 18, 1, 0);
    wB8 = buatWaktu(0, 2, 0, 0);

    wS1 = buatWaktu(0, 0, 0, 0);
    wS2 = buatWaktu(0, 0, 0, 0);
    wS3 = buatWaktu(0, 0, 0, 0);
    wS4 = buatWaktu(0, 0, 0, 0);
    wS5 = buatWaktu(0, 4, 2, 0);
    wS6 = buatWaktu(0, 2, 2, 0);
    wS7 = buatWaktu(0, 1, 0, 0);
    wS8 = buatWaktu(0, 23, 1, 0);

    AksiLokasi aL1, aL2, aL3, aL4, aL5, aL6, aL7, aL8, aL9;
    Teks namaM1, idTM1, idUM1, aLT1;
    Teks namaM2, idTM2, idUM2, aLT2;
    Teks namaM3, idTM3, idUM3, aLT3;
    Teks namaM4, idTM4, idUM4, aLT4;
    Teks namaM5, idTM5, idUM5, aLT5;
    Teks namaM6, idTM6, idUM6, aLT6;
    Teks namaM7, idTM7, idUM7, aLT7;
    Teks namaM8, idTM8, idUM8, aLT8;

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

    buatTeks("BUY", &aLT3);
    buatTeks("Tahu", &namaM3);
    buatTeks("012", &idTM3);
    buatTeks("000", &idUM3);
    buatAksiLokasi(&aL3, aLT3, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT4);
    buatTeks("Geprek", &namaM4);
    buatTeks("013", &idTM4);
    buatTeks("000", &idUM4);
    buatAksiLokasi(&aL4, aLT4, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT5);
    buatTeks("Besthal", &namaM5);
    buatTeks("014", &idTM5);
    buatTeks("000", &idUM5);
    buatAksiLokasi(&aL5, aLT5, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT6);
    buatTeks("AyNus", &namaM6);
    buatTeks("015", &idTM6);
    buatTeks("000", &idUM6);
    buatAksiLokasi(&aL6, aLT6, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT7);
    buatTeks("NasKor", &namaM7);
    buatTeks("017", &idTM7);
    buatTeks("000", &idUM7);
    buatAksiLokasi(&aL7, aLT7, 2, 2, 0, 1, 5, 0);

    buatTeks("BUY", &aLT8);
    buatTeks("Sop Iga", &namaM8);
    buatTeks("018", &idTM8);
    buatTeks("000", &idUM8);
    buatAksiLokasi(&aL8, aLT8, 2, 2, 0, 1, 5, 0);

    buatMakanan(&temp1, namaM1, idTM1, idUM1, wB1, wS1, aL1, panjang, lebar);
    buatMakanan(&temp2, namaM2, idTM2, idUM2, wB2, wS2, aL2, panjang, lebar);
    buatMakanan(&temp3, namaM3, idTM3, idUM3, wB3, wS3, aL3, panjang, lebar);
    buatMakanan(&temp4, namaM4, idTM4, idUM4, wB4, wS4, aL4, panjang, lebar);
    buatMakanan(&temp5, namaM5, idTM5, idUM5, wB5, wS5, aL5, panjang, lebar);
    buatMakanan(&temp6, namaM6, idTM6, idUM6, wB6, wS6, aL6, panjang, lebar);
    buatMakanan(&temp7, namaM7, idTM7, idUM7, wB7, wS7, aL7, panjang, lebar);
    buatMakanan(&temp8, namaM8, idTM8, idUM8, wB8, wS8, aL8, panjang, lebar);

    // Uji membuat queue
    buatFQKosong(&dq, 5);
    buatFQKosong(&iq, 5);

    // Enqueue delivery
    printf("DQ Awal\n");
    enqueueDelivery(&dq, temp5);
    enqueueDelivery(&dq, temp6);
    enqueueDelivery(&dq, temp7);
    enqueueDelivery(&dq, temp8);

    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ Awal\n");
    enqueueDelivery(&iq, temp1);
    enqueueDelivery(&iq, temp2);
    enqueueDelivery(&iq, temp3);
    enqueueDelivery(&iq, temp4);
    cetakFoodQueue(iq);
    printf("\n\n");

    Waktu wOffset = buatWaktu(0, 5, 2, 0);
    majukanWFQ(&dq, &iq, wOffset);

    // Enqueue delivery
    printf("DQ After\n");
    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ After\n");
    cetakFoodQueue(iq);
    printf("\n\n");
}

int main(int argc, char const *argv[])
{
    // tC1();
    // tC2();
    // tC3();
    // tC4();
    // tC5();
    tC6();
}