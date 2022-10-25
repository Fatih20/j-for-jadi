#include <stdio.h>
#include "state.h"

int main()
{
    State state;
    int absis = 4;
    int ordinat = 5;
    FoodQueue inventory;
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
    buatFQKosong(&inventory, 5);

    // Uji print tiap enqueue inventory baru
    printf("Tes enqueue delivery\n\n");
    enqueueDelivery(&inventory, temp1);
    buatState(&state, absis, ordinat, 0, 0, 10, 0, inventory);
    cetakState(state);
    enqueueDelivery(&inventory, temp2);
    buatState(&state, absis, ordinat, 0, 0, 15, 0, inventory);
    cetakState(state);
    enqueueDelivery(&inventory, temp3);
    buatState(&state, absis, ordinat, 0, 0, 20, 0, inventory);
    cetakState(state);
    enqueueDelivery(&inventory, temp4);
    buatState(&state, absis, ordinat, 0, 0, 25, 0, inventory);
    cetakState(state);
}

/*
gcc -o main ADT\State\stateDriver.c ADT\State\state.c ADT\FoodQueue\foodQueue.c ADT\ListDinMakanan\ldinmakanan.c ADT\Makanan\makanan.c ADT\Point\Point.c ADT\Teks\teks.c ADT\ListDinKar\ldinkar.c ADT\Waktu\waktu.c
*/