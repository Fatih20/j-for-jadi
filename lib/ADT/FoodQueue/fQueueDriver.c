#include "foodQueue.h"
#include "../AksiLokasi/aksiLokasi.h"

int main(int argc, char const *argv[])
{
    FoodQueue fq1, fq2;
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

    cetakMakanan(temp1);
    // Uji membuat queue
    buatFQKosong(&fq1, 5);
    buatFQKosong(&fq2, 5);

    // Uji enqueue delivery
    printf("Tes enqueue delivery\n\n");
    enqueueDelivery(&fq1, temp1);
    enqueueDelivery(&fq1, temp2);
    enqueueDelivery(&fq1, temp3);
    enqueueDelivery(&fq1, temp4);
    cetakFoodQueue(fq1);
    printf("\n\n");

    // Uji enqueue inventory
    printf("Tes enqueue inventory\n");
    enqueueInventory(&fq2, temp1);
    enqueueInventory(&fq2, temp2);
    enqueueInventory(&fq2, temp3);
    enqueueInventory(&fq2, temp4);
    cetakFoodQueue(fq2);
    printf("\n\n");

    // Uji Dequeue FQ1
    printf("Tes dequeue FQ1\n");
    FoodQueueEl tempEl1;
    dequeue(&fq1, &tempEl1);
    cetakFoodQueue(fq1);
    printf("\n");
    cetakMakanan(tempEl1);
    printf("\n\n");

    // Uji Dequeue FQ2
    printf("Tes dequeue FQ2\n");
    FoodQueueEl tempEl2;
    dequeue(&fq2, &tempEl2);
    cetakFoodQueue(fq2);
    printf("\n");
    cetakMakanan(tempEl2);
    printf("\n\n");

    // Uji copyFQ
    printf("Tes copy FQ1 ke FQ3\n");
    FoodQueue fq3;
    buatFQKosong(&fq3, 1);
    copyFoodQueue(fq1, &fq3);
    cetakFoodQueue(fq3);
    printf("\n\n");

    // Uji remove and find by ID
    printf("Tes remove dan cari tipe dalam FQ2\n");
    FoodQueueEl tempEl3;
    printf("%d\n", idxMakanan(fq2, "014"));
    deleteByIdTipe(&fq2, "010", &tempEl3);
    cetakFoodQueue(fq2);
    printf("\n\n");
    return 0;
}
