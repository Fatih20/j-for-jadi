#include "../boolean.h"
#include "../Teks/teks.h"
#include "../Makanan/makanan.h"

#ifndef setid_H
#define setid_H

#define capacitySetID 1000
#define IDX_MIN 0
#define IDX_UNDEF -1

typedef makananID setIDEl;
typedef int SetIdxType;

/**
 * @brief ADT SetID yang menyimpan daftar idTipe makanan
 * Representasi yang digunakan adalah array statik implisit rata kiri
 * Indeks yang digunakan [0..capacitySetID-1]
 * Definisi :
   Set kosong: semua elemen bernilai MARK
   Definisi elemen pertama: elmtSetID(S,i) dengan i=0
 *
 */
typedef struct
{
  setIDEl idTipe[capacitySetID];
} SetID;

/* ********** SELEKTOR ********** */
#define elmtSetID(S, i) (S).idTipe[(i)]

/**
 * @brief Mengembalikan MARK
 *
 * @return MARK
 */
setIDEl getMarkSetID();

/**
 * @brief Konstruktor : Set kosong
 *
 * @param S
 */
void createSet(SetID *S);

/**
 * @brief Mengirimkan true jika Set S kosong, mengirimkan false jika tidak
 *
 * @param S
 * @return boolean
 */
boolean isEmptySet(SetID S);

/**
 * @brief mengembalikan banyaknya elemen dalam set
 *
 * @param S set yang dicek jumlah elemennya
 * @return int yang mewakili jumlah elemen set
 */
int lengthSet(SetID S);

/**
 * @brief menambahkan satu elemen ke dalam Set
 *
 * @param S set yang akan ditambahkan satu elemen ke dalamnya
 * @param val elemen yang akan ditambahkan ke dalam set
 *
 * @return set yang bertambah elemennya jika val belum ada di dalam set
 */
void addElmtSet(SetID *S, setIDEl val);

/**
 * @brief menghapus satu elemen dari dalam set
 *
 * @param S set yang akan dihapus salah satu elemennya
 * @param val elemen yang akan dihapus dari set
 *
 * @return set yang berkurang elemennya jika val ada di dalam set
 */
void removeElmtSet(SetID *S, setIDEl val);

/**
 * @brief mengecek apakah ada val di dalam set
 *
 * @param S set yang akan dicek
 * @param val elemen yang akan dicari di dalam set
 *
 * @return boolean apakah val ada di dalam S
 */
boolean isElmtInSet(SetID S, setIDEl val);

/**
 * @brief mengecek apakah ada dua set adalah sama
 *
 * @param S1 set pertama
 * @param S2 set kedua
 *
 * @return boolean apakah S1 sama dengan S2
 */
boolean isSetEqual(SetID S1, SetID S2);

/**
 * @brief menggabungkan dua buah set
 * @param S1 set pertama
 * @param S2 set kedua
 *
 * @return S3 yang merupakan sebuah set hasil operasi union S1 dan S2
 */
SetID setUnion(SetID S1, SetID S2);

/**
 * @brief Fungsi untuk mencari irisan dari dua buah set
 * @param S1 set pertama
 * @param S2 set kedua
 *
 * @return S3 yang merupakan sebuah set hasil operasi intersection S1 dan S2
 */
SetID setIntersection(SetID S1, SetID S2);

/**
 * @brief Fungsi untuk mencari set difference dari dua buah set
 * @param S1 set pertama
 * @param S2 set kedua
 *
 * @return S3 yang merupakan S1 dikurangi S2
 */
SetID setDifference(SetID S1, SetID S2);

/**
 * @brief Fungsi untuk menyalin isi dari suatu set ke set baru
 * @param S set yang akan disalin
 *
 * @return set copy yang merupakan hasil salinan dari set S1
 */
SetID copySet(SetID S);

/**
 * @brief Fungsi untuk mengecek subset
 * @param S1 set pertama
 * @param S2 set kedua
 *
 * @return mengembalikan true jika S1 adalah subset dari S2
 */
boolean isSubset(SetID S1, SetID S2);

/**
 * @brief Menuliskan isi set ID dengan format [e1,e2,...,en] tanpa diakhiri enter
 *
 * @param S
 */
void printSetID(SetID S);

#endif