#include <stdio.h>
#include "simulator.h"

int main()
{
    Simulator simulator;
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

    // buatMakanan(&temp1, namaM1, idTM1, idUM1, wB1, wS1, aL1);
    // buatMakanan(&temp2, namaM2, idTM2, idUM2, wB2, wS2, aL2);
    // buatMakanan(&temp3, namaM3, idTM3, idUM3, wB3, wS3, aL3);
    // buatMakanan(&temp4, namaM4, idTM4, idUM4, wB4, wS4, aL4);

    // Uji membuat queue
    buatFQKosong(&inventory, 5);

    // Uji print tiap enqueue inventory baru
    // printf("Tes enqueue delivery\n\n");
    // enqueueDelivery(&inventory, temp1);
    // buatSimulator(&simulator, absis, ordinat, 0, 0, 10, 0, inventory);
    // cetakSimulator(simulator);
    // enqueueDelivery(&inventory, temp2);
    // buatSimulator(&simulator, absis, ordinat, 0, 0, 15, 0, inventory);
    // cetakSimulator(simulator);
    // enqueueDelivery(&inventory, temp3);
    // buatSimulator(&simulator, absis, ordinat, 0, 0, 20, 0, inventory);
    // cetakSimulator(simulator);
    // enqueueDelivery(&inventory, temp4);
    // buatSimulator(&simulator, absis, ordinat, 0, 0, 25, 0, inventory);
    // cetakSimulator(simulator);
}

/*
gcc -o main ADT\State\stateDriver.c ADT\State\state.c ADT\FoodQueue\foodQueue.c ADT\ListDinMakanan\ldinmakanan.c ADT\Makanan\makanan.c ADT\Point\Point.c ADT\Teks\teks.c ADT\ListDinKar\ldinkar.c ADT\Waktu\waktu.c
*/