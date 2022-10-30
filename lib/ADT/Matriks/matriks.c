#include <stdio.h>
#include "matriks.h"

LDinTeks currentRow;

void createMatriks(int nRows, int nCols, Matriks *m)
{
    // KAMUS LOKAL
    // ALGORITMA
    ROW_EFF(*m) = nRows;
    COL_EFF(*m) = nCols;
}

boolean isMatriksIdxValid(int i, int j)
{
    // KAMUS LOKAL
    // ALGORITMA
    return ((i >= 0 && i < ROW_CAP) && (j >= 0 && j < COL_CAP));
}

IdxType getLastIdxRow(Matriks m)
{
    // KAMUS LOKAL
    // ALGORITMA
    return (ROW_EFF(m) - 1);
}

IdxType getLastIdxCol(Matriks m)
{
    // KAMUS LOKAL
    // ALGORITMA
    return (COL_EFF(m) - 1);
}

boolean isIdxEff(Matriks m, IdxType i, IdxType j)
{
    // KAMUS LOKAL
    // ALGORITMA
    return (i >= 0 && i <= getLastIdxRow(m)) && (j >= 0 && j <= getLastIdxCol(m));
}

void copyMatriks(Matriks mIn, Matriks *mOut)
{
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    createMatriks(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (i = 0; i <= getLastIdxRow(mIn); i++)
    {
        for (j = 0; j <= getLastIdxCol(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatriks(Matriks *m, char namaFile[], POINT *lokasiSimulator, AksiLokasi *MIX, AksiLokasi *BOIL, AksiLokasi *CHOP, AksiLokasi *FRY, AksiLokasi *TELEPON)
{
    // KAMUS LOKAL
    int i, j, e, nRows, nCols, ctr;
    Teks aksi; // penampung teks aksi
    boolean isRow;
    // ALGORITMA
    ctr = 0; // Untuk mengambi nRows dan nCols
    isRow = true;
    CreatePoint(lokasiSimulator, -1, -1);
    startMBFile(namaFile);
    while (!endMBF)
    {

        if (ctr == 0)
        {

            if (isRow) // Jika yang terbaca adalah konfigurasi nRows
            {
                i = 0;
                isRow = false;
                nRows = teksToInt(elmtLDT(currentRow, 0));
            }
            if (!isRow) // Jika yang terbaca adalah konfigurasi nCols
            {
                nCols = teksToInt(elmtLDT(currentRow, 1));
                ctr++;
            }

            if (ctr > 0) // Jika Konfigurasi baris 1 sudah selesai
            {
                createMatriks(nRows + 2, nCols + 2, m); // Insialisasi ukuran peta
                // Batas Atas dan Bawah Peta
                for (j = 0; j <= getLastIdxCol(*m); j++)
                {
                    ELMT(*m, 0, j) = '*';
                    ELMT(*m, getLastIdxRow(*m), j) = '*';
                }
                i = 1; // indeks baris
            }
        }
        else
        {
            // Mengisi Peta
            ELMT(*m, i, 0) = '*';
            ELMT(*m, i, getLastIdxCol(*m)) = '*';
            for (j = 1; j <= getLastIdxCol(*m) - 1; j++)
            {
                if (nthChar(elmtLDT(currentRow, 0), j - 1) == '#')
                {
                    ELMT(*m, i, j) = ' ';
                }
                else
                {
                    if (nthChar(elmtLDT(currentRow, 0), j - 1) == 'S')
                    {
                        CreatePoint(lokasiSimulator, i - 1, j - 1);
                    }
                    else if (nthChar(elmtLDT(currentRow, 0), j - 1) == 'M')
                    {
                        buatTeks("MIX", &aksi);                              // default
                        buatAksiLokasi(MIX, aksi, i - 1, j - 1, 0, 0, 1, 0); // default
                    }
                    else if (nthChar(elmtLDT(currentRow, 0), j - 1) == 'T')
                    {
                        buatTeks("TELEPON", &aksi);                              // default
                        buatAksiLokasi(TELEPON, aksi, i - 1, j - 1, 0, 0, 1, 0); // default
                    }
                    else if (nthChar(elmtLDT(currentRow, 0), j - 1) == 'F')
                    {
                        buatTeks("FRY", &aksi);                              // default
                        buatAksiLokasi(FRY, aksi, i - 1, j - 1, 0, 0, 1, 0); // default
                    }
                    else if (nthChar(elmtLDT(currentRow, 0), j - 1) == 'C')
                    {
                        buatTeks("CHOP", &aksi);                              // default
                        buatAksiLokasi(CHOP, aksi, i - 1, j - 1, 0, 0, 1, 0); // default
                    }
                    else if (nthChar(elmtLDT(currentRow, 0), j - 1) == 'B')
                    {
                        buatTeks("BOIL", &aksi);                              // default
                        buatAksiLokasi(BOIL, aksi, i - 1, j - 1, 0, 0, 1, 0); // default
                    }
                    ELMT(*m, i, j) = nthChar(elmtLDT(currentRow, 0), j - 1);
                }
            }
            i++;
        }
        advMBFile();
    }
    // m merupakan peta hasil konfigurasi
}

void displayMatriks(Matriks m)
{
    // KAMUS LOKAL
    int i, j;
    // ALGORITMA
    for (i = 0; i <= getLastIdxRow(m); i++)
    {
        for (j = 0; j <= getLastIdxCol(m); j++)
        {
            if (j != getLastIdxCol(m))
            {
                printf("%c ", ELMT(m, i, j));
            }
            else
            {
                printf("%c", ELMT(m, i, j));
            }
        }
        printf("\n");
    }
}

boolean isCollide(Matriks m, POINT p)
{
    // KAMUS LOKAL
    int x, y;
    // ALGORITMA
    // ditambah 1 untuk menyesuaikan Matriks dengan Peta yang sebenarnya (di luar *)
    x = Absis(p) + 1;
    y = Ordinat(p) + 1;
    return (ELMT(m, x, y) == '*' || ELMT(m, x, y) == 'X' || ELMT(m, x, y) == 'T' || ELMT(m, x, y) == 'M' || ELMT(m, x, y) == 'F' || ELMT(m, x, y) == 'C' || ELMT(m, x, y) == 'B');
}

void moveSimulator(Matriks *m, POINT *lokasiSimulator, POINT p)
{
    // KAMUS LOKAL
    int x1, y1, x2, y2;
    // ALGORITMA

    // Setup
    x1 = Absis(*lokasiSimulator) + 1;
    y1 = Ordinat(*lokasiSimulator) + 1;
    x2 = Absis(p) + 1;
    y2 = Ordinat(p) + 1;
    ELMT(*m, x2, y2) = 'S'; // Mengisi tanda 'S' pada koordinat p
    ELMT(*m, x1, y1) = ' '; // Menghapus tanda 'S' pada posisi sebelumnya
    // Mengubah lokasi simulator
    Absis(*lokasiSimulator) = x2 - 1;
    Ordinat(*lokasiSimulator) = y2 - 1;
}
