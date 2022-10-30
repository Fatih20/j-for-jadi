#include "lstatmakanan.h"
#include "../MBFile/mBFile.h"
#include <stdio.h>
Makanan getMarkLStatMakanan()
{
    Makanan MARK;
    char blank[] = "#";
    Teks markTeks;
    buatTeks(blank, &markTeks);
    Waktu markWaktu = buatWaktu(-1, -1, -1, -1);
    AksiLokasi markAksi;
    buatAksiLokasi(&markAksi, markTeks, -1, -1, -1, -1, -1, -1);
    buatMakanan(&MARK, markTeks, markTeks, markTeks, markWaktu, markWaktu, markAksi);
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

void readLStatMakanan(LStatMakanan *l, char *file, AksiLokasi aLArray[])
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
        int hB, jB, mB, hS, jS, mS, hariOlah, jamOlah, menitOlah;
        /* BACA ID MAKANAN */
        idTemp = elmtLDT(currentRow, 0);

        /* BACA NAMA MAKANAN*/
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
        /* BACA WAKTU KADALUARSA*/
        advMBFile();
        hB = teksToInt(elmtLDT(currentRow, 0));
        jB = teksToInt(elmtLDT(currentRow, 1));
        mB = teksToInt(elmtLDT(currentRow, 2));
        Waktu waktuKad = buatWaktu(hB, jB, mB, 0);

        /* BACA LAMA PENGIRIMAN */
        advMBFile();
        hS = teksToInt(elmtLDT(currentRow, 0));
        jS = teksToInt(elmtLDT(currentRow, 1));
        mS = teksToInt(elmtLDT(currentRow, 2));
        Waktu waktuKirim = buatWaktu(hS, jS, mS, 0);

        /* BACA AKSI */
        advMBFile();
        aksi = elmtLDT(currentRow, 0);

        /* BACA WAKTU PENGOLAHAN*/
        advMBFile();
        hariOlah = teksToInt(elmtLDT(currentRow, 0));
        jamOlah = teksToInt(elmtLDT(currentRow, 1));
        menitOlah = teksToInt(elmtLDT(currentRow, 2));
        POINT tempatAksi = aksiLokasiDiMana(aksi, aLArray);

        /* BUAT AKSI LOKASI */
        AksiLokasi aksiTemp;
        buatAksiLokasi(&aksiTemp, aksi, Absis(tempatAksi), Ordinat(tempatAksi), hariOlah, jamOlah, menitOlah, 0);
        /* BUAT MAKANAN */
        buatMakanan(&makananTemp, namaTemp, idTemp, idTemp, waktuKad, waktuKirim, aksiTemp);
        /* MASUKKAN MAKANAN KE LSTAT */
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

Makanan getMakananFromID(LStatMakanan l, Teks idTipe)
{
    for (int i = 0; i < panjangLStatMakanan(l); i++)
    {
        if (teksSama(idTipe(elmtLSM(l, i)), idTipe))
        {
            return (elmtLSM(l, i));
        }
    }
    return getMarkLStatMakanan();
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
