/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef mKFile
#define mKFile

#include "../boolean.h"
#include "../MCFile/mCFile.h"
#include "../Teks/teks.h"

/**
 * @brief Mesin masih berjalan atau tidak
 *
 */
extern boolean endMKF;

/**
 * @brief Kata yang sedang dibaca oleh mesin.
 *
 */
extern Teks currentWord;

/**
 * @brief Karakter sekarang merupakan BLANKF yang didefinisikan di dalam fungsi ini. BLANKF adalah spasi atau newline.
 * @param c karakter yang dicek apakah BLANK atau tidak
 *
 */
boolean isBlankF(char c);

/**
 * @brief Mengabaikan satu atau beberapa BLANK. currentChar bukan blank setelah dijalankan, bisa MARKF.
 *
 */
void ignoreBlanksF();

/**
 * @brief Menyiapkan mesin untuk pengoperasian dan pita untuk dibaca. Pembaca kata ada pada kata pertama setelah fungsi dijalankan. Bisa langsung berhenti jika hanya satu kata dilanjutkan MARKF.
 * @param namaFile file yang akan dibaca. Gunakan directory file relatif pada directory program, bukan nama file saja.
 *
 */
void startMKFile(char namaFile[]);

/**
 * @brief Memajukan pembacaan ke kata selanjutnya. Dapat menyebabkan mesin berhenti jika kata selanjutnya MARKF.
 *
 */
void advMKFile();

/**
 * @brief Menyimpan kata yang sedang diperiksa. Mesin harus sudah berada pada karakter kata pertama sebelum fungsi dijalankan.
 *
 */
void saveKataF();

#endif