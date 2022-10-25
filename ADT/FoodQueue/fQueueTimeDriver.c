#include "foodQueue.h"

int main(int argc, char const *argv[])
{
    FoodQueue dq, iq;
    Makanan temp1, temp2, temp3, temp4;
    Waktu wB1, wB2, wB3, wB4, wS1, wS2, wS3, wS4;
    wB1 = buatWaktu(0, 0, 3, 0);
    wB2 = buatWaktu(0, 0, 2, 0);
    wB3 = buatWaktu(0, 0, 2, 0);
    wB4 = buatWaktu(0, 0, 1, 0);

    wS1 = buatWaktu(0, 0, 1, 0);
    wS2 = buatWaktu(0, 0, 2, 0);
    wS3 = buatWaktu(0, 0, 2, 0);
    wS4 = buatWaktu(0, 0, 3, 0);

    buatMakanan(&temp1, "Susu", "010", "000", wB1, wS1);
    buatMakanan(&temp2, "Tahu", "012", "000", wB2, wS2);
    buatMakanan(&temp3, "Tempe", "011", "000", wB3, wS3);
    buatMakanan(&temp4, "Geprek", "013", "000", wB4, wS4);

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

    // // Majukan waktu delivery
    // printf("Delivery dimajukan satu\n");
    // majukanWSampai(&dq, &iq);
    // printf("DQ\n");
    // cetakFoodQueue(dq);
    // printf("\nIQ\n");
    // cetakFoodQueue(iq);
    // printf("\n");

    // // Majukan waktu delivery
    // printf("Delivery dimajukan satu\n");
    // majukanWSampai(&dq, &iq);
    // printf("DQ\n");
    // cetakFoodQueue(dq);
    // printf("\nIQ\n");
    // cetakFoodQueue(iq);
    // printf("\n");

    // // Majukan waktu inventory
    // printf("Inventory dimajukan satu\n");
    // majukanWBasi(&iq);
    // printf("\nIQ\n");
    // cetakFoodQueue(iq);
    // printf("\n");

    // // Majukan waktu inventory
    // printf("Inventory dimajukan satu\n");
    // majukanWBasi(&iq);
    // printf("\nIQ\n");
    // cetakFoodQueue(iq);

    // Majukan waktu semua
    printf("\nWaktu dimajukan satu\n");
    majukanWFQ(&dq, &iq);
    printf("\nDQ\n");
    cetakFoodQueue(dq);
    printf("\nIQ\n");
    cetakFoodQueue(iq);

    // Majukan waktu semua
    printf("\nWaktu dimajukan satu\n");
    majukanWFQ(&dq, &iq);
    printf("\nDQ\n");
    cetakFoodQueue(dq);
    printf("\nIQ\n");
    cetakFoodQueue(iq);

    // Majukan waktu semua
    printf("\nWaktu dimajukan satu\n");
    majukanWFQ(&dq, &iq);
    printf("\nDQ\n");
    cetakFoodQueue(dq);
    printf("\nIQ\n");
    cetakFoodQueue(iq);
}
