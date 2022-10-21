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
} Point;

/**
 * @brief Notasi Akses: Selektor POINT
 *
 */
#define Absis(P) (P).X
#define Ordinat(P) (P).Y

/**
 * @brief Membentuk sebuah POINT dari komponen-komponennya
 * @param P: Pointer to Point
 * @param X: int
 * @param Y: int
 * @return Terbentuk Point (X,Y) yang terdefinisi nilainya
 */
void CreatePoint(Point *P, int X, int Y);

/**
 * @brief Menggeser Point ke Barat sejauh 1 satuan (x,y) -> (x-1,y)
 * @param P: Pointer to Point
 * @return Point bergeser ke Barat sejauh 1 satuan
 */
void moveWest(Point *P);
/**
 * @brief Menggeser Point ke Utara sejauh 1 satuan (x,y) -> (x,y+1)
 * @param P: Pointer to Point
 * @return Point bergeser ke Utara sejauh 1 satuan
 */
void moveNorth(Point *P);
/**
 * @brief Menggeser Point ke Timur sejauh 1 satuan (x,y) -> (x+1,y)
 * @param P: Pointer to Point
 * @return Point bergeser ke Timur sejauh 1 satuan
 */
void moveEast(Point *P);
/**
 * @brief Menggeser Point ke Selatan sejauh 1 satuan (x,y) -> (x,y-1)
 * @param P: Pointer to Point
 * @return Point bergeser ke Selatan sejauh 1 satuan
 */
void moveSouth(Point *P);

#endif
