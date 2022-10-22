#include "lstatmakanan.h"
#include "../MKFile/mKFile.h"
#include <stdio.h>
Makanan getMarkLStatMakanan()
{
    Makanan MARK;
    char blank[] = "#";
    buatMakanan(&MARK, blank, -1, -1, blank, blank);
    return MARK;
}

void buatLStatMakanan(LStatMakanan *l)
{
    for (int i = 0; i < capacityLSM; i++)
    {
        elmtLSM(*l, i) = getMarkLStatMakanan();
    }
}

int panjangLStatMakanan(LStatMakanan l)
{
    int res = 0;
    for (int i = 0; i < capacityLSM; i++)
    {
        if (isMakananEqual(elmtLSM(l, i), getMarkLStatMakanan()))
        {
            res += 1;
        }
    }
    return res;
}

IdxType lastIdxLStatMakanan(LStatMakanan l)
{
    return panjangLStatMakanan(l) - 1;
}


boolean isIdxValidLStatMakanan(LStatMakanan l, IdxType i)
{
    return i >= 0 && i < capacityLSM;
}

boolean isIdxEffLStatMakanan(LStatMakanan l, IdxType i)
{
    return i >= 0 && i < panjangLStatMakanan(l);
}

boolean isEmptyLStatMakanan(LStatMakanan l)
{
    return !panjangLStatMakanan(l);
}

boolean isFullLStatMakanan(LStatMakanan l)
{
    return panjangLStatMakanan(l) == capacityLSM;
}


void readLStatMakanan(LStatMakanan *l) 
{
    startMKFile("makanancfg.txt");
    printf("aaa");
    int n;
    if (!endMKF)
    {
        printf("aaa");
        n = teksToInt(currentWord);
    }
    while (n--)
    {
        Makanan makananTemp;
        Teks idTemp, aksi, namaTemp;
        int hariKad, jamKad, menitKad, hariKirim, jamKirim, menitKirim, hariOlah, jamOlah, menitOlah;
        advMKFile();
        idTemp = currentWord; /* Baca ID */
        advMKFile();
        namaTemp = currentWord; 
        advMKFile();    /* Baca nama*/
        for (int i = 0; i < 3; i++) /* Baca waktu kadaluarsa */
        {
            advMKFile();
            hariKad = teksToInt(currentWord);
            advMKFile();
            jamKad = teksToInt(currentWord);
            advMKFile();
            menitKad = teksToInt(currentWord);
        }
        for (int i = 0; i < 3; i++) /* Baca waktu pengiriman*/
        {
            advMKFile();
            hariKirim = teksToInt(currentWord);
            advMKFile();
            jamKirim = teksToInt(currentWord);
            advMKFile();
            menitKirim = teksToInt(currentWord);
        }
        advMKFile();
        aksi = currentWord;         /* Baca aksi */
        for (int i = 0; i < 3; i++) /* Baca waktu pengolahan */
        {
            advMKFile();
            hariOlah = teksToInt(currentWord);
            advMKFile();
            jamOlah = teksToInt(currentWord);
            advMKFile();
            menitOlah = teksToInt(currentWord);
        }
        idTipe(makananTemp) = idTemp;
        basiDalam(makananTemp) = hariKad;
        sampaiDalam(makananTemp) = hariKirim;
        namaMakanan(makananTemp) = namaTemp;
        cetakMakanan(makananTemp);
        insertLastLStatMakanan(l, makananTemp);
    }
};
/* I.S. l sembarang */
/* F.S. List l terdefinisi */
/* Proses: membaca banyaknya elemen l dan mengisi nilainya */
/* 1. Baca banyaknya elemen diakhiri enter, misalnya n */
/*    Pembacaan diulangi sampai didapat n yang benar yaitu 0 <= n <= CAPACITY */
/*    Jika n tidak valid, tidak diberikan pesan kesalahan */
/* 2. Jika 0 < n <= CAPACITY; Lakukan n kali:
          Baca elemen mulai dari indeks 0 satu per satu diakhiri enter */
/*    Jika n = 0; hanya terbentuk List kosong */
void printLStatMakanan(LStatMakanan l)
{
    for (int i = 0; i < panjangLStatMakanan(l); i++)
    {
        printf("%d. \n", i + 1);
        cetakMakanan(elmtLSM(l, i));
    }
}

int indexOfLStatMakanan(LStatMakanan l, LStatMakananEl val)
{
    if (!isEmptyLStatMakanan(l))
    {
        int i = IDX_MIN;
        for (i; i < panjangLStatMakanan(l); i++)
        {
            if (isMakananEqual(elmtLSM(l, i), val))
            {
                return i;
            }
        }
        return IDX_UNDEF;
    }
    else
    {
        return IDX_UNDEF;
    }
}

void insertLastLStatMakanan(LStatMakanan *l, LStatMakananEl val)
{
    if (panjangLStatMakanan(*l) < capacityLSM)
    {
        elmtLSM(*l, panjangLStatMakanan(*l)) = val;
    }
}
