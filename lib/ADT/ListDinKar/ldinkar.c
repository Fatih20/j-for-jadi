#include "ldinkar.h"
#include <stdio.h>
#include <stdlib.h>

void buatLDinKar(LDinKar *l, int capacity)
{
    kar(*l) = (LDinKarEl *)malloc(capacity * sizeof(LDinKarEl));
    nEffLDC(*l) = 0;
    capacityLDC(*l) = capacity;
}

void dealokasiLDinKar(LDinKar *l)
{
    free(kar(*l));
    capacityLDC(*l) = 0;
    nEffLDC(*l) = 0;
}

int panjangLDinKar(LDinKar l)
{
    return nEffLDC(l);
}

IdxType lastIdxLDinKar(LDinKar l)
{
    return nEffLDC(l) - 1;
}

boolean isIdxValidLDinKar(LDinKar l, IdxType i)
{
    return (i < capacityLDC(l) && i >= IDX_MIN);
}

boolean isIdxEffLDinKar(LDinKar l, IdxType i)
{
    return (i <= nEffLDC(l) && i >= IDX_MIN);
}

boolean isEmptyLDinKar(LDinKar l)
{
    return (nEffLDC(l) == 0);
}

boolean isFullLDinKar(LDinKar l)
{
    return (nEffLDC(l) == capacityLDC(l));
}

void readLDinKar(LDinKar *l)
{
    int n, i;
    scanf("%d", &n);
    while (n < 0)
    {
        scanf("%d", &n);
    }
    if (n > capacityLDC(*l))
    {
        expandLDinKar(l, n - capacityLDC(*l));
    }
    char temp;
    scanf("%c", &temp); /*eats new line*/
    nEffLDC(*l) = n;
    for (i = IDX_MIN; i < n; i++)
    {
        scanf("%c", &(elmtLDC(*l, i)));
    }
}

void printLDinKar(LDinKar l)
{
    if (!isEmptyLDinKar(l))
    {
        for (int i = IDX_MIN; i < panjangLDinKar(l); i++)
        {
            printf("%c", elmtLDC(l, i));
        }
        printf("\n");
    }
}

void copyLDinKar(LDinKar lIn, LDinKar *lOut)
{
    buatLDinKar(lOut, capacityLDC(lIn));
    for (int i = IDX_MIN; i < panjangLDinKar(lIn); i++)
    {
        elmtLDC(*lOut, i) = elmtLDC(lIn, i);
    }
    nEffLDC(*lOut) = nEffLDC(lIn);
    capacityLDC(*lOut) = capacityLDC(lIn);
}

void insertFirstLDinKar(LDinKar *l, LDinKarEl val)
{
    insertAtLDinKar(l, val, 0);
}

void insertLastLDinKar(LDinKar *l, LDinKarEl val)
{
    insertAtLDinKar(l, val, nEffLDC(*l));
}

void insertAtLDinKar(LDinKar *l, LDinKarEl val, IdxType idx)
{
    if (isFullLDinKar(*l))
    {
        expandLDinKar(l, 1);
    }
    nEffLDC(*l) += 1;
    if (isIdxEffLDinKar(*l, idx))
    {
        for (int i = lastIdxLDinKar(*l); i > idx; i--)
        {
            elmtLDC(*l, i) = elmtLDC(*l, i - 1);
        }
        elmtLDC(*l, idx) = val;
    }
    else
    {
        printf("idx tidak efektif!\n");
    }
}

void removeFirstLDinKar(LDinKar *l, LDinKarEl *val)
{
    removeAtLDinKar(l, val, 0);
};

void removeAtLDinKar(LDinKar *l, LDinKarEl *val, IdxType idx)
{
    *val = elmtLDC(*l, idx);
    for (int i = idx; i < panjangLDinKar(*l) - 1; i++)
    {
        elmtLDC(*l, i) = elmtLDC(*l, i + 1);
    }
    nEffLDC(*l) -= 1;
}

void removeLastLDinKar(LDinKar *l, LDinKarEl *val)
{
    removeAtLDinKar(l, val, panjangLDinKar(*l) - 1);
};

void expandLDinKar(LDinKar *l, int num)
{
    capacityLDC(*l) += num;
    kar(*l) = realloc(kar(*l), (capacityLDC(*l)) * sizeof(LDinKarEl));
}