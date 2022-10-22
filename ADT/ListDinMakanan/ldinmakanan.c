#include "ldinmakanan.h"
#include <stdio.h>
#include <stdlib.h>

void buatLDinMakanan(LDinMakanan *l, int capacity)
{
    MAKANAN(*l) = (LDinMakananEl *)malloc(capacity * sizeof(LDinMakananEl));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealokasiLDinMakanan(LDinMakanan *l)
{
    free(MAKANAN(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int panjangLDinMakanan(LDinMakanan l)
{
    return NEFF(l);
}

IdxType lastIdxLDinMakanan(LDinMakanan l)
{
    return NEFF(l) - 1;
}

boolean isIdxValidLDinMakanan(LDinMakanan l, IdxType i)
{
    return (i < CAPACITY(l) && i >= IDX_MIN);
}

boolean isIdxEffLDinMakanan(LDinMakanan l, IdxType i)
{
    return (i <= NEFF(l) && i >= IDX_MIN);
}

boolean isEmptyLDinMakanan(LDinMakanan l)
{
    return (NEFF(l) == 0);
}

boolean isFullLDinMakanan(LDinMakanan l)
{
    return (NEFF(l) == CAPACITY(l));
}

void readLDinMakanan(LDinMakanan *l)
{
    int n, i = IDX_MIN;
    scanf("%d", &n);
    while (n < 0)
    {
        scanf("%d", &n);
    }
    if (n > CAPACITY(*l))
    {
        expandLDinMakanan(l, n - CAPACITY(*l));
    }
    NEFF(*l) = n;
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
        ELMT(*l, i) = temp;
    }
}

void printLDinMakanan(LDinMakanan l)
{
    if (!isEmptyLDinMakanan(l))
    {
        for (int i = IDX_MIN; i < panjangLDinMakanan(l); i++)
        {
            cetakMakanan(ELMT(l, i));
        }
    }
}

void copyLDinMakanan(LDinMakanan lIn, LDinMakanan *lOut)
{
    buatLDinMakanan(lOut, CAPACITY(lIn));
    for (int i = IDX_MIN; i < panjangLDinMakanan(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
    CAPACITY(*lOut) = CAPACITY(lIn);
}

void insertFirstLDinMakanan(LDinMakanan *l, LDinMakananEl val)
{
    insertAtLDinMakanan(l, val, 0);
}

void insertLastLDinMakanan(LDinMakanan *l, LDinMakananEl val)
{
    insertAtLDinMakanan(l, val, NEFF(*l));
}

void insertAtLDinMakanan(LDinMakanan *l, LDinMakananEl val, IdxType idx)
{
    if (isFullLDinMakanan(*l))
    {
        expandLDinMakanan(l, 1);
    }
    NEFF(*l) += 1;
    if (isIdxEffLDinMakanan(*l, idx))
    {
        for (int i = lastIdxLDinMakanan(*l); i > idx; i--)
        {
            ELMT(*l, i) = ELMT(*l, i - 1);
        }
        ELMT(*l, idx) = val;
    }
    else
    {
        printf("idx tidak efektif!\n");
    }
}

void expandLDinMakanan(LDinMakanan *l, int num)
{
    CAPACITY(*l) += num;
    MAKANAN(*l) = realloc(MAKANAN(*l), (CAPACITY(*l)) * sizeof(LDinMakananEl));
}