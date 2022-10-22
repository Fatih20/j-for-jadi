#include "deliveryQueue.h"

int main(int argc, char const *argv[])
{
    DeliveryQueue dq1;
    Makanan temp1, temp2, temp3;
    buatMakanan(&temp1, "Susu", 2, 3, "010", "000");
    buatMakanan(&temp2, "Tahu", 2, 1, "012", "000");
    buatMakanan(&temp3, "Tempe", 2, 2, "011", "000");

    // Uji membuat queue
    buatDQKosong(&dq1, 5);
    cetakDeliveryQueue(dq1);

    // Uji enqueue
    printf("Tes enqueue\n");
    enqueue(&dq1, temp1);
    enqueue(&dq1, temp2);
    enqueue(&dq1, temp3);

    cetakDeliveryQueue(dq1);
    printf("\n");

    // Uji Dequeue
    printf("Tes dequeue\n");
    DeliveryQueueEl tempEl1;
    dequeue(&dq1, &tempEl1);
    dequeue(&dq1, &tempEl1);
    dequeue(&dq1, &tempEl1);
    cetakDeliveryQueue(dq1);
    printf("\n");

    return 0;
}
