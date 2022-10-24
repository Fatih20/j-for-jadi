#include "foodQueue.h"

int main(int argc, char const *argv[])
{
    FoodQueue dq, iq;
    Makanan temp1, temp2, temp3, temp4;
    buatMakanan(&temp1, "Susu", 1, 3, "010", "000");
    buatMakanan(&temp2, "Tahu", 3, 1, "012", "000");
    buatMakanan(&temp3, "Tempe", 2, 2, "011", "000");
    buatMakanan(&temp4, "Geprek", 2, 2, "013", "000");

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

    // Majukan waktu delivery
    printf("Delivery dimajukan satu\n");
    majukanWSampai(&dq, &iq);
    printf("DQ\n");
    cetakFoodQueue(dq);
    printf("\nIQ\n");
    cetakFoodQueue(iq);
    printf("\n");

    // Majukan waktu delivery
    printf("Delivery dimajukan satu\n");
    majukanWSampai(&dq, &iq);
    printf("DQ\n");
    cetakFoodQueue(dq);
    printf("\nIQ\n");
    cetakFoodQueue(iq);
    printf("\n");

    // Majukan waktu inventory
    printf("Inventory dimajukan satu\n");
    majukanWBasi(&iq);
    printf("\nIQ\n");
    cetakFoodQueue(iq);
    printf("\n");

    // Majukan waktu inventory
    printf("Inventory dimajukan satu\n");
    majukanWBasi(&iq);
    printf("\nIQ\n");
    cetakFoodQueue(iq);
}
