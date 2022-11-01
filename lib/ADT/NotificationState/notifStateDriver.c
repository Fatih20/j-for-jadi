#include "notificationState.h"

int main(int argc, char const *argv[])
{
    LDinNotif lf, lb, ltemp;
    LDinNtfEl teks1, teks2;
    buatLDinNotif(&lf, 5);
    buatLDinNotif(&lb, 5);

    Notif n1;
    Teks nT1;
    buatTeks("Bawang", &nT1);
    buatNotif('e', nT1, &n1);

    Notif n2;
    Teks nT2;
    buatTeks("Ayam Goreng", &nT2);
    buatNotif('p', nT2, &n2);

    Notif n3;
    Teks nT3;
    buatTeks("Besthal", &nT3);
    buatNotif('c', nT3, &n3);

    Notif n4;
    Teks nT4;
    buatTeks("AyNus", &nT4);
    buatNotif('d', nT4, &n4);

    insertLastLDinNotif(&lf, n1);
    insertLastLDinNotif(&lf, n2);

    insertLastLDinNotif(&lb, n3);
    insertLastLDinNotif(&lb, n4);

    NotifState ns;
    forNS(ns) = lf;
    forNS(ns) = lb;

    /* code */
    return 0;
}