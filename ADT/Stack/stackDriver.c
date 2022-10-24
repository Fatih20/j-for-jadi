#include <stdio.h>
#include "stack.h"

int main()
{
    Stack SState;
    State state;
    POINT lokasi;
    Absis(lokasi) = 4;
    Ordinat(lokasi) = 5;
    int waktu = 100;
    FoodQueue inventory;
    Makanan temp1, temp2, temp3, temp4;
    buatMakanan(&temp1, "Susu", 1, 3, "010", "000");
    buatMakanan(&temp2, "Tahu", 3, 1, "012", "000");
    buatMakanan(&temp3, "Tempe", 2, 2, "011", "000");
    buatMakanan(&temp4, "Geprek", 2, 2, "013", "000");

    // Uji membuat queue
    buatFQKosong(&inventory, 5);

    // Inisialisasi Stack Kosong
    CreateEmptyStack(&SState, 10);

    printf("IsEmpty: %d\n", IsEmptyStack(SState));
    // Uji print tiap enqueue inventory baru
    printf("Tes enqueue delivery\n\n");
    enqueueDelivery(&inventory, temp1);
    buatState(&state, lokasi, waktu, inventory);
    Push(&SState, state);
    cetakState(state);
    printf("IsFull: %d\n", IsFullStack(SState));
    printf("IsEmpty: %d\n", IsEmptyStack(SState));

    enqueueDelivery(&inventory, temp2);
    buatState(&state, lokasi, waktu, inventory);
    cetakState(state);
    Push(&SState, state);
    printf("IsFull: %d\n", IsFullStack(SState));
    printf("IsEmpty: %d\n", IsEmptyStack(SState));

    shrinkStack(&SState, 7);
    enqueueDelivery(&inventory, temp3);
    buatState(&state, lokasi, waktu, inventory);
    cetakState(state);
    Push(&SState, state);
    printf("IsFull: %d\n", IsFullStack(SState));
    printf("IsEmpty: %d\n", IsEmptyStack(SState));

    expandStack(&SState, 2);
    enqueueDelivery(&inventory, temp4);
    buatState(&state, lokasi, waktu, inventory);
    cetakState(state);
    Push(&SState, state);
    printf("IsFull: %d\n", IsFullStack(SState));
    printf("IsEmpty: %d\n", IsEmptyStack(SState));

    shrinkStack(&SState, 1);
    printf("IsFull: %d\n", IsFullStack(SState));
    printf("IsEmpty: %d\n", IsEmptyStack(SState));

    Pop(&SState, &state);
    printf("IsFull: %d\n", IsFullStack(SState));
    printf("IsEmpty: %d\n", IsEmptyStack(SState));
}

/*
gcc -o main ADT\State\stateDriver.c ADT\State\state.c ADT\FoodQueue\foodQueue.c ADT\ListDinMakanan\ldinmakanan.c ADT\Makanan\makanan.c ADT\Point\Point.c ADT\Teks\teks.c
*/