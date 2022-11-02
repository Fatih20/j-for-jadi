#include <stdio.h>
#include "state.h"

void buatState(State *S, int x, int y, int HH, int JJ, int MM, int DD, FoodQueue inventory, FoodQueue delivery)
{
    FoodQueue inventoryBaru;
    copyFoodQueue(inventory, &inventoryBaru);
    inventoryState(*S) = inventoryBaru;
    FoodQueue deliveryBaru;
    copyFoodQueue(delivery, &deliveryBaru);
    deliveryState(*S) = deliveryBaru;
    POINT posisi;
    Absis(posisi) = x;
    Ordinat(posisi) = y;
    posisiState(*S) = posisi;
    waktuState(*S) = buatWaktu(HH, JJ, MM, DD);
    NotifState notifState;
    LDinNotif notifStateF;
    buatLDinNotif(&notifStateF, 5);
    LDinNotif notifStateB;
    buatLDinNotif(&notifStateB, 5);
    buatNotifState(&notifState, notifStateF, notifStateB);
    notifS(*S) = notifState;
}

void cetakState(State S)
{
    printf("State saat ini:\n");
    printf("Posisi: ");
    TulisPOINT(posisiState(S));
    printf("\nWaktu : ");
    tulisWaktu(waktuState(S));
    printf("\nInventory:\n");
    cetakFoodQueue(inventoryState(S));
    printf("\n");
    printf("\nDelivery:\n");
    cetakFoodQueue(deliveryState(S));
    printf("\n");
}

void copyState(State SIn, State *SOut)
{
    FoodQueue inventorySalinan;
    FoodQueue deliverySalinan;
    POINT posisi;
    NotifState notifSSalinan;
    int HH, JJ, MM, DD;
    copyFoodQueue(inventoryState(SIn), &inventorySalinan);
    inventoryState(*SOut) = inventorySalinan;
    copyFoodQueue(deliveryState(SIn), &deliverySalinan);
    deliveryState(*SOut) = deliverySalinan;
    CreatePoint(&posisi, Absis(posisiState(SIn)), Ordinat(posisiState(SIn)));
    posisiState(*SOut) = posisi;
    HH = Hari(waktuState(SIn));
    JJ = Jam(waktuState(SIn));
    MM = Menit(waktuState(SIn));
    DD = Detik(waktuState(SIn));
    copyNotifState(notifS(SIn), &notifSSalinan);
    notifS(*SOut) = notifSSalinan;

    waktuState(*SOut) = buatWaktu(HH, JJ, MM, DD);
}

void majukanWaktuState(State *S, Waktu waktu)
{
    // Memajukan waktuState
    long detik;
    detik = waktuToDetik(waktu);
    waktuState(*S) = nextNDetik(waktuState(*S), detik);
    // Memajukan waktu di inventoryState
    majukanWIQ(&inventoryState(*S), waktu);
    // Memajukan waktu di deliveryState
    majukanWDQ(&deliveryState(*S), &inventoryState(*S), waktu);
}

void tambahNotifF(char kode, Teks subject, State *state)
{
    Notif addedNotif;
    buatNotif(kode, subject, &addedNotif);
    insertLastLDinNotif(&(forNS(notifS(*state))), addedNotif);
}

void tambahNotifB(char kode, Teks subject, State *state)
{
    Notif addedNotif;
    buatNotif(kode, subject, &addedNotif);
    insertLastLDinNotif(&(backNS(notifS(*state))), addedNotif);
};
