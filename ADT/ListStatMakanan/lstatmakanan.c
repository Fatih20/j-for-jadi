#include "lstatmakanan.h"
#include "../MBFile/mBFile.h"
#include <stdio.h>
Makanan getMarkLStatMakanan()
{
    Makanan MARK;
    char blank[] = "#";
    Waktu markWaktu = buatWaktu(-1, -1, -1, -1);
    buatMakanan(&MARK, blank, blank, blank, markWaktu, markWaktu);
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
        if (!isMakananEqual(elmtLSM(l, i), getMarkLStatMakanan()))
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

void readLStatMakanan(LStatMakanan *l, char *file)
{

    startMBFile(file);
    int n;
    if (!endMBF)
    {
        n = teksToInt(elmtLDT(currentRow, 0));
    }
    while (n--)
    {
        advMBFile();
        Makanan makananTemp;
        Teks idTemp, aksi, namaTemp, space;
        int hariKad, jamKad, menitKad, hariKirim, jamKirim, menitKirim, hariOlah, jamOlah, menitOlah;
        idTemp = elmtLDT(currentRow, 0);
        advMBFile();
        buatTeks("", &namaTemp);
        buatTeks(" ", &space);
        for (int i = 0; i < nEffLDT(currentRow); i++)
        {
            if (i != 0)
            {
                gabungkanTeks(namaTemp, space, &namaTemp);
            }
            gabungkanTeks(namaTemp, elmtLDT(currentRow, i), &namaTemp);
        }
        advMBFile();
        hariKad = teksToInt(elmtLDT(currentRow, 0));
        jamKad = teksToInt(elmtLDT(currentRow, 1));
        menitKad = teksToInt(elmtLDT(currentRow, 2));
        /* BUAT WAKTU*/
        Waktu waktuKad = buatWaktu(hariKad, jamKad, menitKad, 0);
        advMBFile();
        hariKirim = teksToInt(elmtLDT(currentRow, 0));
        jamKirim = teksToInt(elmtLDT(currentRow, 1));
        menitKirim = teksToInt(elmtLDT(currentRow, 2));
        Waktu waktuKirim = buatWaktu(hariKirim, jamKirim, menitKirim, 0);
        advMBFile();
        aksi = elmtLDT(currentRow, 0);
        advMBFile();
        hariOlah = teksToInt(elmtLDT(currentRow, 0));
        jamOlah = teksToInt(elmtLDT(currentRow, 1));
        menitOlah = teksToInt(elmtLDT(currentRow, 2));
        Waktu waktuOlah = buatWaktu(hariOlah, jamOlah, menitOlah, 0);
        idTipe(makananTemp) = idTemp;
        basiDalam(makananTemp) = waktuKad;
        sampaiDalam(makananTemp) = waktuKirim;
        namaMakanan(makananTemp) = namaTemp;
        insertLastLStatMakanan(l, makananTemp);
    }
}; /* blomm finalll */

/* BELUM FINALL tar aja klo adt makanan dah fixx */
void printLStatMakanan(LStatMakanan l)
{
    printf("==============================\n");
    printf("         DAFTAR MAKANAN       \n");
    printf("==============================\n");
    printf("Nama Makanan - Waktu Kadaluarsa - Lama Pengiriman\n");
    for (int i = 0; i < panjangLStatMakanan(l); i++)
    {
        printf("%d. ", i + 1);
        cetakTeks(namaMakanan(elmtLSM(l, i)));
        printf(" - ");
        /* CETAK WAKTU*/
        tulisWaktu(basiDalam(elmtLSM(l, i)));
        printf(" - ");
        tulisWaktu(sampaiDalam(elmtLSM(l, i)));
        /* ga pake cetakMakanan krn ini idUniknya undefined*/
        printf("\n");
    }
}

Teks getNameFromID(LStatMakanan l, Teks idTipe)
{
    for (int i = 0; i < panjangLStatMakanan(l); i++)
    {
        if (teksSama(idTipe(elmtLSM(l, i)), idTipe))
        {
            return namaMakanan(elmtLSM(l, i));
        }
    }
    Teks blank;
    buatTeks("#", &blank);
    return blank;
};

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
