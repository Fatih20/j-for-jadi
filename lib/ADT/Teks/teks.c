#include "teks.h"
#include <stdio.h>

void buatTeks(char string[], Teks *teks)
{
    int i = 0;
    buatTeksKosong(teks);
    for (char kar = *string; kar != '\0'; kar = *++string)
    {
        insertLastLDinKar(&(karArrayT(*teks)), kar);
        // Tidak perlu tambahkan panjangT karena otomatis dilakukan di dalam insertLast
        i += 1;
    }
};

void buatTeksKosong(Teks *teks)
{
    panjangT(*teks) = 0;
    buatLDinKar(&karArrayT(*teks), 20);
};

void cetakTeks(Teks t, char color)
{
    for (int i = 0; i < panjangT(t); i++)
    {
        // printf("test");
        if (color == 'r')
        {
            printRed(elmtLDC(karArrayT(t), i));
        }
        else if (color == 'g')
        {
            printGreen(elmtLDC(karArrayT(t), i));
        }
        else if (color == 'b')
        {
            printBlue(elmtLDC(karArrayT(t), i));
        }
        else if (color == 'y')
        {
            printYellow(elmtLDC(karArrayT(t), i));
        }
        else if (color == 'c')
        {
            printCyan(elmtLDC(karArrayT(t), i));
        }
        else if (color == 'm')
        {
            printMagenta(elmtLDC(karArrayT(t), i));
        }
        else if (color == 'p')
        {
            printPurple(elmtLDC(karArrayT(t), i));
        }
        else
        {
            printf("%c", elmtLDC(karArrayT(t), i));
        }
    }
};

void plusKar(Teks *teks, char kar)
{
    insertLastLDinKar(&(karArrayT(*teks)), kar);
};

void prefixKar(Teks *teks, char kar)
{
    insertFirstLDinKar(&(karArrayT(*teks)), kar);
};

void delKar(Teks *teks)
{
    char temp;
    removeLastLDinKar(&karArrayT(*teks), &temp);
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

boolean teksSamaCI(Teks t1, Teks t2)
{
    boolean same = panjangT(t1) == panjangT(t2);
    int i = 0;
    int pTeks = panjangT(t1);
    while (same && i < pTeks)
    {
        char oKar1 = elmtLDC(karArrayT(t1), i);
        char oKar2 = elmtLDC(karArrayT(t2), i);
        if (oKar1 >= 'a' && oKar1 <= 'z')
        {
            oKar1 -= ('a' - 'A');
        }

        if (oKar2 >= 'a' && oKar2 <= 'z')
        {
            oKar2 -= ('a' - 'A');
        }

        same = oKar1 == oKar2;
        i += same;
    }
    return same;
};

Teks toUpper(Teks t1)
{
    int pTeks = panjangT(t1);
    Teks t1U;
    buatTeksKosong(&t1U);
    for (int i = 0; i < pTeks; i++)
    {
        char uKar = elmtLDC(karArrayT(t1), i);
        if (uKar >= 'a' && uKar <= 'z')
        {
            uKar -= ('a' - 'A');
        }
        plusKar(&t1U, uKar);
    }
    return t1U;
}

Teks toLower(Teks t1)
{
    int pTeks = panjangT(t1);
    Teks t1L;
    buatTeksKosong(&t1L);
    for (int i = 0; i < pTeks; i++)
    {
        char lKar = elmtLDC(karArrayT(t1), i);
        if (lKar >= 'a' && lKar <= 'z')
        {
            lKar += ('a' - 'A');
        }
        plusKar(&t1L, lKar);
    }
    return t1L;
}

void prependTeks(Teks *t1, Teks t2)
{
    int pT2 = panjangT(t2);
    for (int i = 0; i < pT2; i++)
    {
        prefixKar(t1, nthChar(t2, i));
    }
};

void tambahkanTeks(Teks *t1, Teks t2)
{
    int pT2 = panjangT(t2);
    for (int i = 0; i < pT2; i++)
    {
        plusKar(t1, nthChar(t2, i));
    }
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

int teksToInt(Teks t)
{
    int val = 0;
    for (int i = 0; i < panjangT(t); i++)
    {
        val = val * 10 + (elmtLDC(karArrayT(t), i) - '0');
    }
    return val;
}

boolean isTeksInt(Teks t)
{
    for (int i = 0; i < panjangT(t); i++)
    {
        if (elmtLDC(karArrayT(t), i) < '0' || elmtLDC(karArrayT(t), i) > '9')
        {
            return false;
        }
    }
    return true;
}

void teksKeString(char string[], Teks teks)
{
    int i = 0;
    while (i < panjangT(teks))
    {
        string[i] = nthChar(teks, i);
        i++;
    }
    string[i] = '\0';
};

Teks intToTeks(int i)
{
    int n = i;
    int digitN = 0;
    Teks iRes;
    buatTeksKosong(&iRes);
    while (n != 0)
    {
        char charToAdd = (n % 10) + '0';
        prefixKar(&iRes, charToAdd);
        n = n / 10;
        digitN++;
    }

    Teks leadingZero;
    buatTeksKosong(&leadingZero);
    int zeroToAdd = 3 - digitN;
    while (zeroToAdd > 0)
    {
        plusKar(&leadingZero, '0');
        zeroToAdd--;
    }

    prependTeks(&iRes, leadingZero);
    return iRes;
};
