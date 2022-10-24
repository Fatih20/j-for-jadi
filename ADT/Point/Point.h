#ifndef POINT_H
#define POINT_H

#include "../boolean.h"

/**
 * @brief Tipe Data Point <X,Y>
 * @param X: Absis dari suatu Point
 * @param Y: Ordinat dari suatu Point
 */
typedef struct
{
    int X; /* absis   */
    int Y; /* ordinat */
} POINT;

/**
 * @brief Notasi Akses: Selektor POINT
 *
 */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/**
 * @brief Membentuk sebuah POINT dari komponen-komponennya
 * @param P: POINT
 * @param X: int
 * @param Y: int
 * @return Terbentuk Point (X,Y) yang terdefinisi nilainya
 */
void CreatePoint(POINT *P, int X, int Y);

/**
 * @brief Membaca nilai absis dan ordinat dari keyboard dan membentuk
   POINT P berdasarkan dari nilai absis dan ordinat tersebut
 * @param P: POINT
 * @return P terdefinisi
 */
void BacaPOINT(POINT *P);

/**
 * @brief Nilai P ditulis ke layar dengan format "(X,Y)"
 * @param P: POINT
 * @return P tertulis di layar dengan format "(X,Y)"
 */
void TulisPOINT(POINT P);

/**
 * @brief Mengirimkan true jika P1 = P2 : absis dan ordinatnya sama
 * @param P1: POINT
 * @param P2: POINT
 * @return boolean
 */
boolean EQ(POINT P1, POINT P2);

/**
 * @brief Mengirimkan true jika P1 tidak sama dengan P2
 * @param P1: POINT
 * @param P2: POINT
 * @return boolean
 */
boolean NEQ(POINT P1, POINT P2);

/**
 * @brief Mengembalikan true jika dua buah titik bersebelahan
 * @param P1: Titik 1
 * @param P2: Titik 2 
 * @return boolean 
 */
boolean IsAdjacent(POINT P1, POINT P2);

/**
 * @brief Menghasilkan true jika P adalah titik origin
 * @param P: POINT
 * @return boolean
 */
boolean IsOrigin(POINT P);

/**
 * @brief Menghasilkan true jika P terletak Pada sumbu X
 * @param P: POINT
 * @return boolean
 */
boolean IsOnSbX(POINT P);

/**
 * @brief Menghasilkan true jika P terletak pada sumbu Y
 * @param P: POINT
 * @return boolean
 */
boolean IsOnSbY(POINT P);

/**
 * @brief Menghasilkan kuadran dari P: 1, 2, 3, atau 4
 * @param P: POINT
 * @return int
 */
int Kuadran(POINT P);

/**
 * @brief Mengirim salinan P dengan absis ditambah satu
 * @param P: POINT
 * @return POINT
 */
POINT NextX(POINT P);

/**
 * @brief Mengirim salinan P dengan ordinat ditambah satu
 * @param P: POINT
 * @return POINT
 */
POINT NextY(POINT P);

/**
 * @brief Mengirim salinan P yang absisnya adalah Absis(P) + deltaX dan ordinatnya adalah Ordinat(P) + deltaY
 * @param P: POINT
 * @param deltaX: Pergeseran terhadap sumbu-x
 * @param deltaY: Pergeseran terhadap sumbu-y
 * @return POINT
 */
POINT PlusDelta(POINT P, int deltaX, int deltaY);

/**
 * @brief Menghasilkan salinan P yang dicerminkan terhadap salah satu sumbu. Jika SbX bernilai true, maka dicerminkan terhadap sumbu X, jika tidak, maka dicerminkan terhadap sumbu Y
 * @param P: POINT
 * @param SbX: Apakah dicerminkan terhadap sumbu X atau tidak
 * @return POINT
 */
POINT MirrorOf(POINT P, boolean SbX);

/**
 * @brief Menghitung jarak P ke (0,0)
 * @param P: POINT
 * @return float
 */
float Jarak0(POINT P);

/**
 * @brief Menghitung panjang garis yang dibentuk P1 dan P2
 *
 * @param P1: POINT
 * @param P2: POINT
 * @return float
 */
float Panjang(POINT P1, POINT P2);

/**
 * @brief Menggeser absis P sebesar deltaX dan ordinatnya sebesar deltaY
 * @param P: POINT
 * @param deltaX: Pergeseran terhadap sumbu X
 * @param deltaY: Pergeseran terhadap sumbu Y
 * @return P digeser, absisnya sebesar deltaX dan ordinatnya sebesar deltaY
 */
void Geser(POINT *P, int deltaX, int deltaY);

/**
 * @brief Menggeser P ke sumbu X dengan Absis yang sama
 * @param P: POINT
 * @return P berada pada sumbu X dengan absis sama dengan absis semula
 */
void GeserKeSbX(POINT *P);
/**
 * @brief Menggeser P ke sumbu Y dengan Ordinat yang sama
 * @param P: POINT
 * @return P berada pada sumbu Y dengan Ordinat sama dengan Ordinat semula
 */
void GeserKeSbY(POINT *P);

/**
 * @brief Mencerminkan P terhadap sumbu X jika SbX true, mencerminkan terhadap sumbu Y jika SbX false
 * @param P: POINT
 * @param SbX: boolean
 * @return P dicerminkan tergantung nilai SbX atau SbY
 */
void Mirror(POINT *P, boolean SbX);

#endif
