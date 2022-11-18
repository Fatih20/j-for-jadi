#include "foodQueue.h"

int main(int argc, char const *argv[])
{
    FoodQueue dq, iq;
    Makanan temp1, temp2, temp3, temp4;
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

    buatMakanan(&temp1, namaM1, idTM1, idUM1, wB1, wS1, aL1, panjang, lebar);
    buatMakanan(&temp2, namaM2, idTM2, idUM2, wB2, wS2, aL2, panjang, lebar);
    buatMakanan(&temp3, namaM3, idTM3, idUM3, wB3, wS3, aL3, panjang, lebar);
    buatMakanan(&temp4, namaM4, idTM4, idUM4, wB4, wS4, aL4, panjang, lebar);

    // Uji membuat queue
    buatFQKosong(&dq, 5);
    buatFQKosong(&iq, 5);

    // Enqueue delivery
    printf("DQ Awal\n");
    enqueueDelivery(&dq, temp1);
    enqueueDelivery(&dq, temp2);
    enqueueDelivery(&dq, temp3);
    enqueueDelivery(&dq, temp4);
    cetakFoodQueue(dq);
    printf("\n\n");

    // Enqueue inventory
    printf("IQ Awal\n");
    enqueueInventory(&iq, temp1);
    enqueueInventory(&iq, temp4);
    enqueueInventory(&iq, temp2);
    enqueueInventory(&iq, temp3);
    cetakFoodQueue(iq);
    printf("\n\n");

    NotifState nS;
    buatNotifStateR(&nS);

    Waktu wOffset = buatWaktu(0, 5, 2, 0);
    majukanWFQ(&dq, &iq, wOffset, &nS);

    majukanWDQ(&dq, &iq, wOffset, &nS);
    majukanWIQ(&iq, wOffset, &nS);
}
