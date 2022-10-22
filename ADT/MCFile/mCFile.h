/* File: charmachine.h */
/* Definisi Mesin Karakter */

#ifndef mCFile
#define mCFile

#include "../boolean.h"

/**
 * @brief Penanda bahwa input untuk MKF selesai
 *
 */
#define MARKF '.'

/**
 * @brief Karakter yang sekarang sedang dibaca MKF
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
 * @param namaFile file yang akan dibaca. Gunakan directory file relatif pada directory program, bukan nama file saja.
 *
 */
void startMCFile(char namaFile[]);

/**
 * @brief Memajukan pita satu karakter. Menyalakan EOP jika karakter selanjutnya adalah MARK.
 *
 */
void advMCFile();

#endif