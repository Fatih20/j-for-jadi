#include <stdio.h>
#include "simulator.h"

int main()
{
    printf("Tes print simulator\n\n");
    Simulator simmmp;
    Teks userName;
    int x = 6;
    int y = 9;
    FoodQueue inventory;
    Makanan temp1, temp2, temp3, temp4;

    buatTeks("FadhilAmri", &userName);
    buatMakanan(&temp1, "Susu", 1, 3, "010", "000");
    buatMakanan(&temp2, "Tahu", 3, 1, "012", "000");
    buatMakanan(&temp3, "Tempe", 2, 2, "011", "000");
    buatMakanan(&temp4, "Geprek", 2, 2, "013", "000");

    // Uji membuat queue
    buatFQKosong(&inventory, 5);

    // Mengisi inventory
    enqueueDelivery(&inventory, temp1);
    enqueueDelivery(&inventory, temp2);
    enqueueDelivery(&inventory, temp3);
    enqueueDelivery(&inventory, temp4);

    buatSimulator(&simmmp, userName, x, y, inventory);
    cetakSimulator(simmmp);
}

// gcc -o main ADT\Simulator\sDriver.c ADT\Simulator\simulator.c ADT\Teks\teks.c ADT\boolean.h ADT\Point\Point.c ADT\Makanan\makanan.c ADT\FoodQueue\foodQueue.c ADT\ListDinMakanan\ldinmakanan.c