#include "../boolean.h"
#include "../Point/Point.h"
#include "../MBFile/mBFile.h"
#include "../AksiLokasi/aksiLokasi.h"
#include "../../Utility/Printc/printc.h"

#ifndef MATRIKS_H
#define MATRIKS_H

/**
 * @brief Ukuran Maksimal dari Peta diasumsikan 100 x 100, CAPACITY 102 untuk alokasi batas (*)
 *
 */
#define ROW_CAP 102
#define COL_CAP 102

typedef int IdxType;
typedef char ElPeta;

/**
 * @brief Matriks yang merepresentasikan peta
 * @param mem Matriks of Char berisi ElPeta
 * @param rowEff banyaknya/ukuran baris yg terdefinisi
 * @param collEff banyaknya/ukuran kolom yg terdefinisi
 */
typedef struct
{
  ElPeta mem[ROW_CAP][COL_CAP];
  int rowEff;
  int colEff;
} Matriks;
/* rowEff >= 12 dan colEff >= 12 */
/* Indeks matriks yang digunakan: [0..ROW_CAP-1][0..COL_CAP-1] */
/* Memori matriks yang dipakai selalu di "ujung kiri atas" */

/**
 * @brief Constructor Matriks
 * @param nRows: Banyak baris
 * @param nCols: Banyak kolom
 * @param m: Matriks(Peta)
 * @return Terbentuk Sebuah Matriks kosong berukuran nRows x nCols
 */
void createMatriks(int nRows, int nCols, Matriks *m);

#define ROW_EFF(M) (M).rowEff
#define COL_EFF(M) (M).colEff
#define ELMT(M, i, j) (M).mem[(i)][(j)]

/**
 * @brief Mengirimkan true jika i, j adalah index yang valid untuk matriks apa pun
 *
 * @param i: Indeks baris
 * @param j: Indeks kolom
 * @return boolean
 */
boolean isMatriksIdxValid(int i, int j);

/**
 * @brief Mengirimkan indeks baris terbesar m
 *
 * @param m: Matriks
 * @return IdxType
 */
IdxType getLastIdxRow(Matriks m);

/**
 * @brief Mengirimkan Indeks kolom terbesar m
 *
 * @param m: Matriks
 * @return IdxType
 */
IdxType getLastIdxCol(Matriks m);

/**
 * @brief Mengirimkan true jika i, j adalah Indeks efektif bagi m
 *
 * @param m: Matriks
 * @param i: Indeks baris
 * @param j: Indeks kolom
 * @return boolean
 */
boolean isIdxEff(Matriks m, IdxType i, IdxType j);

/**
 * @brief Melakukan assignment mOut <- mIn
 *
 * @param mIn: Matriks yang akan dicopy
 * @param mOut: Matriks hasil copy
 * @return Matriks mOut terdefinisi dan merupakan salinan dari mIn
 */
void copyMatriks(Matriks mIn, Matriks *mOut);

/**
 * @brief Melakukan CreateMatrix(m,nRow,nCol) dan mengisi nilai efektifnya
 *
 * @param m: Matriks
 * @param namaFile: namaFile konfigurasi
 * @param lokasiSimulator: titik koordinat simulator
 * @param MIX: AksiLokasi mix
 * @param BOIL: AksiLokasi boil
 * @param CHOP: AksiLokasi chop
 * @param FRY: AksiLokasi fry
 * @param TELEPON: AksiLokasi telepon
 * @param KULKAS: AksiLokasi kulkas
 * @return m terdefinisi nilai elemen efektifnya, berukuran nRow x nCol
 */
void readMatriks(Matriks *m, char namaFile[], POINT *lokasiSimulator, AksiLokasi *MIX, AksiLokasi *BOIL, AksiLokasi *CHOP, AksiLokasi *FRY, AksiLokasi *TELEPON, AksiLokasi *KULKAS);

/**
 * @brief Menulis nilai setiap elemen m ke layar dengan traversal per baris dan per kolom
 *
 * @param m: Matriks(peta)
 * @return Nilai m(i,j) ditulis ke layar per baris per kolom, masing-masing elemen per baris
   dipisahkan sebuah spasi
 */
void displayMatriks(Matriks m);

/**
 * @brief Mengembalikan true jika pada koordinat p terdapat batas(*), tembok(X), lokasi suatu tempat(T,M,F,C,B)
 *
 * @param m: Matriks(peta)
 * @param p: Koordinat pada peta yang akan dicek
 * @return boolean
 */
boolean isCollide(Matriks m, POINT p);

/**
 * @brief Mengembalikan True jika titik P adalah border
 * @param m: Peta
 * @param p: Titik
 * @return boolean
 */
boolean isBorder(Matriks m, POINT p);

/**
 * @brief Memindahkan posisi simulator menuju koordinat p dan mengubah posisi sebelumnya menjadi blank
 *
 * @param m: Matriks(peta)
 * @param lokasiSimulator: Lokasi Simulator
 * @param p: koordinat tujuan
 */
void moveSimulator(Matriks *m, POINT *lokasiSimulator, POINT p);

#endif