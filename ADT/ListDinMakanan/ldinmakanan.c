#include "ldinmakanan.h"
#include <stdio.h>
#include <stdlib.h>

void buatLDinMakanan(LDinMakanan *l, int capacity)
{
    makanan(*l) = (LDinMakananEl *)malloc(capacity * sizeof(LDinMakananEl));
    nEffLDM(*l) = 0;
    capacityLDM(*l) = capacity;
}

void dealokasiLDinMakanan(LDinMakanan *l)
{
    free(makanan(*l));
    capacityLDM(*l) = 0;
    nEffLDM(*l) = 0;
}

int panjangLDinMakanan(LDinMakanan l)
{
    return nEffLDM(l);
}

IdxType lastIdxLDinMakanan(LDinMakanan l)
{
    return nEffLDM(l) - 1;
}

boolean isIdxValidLDinMakanan(LDinMakanan l, IdxType i)
{
    return (i < capacityLDM(l) && i >= IDX_MIN);
}

boolean isIdxEffLDinMakanan(LDinMakanan l, IdxType i)
{
    return (i <= nEffLDM(l) && i >= IDX_MIN);
}

boolean isEmptyLDinMakanan(LDinMakanan l)
{
    return (nEffLDM(l) == 0);
}

boolean isFullLDinMakanan(LDinMakanan l)
{
    return (nEffLDM(l) == capacityLDM(l));
}

void readLDinMakanan(LDinMakanan *l)
{
    int n, i = IDX_MIN;
    scanf("%d", &n);
    while (n < 0)
    {
        scanf("%d", &n);
    }
    if (n > capacityLDM(*l))
    {
        expandLDinMakanan(l, n - capacityLDM(*l));
    }
    nEffLDM(*l) = n;
    for (i; i < n; i++)
    {
        Makanan temp;
        char idMakanan[100];
        char namaMakanan[100];
        int waktuKadaluarsa, lamaPengiriman;
        printf("Masukkan ID makanan: ");
        scanf("%s", &idMakanan);
        printf("Masukkan nama makanan: ");
        scanf("%s", &namaMakanan);
        printf("Masukkan waktu kadaluarsa: ");
        scanf("%d", &waktuKadaluarsa);
        printf("Masukkan lama pengiriman: ");
        scanf("%d", &lamaPengiriman);
        buatMakanan(&temp, namaMakanan, waktuKadaluarsa, lamaPengiriman, idMakanan, idMakanan);
        elmtLDM(*l, i) = temp;
    }
}

void printLDinMakanan(LDinMakanan l)
{
    if (!isEmptyLDinMakanan(l))
    {
        for (int i = IDX_MIN; i < panjangLDinMakanan(l); i++)
        {
            cetakMakanan(elmtLDM(l, i));
        }
    }
}

void copyLDinMakanan(LDinMakanan lIn, LDinMakanan *lOut)
{
    buatLDinMakanan(lOut, capacityLDM(lIn));
    for (int i = IDX_MIN; i < panjangLDinMakanan(lIn); i++)
    {
        elmtLDM(*lOut, i) = elmtLDM(lIn, i);
    }
    nEffLDM(*lOut) = nEffLDM(lIn);
    capacityLDM(*lOut) = capacityLDM(lIn);
}

void removeFirstLDinMakanan(LDinMakanan *l, LDinMakananEl *X)
{
    *X = elmtLDM(*l, 0);
    int i = 0;
    int lastIndex = lastIdxLDinMakanan(*l);
    for (int i = 0; i <= lastIndex - 1; i++)
    {
        elmtLDM(*l, i) = elmtLDM(*l, i + 1);
    }
    nEffLDM(*l)--;
};

void removeAtLDinMakanan(LDinMakanan *l, LDinMakananEl *val, IdxType idx)
{
    *val = elmtLDM(*l, idx);
    for (int i = idx; i < panjangLDinMakanan(*l) - 1; i++)
    {
        elmtLDM(*l, i) = elmtLDM(*l, i + 1);
    }
    nEffLDM(*l) -= 1;
}

void removeLastLDinMakanan(LDinMakanan *l, LDinMakananEl *val)
{
    removeAtLDinMakanan(l, val, panjangLDinMakanan(*l) - 1);
};

void insertFirstLDinMakanan(LDinMakanan *l, LDinMakananEl val)
{
    insertAtLDinMakanan(l, val, 0);
}

void insertLastLDinMakanan(LDinMakanan *l, LDinMakananEl val)
{
    insertAtLDinMakanan(l, val, nEffLDM(*l));
}

void insertAtLDinMakanan(LDinMakanan *l, LDinMakananEl val, IdxType idx)
{
    if (isFullLDinMakanan(*l))
    {
        expandLDinMakanan(l, 1);
    }
    nEffLDM(*l) += 1;
    if (isIdxEffLDinMakanan(*l, idx))
    {
        for (int i = lastIdxLDinMakanan(*l); i > idx; i--)
        {
            elmtLDM(*l, i) = elmtLDM(*l, i - 1);
        }
        elmtLDM(*l, idx) = val;
    }
    else
    {
        printf("idx tidak efektif!\n");
    }
}

void expandLDinMakanan(LDinMakanan *l, int num)
{
    capacityLDM(*l) += num;
    makanan(*l) = realloc(makanan(*l), (capacityLDM(*l)) * sizeof(LDinMakananEl));
}