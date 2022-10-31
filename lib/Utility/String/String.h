#include "../../ADT/boolean.h"

/**
 * @brief Membandingkan apakah string a dan b sama atau tidak
 *
 * @param a
 * @param b
 * @return boolean
 */
boolean stringSame(char a[], char b[]);

/**
 * @brief Menghasilkan panjang dari string a
 *
 * @param a
 * @return int panjang string a
 */
int stringLen(char a[]);

/**
 * @brief Menghasilkan gabungan string a dan b. Menyimpannya ke c.
 *
 * @param a
 * @param b
 * @param c Pointer ke string yang sudah dialokasikan punya panjang sebesar a dan b
 */
void stringConcat(char a[], char b[], char c[]);
