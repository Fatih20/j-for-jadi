#include "listDinNotif.h"
#include <stdio.h>
#include <string.h>

int main()
{
    LDinNotif l, ltemp;
    char temp1[] = "temp1";
    char temp2[] = "temp2";
    LDinNtfEl teks1, teks2;
    buatLDinNotif(&l, 5);
    // readLDinNotif(&l);
    printLDinNotif(l);

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
    /* Uji insertFirstLDinNotif*/
    printf("*****Insert First*****\n");
    insertFirstLDinNotif(&l, n1);
    printLDinNotif(l);
    /* UJI insertAtLDinNotif */
    printf("*****Insert At*****\n");
    insertAtLDinNotif(&l, n2, 0);
    printLDinNotif(l);
    /* UJI insertLastLDinNotif */
    printf("*****Insert Last*****\n");
    insertLastLDinNotif(&l, n3);
    printLDinNotif(l);

    /* UJI copyLDinNotif*/
    printf("*****Copy*****\n");
    copyLDinNotif(l, &ltemp);
    printf("*****Copied List*****\n");
    printLDinNotif(ltemp);

    /* UJI removeFirst */
    printf("****First Element Removed*****\n");
    Notif val;
    removeFirstLDinNotif(&l, &val);
    printLDinNotif(l);

    /* UJI removeLast */
    printf("****Last Element Removed*****\n");
    removeLastLDinNotif(&l, &val);
    printLDinNotif(l);

    printf("****Element at Idx 1 Removed*****\n");
    removeAtLDinNotif(&l, &val, 1);
    printLDinNotif(l);
    dealokasiLDinNotif(&l);
    dealokasiLDinNotif(&ltemp);
}