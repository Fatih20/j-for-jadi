/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef mCInput
#define mCInput

#include "../boolean.h"

/**
 * @brief Penanda bahwa input untuk MKI selesai
 *
 */
#define MARKI '\n'

/**
 * @brief Karakter yang sekarang sedang dibaca MKI
 *
 */
extern char currentCharI;

/**
 * @brief Apakah MKI telah berhenti karena menemukan MARK
 *
 */
extern boolean EOPI;

/**
 * @brief Menyiapkan mesin untuk pengoperasian dan pita untuk dibaca. Pembaca karakter ada pada karakter pertama setelah fungsi dijalankan.
 *
 */
void startMCInput();

/**
 * @brief Memajukan pita satu karakter. Menyalakan EOP jika karakter selanjutnya adalah MARK.
 *
 */
void advMCInput();

#endif