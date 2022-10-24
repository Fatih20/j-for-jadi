#include "ldinteks.h"
#include <stdio.h>
#include <stdlib.h>

void buatLDinTeks(LDinTeks *l, int capacity)
{
    teks(*l) = (LDinTeksEl *)malloc(capacity * sizeof(LDinTeksEl));
    nEffLDT(*l) = 0;
    capacityLDT(*l) = capacity;
}

void dealokasiLDinTeks(LDinTeks *l)
{
    free(teks(*l));
    capacityLDT(*l) = 0;
    nEffLDT(*l) = 0;
}

int panjangLDinTeks(LDinTeks l)
{
    return nEffLDT(l);
}

IdxType lastIdxLDinTeks(LDinTeks l)
{
    return nEffLDT(l) - 1;
}

boolean isIdxValidLDinTeks(LDinTeks l, IdxType i)
{
    return (i < capacityLDT(l) && i >= IDX_MIN);
}

boolean isIdxEffLDinTeks(LDinTeks l, IdxType i)
{
    return (i <= nEffLDT(l) && i >= IDX_MIN);
}

boolean isEmptyLDinTeks(LDinTeks l)
{
    return (nEffLDT(l) == 0);
}

boolean isFullLDinTeks(LDinTeks l)
{
    return (nEffLDT(l) == capacityLDT(l));
}

void readLDinTeks(LDinTeks *l)
{
    int n, i;
    scanf("%d", &n);
    while (n < 0)
    {
        scanf("%d", &n);
    }
    if (n > capacityLDT(*l))
    {
        expandLDinTeks(l, n - capacityLDT(*l));
    }
    char tempString[100]; /*eats new line*/
    nEffLDT(*l) = n;
    for (i = IDX_MIN; i < n; i++)
    {
        Teks tempTeks;
        scanf("%s", &tempString);
        buatTeks(tempString, &tempTeks);
        elmtLDT(*l, i) = tempTeks;
    }
}

void printLDinTeks(LDinTeks l)
{
    if (!isEmptyLDinTeks(l))
    {
        for (int i = IDX_MIN; i < panjangLDinTeks(l); i++)
        {
            cetakTeks(elmtLDT(l, i));
            printf(" ");
        }
        printf("\n");
    }
}

void copyLDinTeks(LDinTeks lIn, LDinTeks *lOut)
{
    buatLDinTeks(lOut, capacityLDT(lIn));
    for (int i = IDX_MIN; i < panjangLDinTeks(lIn); i++)
    {
        elmtLDT(*lOut, i) = elmtLDT(lIn, i);
    }
    nEffLDT(*lOut) = nEffLDT(lIn);
    capacityLDT(*lOut) = capacityLDT(lIn);
}

void insertFirstLDinTeks(LDinTeks *l, LDinTeksEl val)
{
    insertAtLDinTeks(l, val, 0);
}

void insertLastLDinTeks(LDinTeks *l, LDinTeksEl val)
{
    insertAtLDinTeks(l, val, nEffLDT(*l));
}

void insertAtLDinTeks(LDinTeks *l, LDinTeksEl val, IdxType idx)
{
    if (isFullLDinTeks(*l))
    {
        expandLDinTeks(l, 1);
    }
    nEffLDT(*l) += 1;
    if (isIdxEffLDinTeks(*l, idx))
    {
        for (int i = lastIdxLDinTeks(*l); i > idx; i--)
        {
            elmtLDT(*l, i) = elmtLDT(*l, i - 1);
        }
        elmtLDT(*l, idx) = val;
    }
    else
    {
        printf("idx tidak efektif!\n");
    }
}

void expandLDinTeks(LDinTeks *l, int num)
{
    capacityLDT(*l) += num;
    teks(*l) = realloc(teks(*l), (capacityLDT(*l)) * sizeof(LDinTeksEl));
}