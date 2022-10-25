#include "foodQueue.h"

int main(int argc, char const *argv[])
{
    FoodQueue fq1, fq2;
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
    enqueueInventory(&fq2, temp4);
    enqueueInventory(&fq2, temp2);
    enqueueInventory(&fq2, temp3);
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
