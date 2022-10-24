#include "teks.h"
#include <stdio.h>

void buatTeks(char string[], Teks *teks)
{
    int i = 0;
    buatTeksKosong(teks);
    for (char kar = *string; kar != '\0'; kar = *++string)
    {
        insertLastLDinKar(&(karArrayT(*teks)), kar);
        panjangT(*teks) += 1;
        i += 1;
    }
};

void buatTeksKosong(Teks *teks)
{
    panjangT(*teks) = 0;
    buatLDinKar(&karArrayT(*teks), 100);
};

void cetakTeks(Teks t)
{
    for (int i = 0; i < panjangT(t); i++)
    {
        // printf("test");
        printf("%c", elmtLDC(karArrayT(t), i));
    }
};

void plusKar(Teks *teks, char kar)
{

    insertLastLDinKar(&(karArrayT(*teks)), kar);
    panjangT(*teks) += 1;
};

void delKar(Teks *teks)
{
    if (panjangT(*teks) > 0)
    {
        panjangT(*teks) -= 1;
    }
};

boolean teksSama(Teks t1, Teks t2)
{
    boolean same = panjangT(t1) == panjangT(t2);
    int i = 0;
    int pTeks = panjangT(t1);
    while (same && i < pTeks)
    {
        same = elmtLDC(karArrayT(t1), i) == elmtLDC(karArrayT(t2), i);
        i += same;
    }
    return same;
};

boolean teksLPendek(Teks t1, Teks t2)
{
    return panjangT(t1) < panjangT(t2);
};

boolean teksSamaP(Teks t1, Teks t2)
{
    return panjangT(t1) == panjangT(t2);
};

boolean teksLPanjang(Teks t1, Teks t2)
{
    return panjangT(t1) > panjangT(t2);
};

void gabungkanTeks(Teks t1, Teks t2, Teks *t3)
{
    buatTeksKosong(t3);
    for (int i = 0; i < panjangT(t1); i++)
    {
        plusKar(t3, elmtLDC(karArrayT(t1), i));
    }

    for (int j = 0; j < panjangT(t2); j++)
    {
        plusKar(t3, elmtLDC(karArrayT(t2), j));
    }
};
