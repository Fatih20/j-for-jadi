#include "ldinkar.h"
#include <stdio.h>
#include <stdlib.h>

void buatLDinKar(LDinKar *l, int capacity)
{
    KAR(*l) = (LDinKarEl *)malloc(capacity * sizeof(LDinKarEl));
    NEFF(*l) = 0;
    CAPACITY(*l) = capacity;
}

void dealokasiLDinKar(LDinKar *l)
{
    free(KAR(*l));
    CAPACITY(*l) = 0;
    NEFF(*l) = 0;
}

int panjangLDinKar(LDinKar l)
{
    return NEFF(l);
}

IdxType lastIdxLDinKar(LDinKar l)
{
    return NEFF(l) - 1;
}

boolean isIdxValidLDinKar(LDinKar l, IdxType i)
{
    return (i < CAPACITY(l) && i >= IDX_MIN);
}

boolean isIdxEffLDinKar(LDinKar l, IdxType i)
{
    return (i <= NEFF(l) && i >= IDX_MIN);
}

boolean isEmptyLDinKar(LDinKar l)
{
    return (NEFF(l) == 0);
}

boolean isFullLDinKar(LDinKar l)
{
    return (NEFF(l) == CAPACITY(l));
}

void readLDinKar(LDinKar *l)
{
    int n, i;
    scanf("%d", &n);
    while (n < 0)
    {
        scanf("%d", &n);
    }
    if (n > CAPACITY(*l))
    {
        expandLDinKar(l, n - CAPACITY(*l));
    }
    char temp;
    scanf("%c", &temp); /*eats new line*/
    NEFF(*l) = n;
    for (i = IDX_MIN; i < n; i++)
    {
        scanf("%c", &(ELMT(*l, i)));
    }
}

void printLDinKar(LDinKar l)
{
    if (!isEmptyLDinKar(l))
    {
        for (int i = IDX_MIN; i < panjangLDinKar(l); i++)
        {
            printf("%c", ELMT(l, i));
        }
        printf("\n");
    }
}

void copyLDinKar(LDinKar lIn, LDinKar *lOut)
{
    buatLDinKar(lOut, CAPACITY(lIn));
    for (int i = IDX_MIN; i < panjangLDinKar(lIn); i++)
    {
        ELMT(*lOut, i) = ELMT(lIn, i);
    }
    NEFF(*lOut) = NEFF(lIn);
    CAPACITY(*lOut) = CAPACITY(lIn);
}

void insertFirstLDinKar(LDinKar *l, LDinKarEl val)
{
    insertAtLDinKar(l, val, 0);
}

void insertLastLDinKar(LDinKar *l, LDinKarEl val)
{
    insertAtLDinKar(l, val, NEFF(*l));
}

void insertAtLDinKar(LDinKar *l, LDinKarEl val, IdxType idx)
{
    if (isFullLDinKar(*l))
    {
        expandLDinKar(l, 1);
    }
    NEFF(*l) += 1;
    if (isIdxEffLDinKar(*l, idx))
    {
        for (int i = lastIdxLDinKar(*l); i > idx; i--)
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

void expandLDinKar(LDinKar *l, int num)
{
    CAPACITY(*l) += num;
    KAR(*l) = realloc(KAR(*l), (CAPACITY(*l)) * sizeof(LDinKarEl));
}