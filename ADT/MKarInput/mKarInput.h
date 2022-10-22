/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef mKarInput
#define mKarInput

#include "../boolean.h"

/**
 * @brief Penanda bahwa input untuk MKI selesai
 *
 */
#define MARK '\n'

/**
 * @brief Karakter yang sekarang sedang dibaca MKI
 *
 */
extern char currentChar;

/**
 * @brief Apakah MKI telah berhenti karena menemukan MARK
 *
 */
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