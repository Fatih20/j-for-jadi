#include <stdio.h>
#include "simulator.h"

void buatSimulator(Simulator *S, Teks userName, int x, int y, int HH, int JJ, int MM, int DD, FoodQueue inventory, FoodQueue delivery, Kulkas kulkas)
{
    FoodQueue inventoryBaru;
    copyFoodQueue(inventory, &inventoryBaru);
    inventorySimulator(*S) = inventoryBaru;
    FoodQueue deliveryBaru;
    copyFoodQueue(delivery, &deliveryBaru);
    deliverySimulator(*S) = deliveryBaru;
    POINT posisi;
    Absis(posisi) = x;
    Ordinat(posisi) = y;
    posisiSimulator(*S) = posisi;
    waktuSimulator(*S) = buatWaktu(HH, JJ, MM, DD);
    NotifState notifState;
    LDinNotif notifStateF;
    buatLDinNotif(&notifStateF, 5);
    LDinNotif notifStateB;
    buatLDinNotif(&notifStateB, 5);
    buatNotifState(&notifState, notifStateF, notifStateB);
    notifSimulator(*S) = notifState;
    kulkasSimulator(*S) = kulkas;
}

void cetakSimulator(Simulator S)
{
    printf("State saat ini:\n");
    printf("Posisi: ");
    TulisPOINT(posisiSimulator(S));
    printf("\nWaktu : ");
    tulisWaktu(waktuSimulator(S));
    printf("\nInventory:\n");
    cetakFoodQueue(inventorySimulator(S));
    printf("\n");
    printf("\nDelivery:\n");
    cetakFoodQueue(deliverySimulator(S));
    printf("\n");
}

void copySimulator(Simulator SIn, Simulator *SOut)
{
    FoodQueue inventorySalinan;
    FoodQueue deliverySalinan;
    POINT posisiSalinan;
    Kulkas kulkasSalinan;
    NotifState notifSSalinan;
    int HH, JJ, MM, DD;

    userNameSimulator(*SOut) = userNameSimulator(SIn);
    copyFoodQueue(inventorySimulator(SIn), &inventorySalinan);
    inventorySimulator(*SOut) = inventorySalinan;
    copyFoodQueue(deliverySimulator(SIn), &deliverySalinan);
    deliverySimulator(*SOut) = deliverySalinan;
    CreatePoint(&posisiSalinan, Absis(posisiSimulator(SIn)), Ordinat(posisiSimulator(SIn)));
    posisiSimulator(*SOut) = posisiSalinan;
    HH = Hari(waktuSimulator(SIn));
    JJ = Jam(waktuSimulator(SIn));
    MM = Menit(waktuSimulator(SIn));
    DD = Detik(waktuSimulator(SIn));
    copyNotifState(notifSimulator(SIn), &notifSSalinan);
    notifSimulator(*SOut) = notifSSalinan;

    waktuSimulator(*SOut) = buatWaktu(HH, JJ, MM, DD);
}

void majukanWaktuSimulator(Simulator *S, Waktu waktu, NotifState *nS)
{
    // Memajukan waktuState
    long detik;
    detik = waktuToDetik(waktu);
    waktuSimulator(*S) = nextNDetik(waktuSimulator(*S), detik);
    // Majukan waktu
    majukanWFQ(&deliverySimulator(*S), &inventorySimulator(*S), waktu, nS);
}

void tambahNotifF(char kode, Teks subject, Simulator *simulator)
{
    Notif addedNotif;
    buatNotif(kode, subject, &addedNotif);
    insertLastLDinNotif(&(forNS(notifSimulator(*simulator))), addedNotif);
}

void tambahNotifB(char kode, Teks subject, Simulator *simulator)
{
    Notif addedNotif;
    buatNotif(kode, subject, &addedNotif);
    insertLastLDinNotif(&(backNS(notifSimulator(*simulator))), addedNotif);
};
