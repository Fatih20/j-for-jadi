#include "ldinfoodset.h"
#include <stdlib.h>

void buatLDinFoodSet(LDinFoodSet *l, int capacity)
{
    contentLDFS(*l) = (LDinFoodSetEl *)malloc(capacity * sizeof(LDinFoodSetEl));
    nEffLDFS(*l) = 0;
    capacityLDFS(*l) = capacity;
}

void dealokasiLDinFoodSet(LDinFoodSet *l)
{
    free(contentLDFS(*l));
    capacityLDFS(*l) = 0;
    nEffLDFS(*l) = 0;
}

int panjangLDinFoodSet(LDinFoodSet l)
{
    return nEffLDFS(l);
}

IdxType lastIdxLDinFoodSet(LDinFoodSet l)
{
    return nEffLDFS(l) - 1;
}

boolean isIdxValidLDinFoodSet(LDinFoodSet l, IdxType i)
{
    return (i < capacityLDFS(l) && i >= IDX_MIN);
}

boolean isIdxEffLDinFoodSet(LDinFoodSet l, IdxType i)
{
    return (i <= nEffLDFS(l) && i >= IDX_MIN);
}

boolean isEmptyLDinFoodSet(LDinFoodSet l)
{
    return (nEffLDFS(l) == 0);
}

boolean isFullLDinFoodSet(LDinFoodSet l)
{
    return (nEffLDFS(l) == capacityLDFS(l));
}

// Commented untuk sementara karena ribet untuk baca aksi lokasi dari sini. Sebaiknya aksi lokasi diadakan fungsi baca untuk mempermudah, kemudian dimasukkan ke sini.
// void readLDinFoodSet(LDinFoodSet *l)
// {
//     int n, i = IDX_MIN;
//     scanf("%d", &n);
//     while (n < 0)
//     {
//         scanf("%d", &n);
//     }
//     if (n > capacityLDFS(*l))
//     {
//         expandLDinFoodSet(l, n - capacityLDFS(*l));
//     }
//     nEffLDFS(*l) = n;
//     for (i; i < n; i++)
//     {
//         Makanan temp;
//         char *idUnik;
//         char *idTipe;
//         char *namaMakanan;
//         char *namaMakanan;
//         char *namaMakanan;
//         char *namaMakanan;
//         Waktu wB;
//         Waktu wS;
//         int waktuKadaluarsa, lamaPengiriman;
//         printf("Masukkan ID Tipe contentLDFS: ");
//         scanf("%s", &idTipe);
//         printf("Masukkan ID Unik makanan: ");
//         scanf("%s", &idUnik);
//         printf("Masukkan nama makanan: ");
//         scanf("%s", namaMakanan);
//         printf("Masukkan waktu kadaluarsa: ");
//         bacaWaktu(&wB);
//         printf("Masukkan lama pengiriman: ");
//         bacaWaktu(&wS);
//         scanf("%d", &lamaPengiriman);
//         Teks nM, idU, idT;
//         buatTeks(idUnik, &idU);
//         buatTeks(namaMakanan, &nM);
//         buatTeks(idTipe, &idT);
//         buatMakanan(&temp, nM, idT, idU, wB, wS, );
//         elmtLDFS(*l, i) = temp;
//     }
// }

void printLDinFoodSet(LDinFoodSet l)
{
    if (!isEmptyLDinFoodSet(l))
    {
        for (int i = IDX_MIN; i < panjangLDinFoodSet(l); i++)
        {
            cetakFoodSet(elmtLDFS(l, i));
        }
    }
}

void copyLDinFoodSet(LDinFoodSet lIn, LDinFoodSet *lOut)
{
    buatLDinFoodSet(lOut, capacityLDFS(lIn));
    for (int i = IDX_MIN; i < panjangLDinFoodSet(lIn); i++)
    {
        elmtLDFS(*lOut, i) = elmtLDFS(lIn, i);
    }
    nEffLDFS(*lOut) = nEffLDFS(lIn);
    capacityLDFS(*lOut) = capacityLDFS(lIn);
}

void removeFirstLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl *X)
{
    *X = elmtLDFS(*l, 0);
    int i = 0;
    int lastIndex = lastIdxLDinFoodSet(*l);
    for (int i = 0; i <= lastIndex - 1; i++)
    {
        elmtLDFS(*l, i) = elmtLDFS(*l, i + 1);
    }
    nEffLDFS(*l)--;
};

void removeAtLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl *val, IdxType idx)
{
    *val = elmtLDFS(*l, idx);
    for (int i = idx; i < panjangLDinFoodSet(*l) - 1; i++)
    {
        elmtLDFS(*l, i) = elmtLDFS(*l, i + 1);
    }
    nEffLDFS(*l) -= 1;
}

void removeLastLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl *val)
{
    removeAtLDinFoodSet(l, val, panjangLDinFoodSet(*l) - 1);
};

void insertFirstLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl val)
{
    insertAtLDinFoodSet(l, val, 0);
}

void insertLastLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl val)
{
    insertAtLDinFoodSet(l, val, nEffLDFS(*l));
}

void insertAtLDinFoodSet(LDinFoodSet *l, LDinFoodSetEl val, IdxType idx)
{
    if (isFullLDinFoodSet(*l))
    {
        expandLDinFoodSet(l, 1);
    }
    nEffLDFS(*l) += 1;
    if (isIdxEffLDinFoodSet(*l, idx))
    {
        for (int i = lastIdxLDinFoodSet(*l); i > idx; i--)
        {
            elmtLDFS(*l, i) = elmtLDFS(*l, i - 1);
        }
        elmtLDFS(*l, idx) = val;
    }
    else
    {
        printf("idx tidak efektif!\n");
    }
}

void expandLDinFoodSet(LDinFoodSet *l, int num)
{
    capacityLDFS(*l) += num;
    contentLDFS(*l) = realloc(contentLDFS(*l), (capacityLDFS(*l)) * sizeof(LDinFoodSetEl));
}

boolean isMakananInLDFS(LDinFoodSet *l, Teks namaMakanan)
{
    for (int i = 0; i < panjangLDinFoodSet(*l); i++)
    {
        if (teksSama(NameFS(elmtLDFS(*l, i)), namaMakanan))
        {
            return true;
        }
    }
    return false;
};

int indexBeforeHigher(LDinFoodSet l, int idTipeI)
{
    int i = 0;
    boolean found = false;
    if (isEmptyLDinFoodSet(l))
    {
        return i;
    }
    while (i < nEffLDFS(l) && !found)
    {
        found = IdFS(elmtLDFS(l, i)) > idTipeI;
        if (!found)
        {
            i++;
        }
    }

    return i - 1;
};

void insertOrderedLDFS(LDinFoodSet *l, FoodSet fs)
{
    int whereToAdd = indexBeforeHigher(*l, IdFS(fs));
    insertAtLDinFoodSet(l, fs, whereToAdd);
};

int searchOrderedLDFS(LDinFoodSet l, Teks id)
{
    int searchedId = teksToInt(id);
    return searchOrderedWLDFS(l, searchedId, capacityLDFS(l) - 1, 0);
};

int searchOrderedWLDFS(LDinFoodSet l, int id, int hi, int lo)
{
    if (hi >= lo)
    {
        int mid = lo + ((hi - lo) / 2);
        int idTipeCurr = IdFS(elmtLDFS(l, mid));

        if (idTipeCurr == id)
        {
            return mid;
        }
        if (idTipeCurr > id)
        {
            return searchResep(l, id, lo, mid - 1);
        }
        return searchResep(l, id, mid + 1, hi);
    }
    return IDX_UNDEF;
}
