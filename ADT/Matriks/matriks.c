#include <stdio.h>
#include "matriks.h"

void createMatrix(int nRows, int nCols, Matriks *m)
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
    createMatrix(ROW_EFF(mIn), COL_EFF(mIn), mOut);
    for (i = 0; i <= getLastIdxRow(mIn); i++)
    {
        for (j = 0; j <= getLastIdxCol(mIn); j++)
        {
            ELMT(*mOut, i, j) = ELMT(mIn, i, j);
        }
    }
}

void readMatriks(Matriks *m, int nRow, int nCol)
{
    // KAMUS LOKAL
    int i, j, e;
    // ALGORITMA
    createMatrix(nRow, nCol, m); // inisialisasi matriks kosong
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
                printf("%d ", ELMT(m, i, j));
            }
            else
            {
                printf("%d", ELMT(m, i, j));
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
