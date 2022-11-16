#include "listDinNotif.h"
#include <stdio.h>
#include <stdlib.h>

void buatLDinNotif(LDinNotif *l, int capacity)
{
    notif(*l) = (LDinNtfEl *)malloc(capacity * sizeof(LDinNtfEl));
    nEffLDN(*l) = 0;
    capacityLDN(*l) = capacity;
}

void dealokasiLDinNotif(LDinNotif *l)
{
    free(notif(*l));
    capacityLDN(*l) = 0;
    nEffLDN(*l) = 0;
}

int panjangLDinNotif(LDinNotif l)
{
    return nEffLDN(l);
}

IdxType lastIdxLDinNotif(LDinNotif l)
{
    return nEffLDN(l) - 1;
}

boolean isIdxValidLDinNotif(LDinNotif l, IdxType i)
{
    return (i < capacityLDN(l) && i >= IDX_MIN);
}

boolean isIdxEffLDinNotif(LDinNotif l, IdxType i)
{
    return (i <= nEffLDN(l) && i >= IDX_MIN);
}

boolean isEmptyLDinNotif(LDinNotif l)
{
    return (nEffLDN(l) == 0);
}

boolean isFullLDinNotif(LDinNotif l)
{
    return (nEffLDN(l) == capacityLDN(l));
}

// void readLDinNotif(LDinNotif *l)
// {
//     int n, i;
//     scanf("%d", &n);
//     while (n < 0)
//     {
//         scanf("%d", &n);
//     }
//     if (n > capacityLDN(*l))
//     {
//         expandLDinNotif(l, n - capacityLDN(*l));
//     }
//     char tempString[100]; /*eats new line*/
//     nEffLDN(*l) = n;
//     for (i = IDX_MIN; i < n; i++)
//     {
//         Notif tempTeks;
//         scanf("%s", tempString);
//         buatTeks(tempString, &tempTeks);
//         elmtLDN(*l, i) = tempTeks;
//     }
// }

void printLDinNotif(LDinNotif l)
{
    Teks notifT;
    buatTeks("Notifikasi: ", &notifT);
    cetakTeks(notifT, 'y');
    if (!isEmptyLDinNotif(l))
    {
        printf("\n");
        for (int i = IDX_MIN; i < panjangLDinNotif(l); i++)
        {
            printf("%d. ", i + 1);
            cetakNotif(elmtLDN(l, i));
            printf("\n");
        }
    }
    else
    {
        printf("-\n");
    }
}

void copyLDinNotif(LDinNotif lIn, LDinNotif *lOut)
{
    buatLDinNotif(lOut, capacityLDN(lIn));
    for (int i = IDX_MIN; i < panjangLDinNotif(lIn); i++)
    {
        elmtLDN(*lOut, i) = elmtLDN(lIn, i);
    }
    nEffLDN(*lOut) = nEffLDN(lIn);
    capacityLDN(*lOut) = capacityLDN(lIn);
}

void removeFirstLDinNotif(LDinNotif *l, LDinNtfEl *val)
{
    removeAtLDinNotif(l, val, 0);
};

void removeAtLDinNotif(LDinNotif *l, LDinNtfEl *val, IdxType idx)
{
    *val = elmtLDN(*l, idx);
    for (int i = idx; i < panjangLDinNotif(*l) - 1; i++)
    {
        elmtLDN(*l, i) = elmtLDN(*l, i + 1);
    }
    nEffLDN(*l) -= 1;
}

void removeLastLDinNotif(LDinNotif *l, LDinNtfEl *val)
{
    removeAtLDinNotif(l, val, panjangLDinNotif(*l) - 1);
};

void insertFirstLDinNotif(LDinNotif *l, LDinNtfEl val)
{
    insertAtLDinNotif(l, val, 0);
}

void insertLastLDinNotif(LDinNotif *l, LDinNtfEl val)
{
    insertAtLDinNotif(l, val, nEffLDN(*l));
}

void insertAtLDinNotif(LDinNotif *l, LDinNtfEl val, IdxType idx)
{
    if (isFullLDinNotif(*l))
    {
        expandLDinNotif(l, 1);
    }
    nEffLDN(*l) += 1;
    if (isIdxEffLDinNotif(*l, idx))
    {
        for (int i = lastIdxLDinNotif(*l); i > idx; i--)
        {
            elmtLDN(*l, i) = elmtLDN(*l, i - 1);
        }
        elmtLDN(*l, idx) = val;
    }
    else
    {
        printf("idx tidak efektif!\n");
    }
}

void insertFirstLDinNotifRaw(LDinNotif *l, char kode, Teks subject)
{
    Notif nTFToAdd;
    buatNotif(kode, subject, &nTFToAdd);
    insertFirstLDinNotif(l, nTFToAdd);
};

void insertLastLDinNotifRaw(LDinNotif *l, char kode, Teks subject)
{
    Notif nTFToAdd;
    buatNotif(kode, subject, &nTFToAdd);
    insertLastLDinNotif(l, nTFToAdd);
};

void insertAtLDinNotifRaw(LDinNotif *l, char kode, Teks subject, int idx)
{
    Notif nTFToAdd;
    buatNotif(kode, subject, &nTFToAdd);
    insertAtLDinNotif(l, nTFToAdd, idx);
};

void expandLDinNotif(LDinNotif *l, int num)
{
    capacityLDN(*l) += num;
    notif(*l) = realloc(notif(*l), (capacityLDN(*l)) * sizeof(LDinNtfEl));
}