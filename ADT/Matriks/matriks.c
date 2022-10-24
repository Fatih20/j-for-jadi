#include <stdio.h>
#include "matriks.h"

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

void readMatriks(Matriks *m, char namaFile[], POINT *lokasiSimulator)
{
    // KAMUS LOKAL
    int i, j, e, nRows, nCols, ctr;
    Teks bil; // Penampung nRow/nCol asumsi 10<=nRow<=100 dan 10<=nCol<=100
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
                while (i < panjangLDinTeks(currentRow) && (currentRow.teks[i] != ' '))
                {
                    bil[i] =
                }
                isRow = false;
                nRows = 0;
                for (i = 0; i < currentWord.length; i++)
                {
                    nRows = nRows * 10 + (int)(bil[i] - '0');
                }
            }
            else // Jika yang terbaca adalah konfigurasi nCols
            {
                nCols = 0;
                for (i = 0; i < currentWord.length; i++)
                {
                    nCols = nCols * 10 + (int)(currentWord.karArray[i] - '0');
                }
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
                i = 1;
            }
            ctr++;
        }
        else
        {
            // Mengisi Peta
            ELMT(*m, i, 0) = '*';
            ELMT(*m, i, getLastIdxCol(*m)) = '*';
            for (j = 1; j <= getLastIdxCol(*m) - 1; j++)
            {
                if (currentWord.karArray[j - 1] == '#')
                {
                    ELMT(*m, i, j) = ' ';
                }
                else
                {
                    if (currentWord.karArray[j - 1] == 'S')
                    {
                        CreatePoint(lokasiSimulator, i - 1, j - 1);
                    }
                    ELMT(*m, i, j) = currentWord.karArray[j - 1];
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
