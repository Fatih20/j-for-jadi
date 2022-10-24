#include "foodQueue.h"

int main(int argc, char const *argv[])
{
    FoodQueue fq1, fq2;
    Makanan temp1, temp2, temp3, temp4;
    buatMakanan(&temp1, "Susu", 1, 3, "010", "000");
    buatMakanan(&temp2, "Tahu", 3, 1, "012", "000");
    buatMakanan(&temp3, "Tempe", 2, 2, "011", "000");
    buatMakanan(&temp4, "Geprek", 2, 2, "013", "000");

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

    // // Uji Dequeue FQ1
    // printf("Tes dequeue FQ1\n");
    // FoodQueueEl tempEl1;
    // // dequeue(&fq1, &tempEl1);
    // cetakFoodQueue(fq1);
    // printf("\n");
    // cetakMakanan(tempEl1);
    // printf("\n\n");

    // // Uji Dequeue FQ2
    // printf("Tes dequeue FQ2\n");
    // FoodQueueEl tempEl2;
    // // dequeue(&fq2, &tempEl2);
    // cetakFoodQueue(fq2);
    // printf("\n");
    // cetakMakanan(tempEl2);
    // printf("\n\n");

    // Uji copyFQ
    printf("Tes copy FQ1 ke FQ3\n");
    FoodQueue fq3;
    buatFQKosong(&fq3, 1);
    copyFoodQueue(fq1, &fq3);
    cetakFoodQueue(fq3);

    // Uji remove and find by ID
    printf("Tes remove dan cari tipe dalam FQ2\n");
    FoodQueueEl tempEl3;
    printf("%d\n", idxMakanan(fq2, "014"));
    deleteByID(&fq2, "010", &tempEl3);
    cetakFoodQueue(fq2);
    return 0;
}
