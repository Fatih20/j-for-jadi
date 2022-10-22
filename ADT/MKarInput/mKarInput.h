/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef mKarInput
#define mKarInput

#include "../boolean.h"

#define MARK '\n'
/* State Mesin */
extern char currentChar;
extern boolean EOP;

/**
 * @brief Menyiapkan mesin untuk pengoperasian dan pita untuk dibaca. Pembaca karakter ada pada karakter pertama setelah fungsi dijalankan.
 *
 */
void startMKInput();

/**
 * @brief Memajukan pita satu karakter. Menyalakan EOP jika karakter selanjutnya adalah MARK.
 *
 */
void advMKInput();

#endif