/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef mBFile
#define mBFile

#include "../boolean.h"
#include "../MCFile/mCFile.h"
#include "../MKFile/mKFile.h"
#include "../ListDinTeks/ldinteks.h"
#include "../Teks/teks.h"

/**
 * @brief Mesin masih berjalan atau tidak
 *
 */
extern boolean endMBF;

/**
 * @brief Baris yang sedang dibaca oleh mesin.
 *
 */
extern LDinTeks currentRow;

/**
 * @brief Kata yang sekarang merupakan BLANKFB yang didefinisikan di dalam fungsi ini. BLANKFB adalah kata yang hanya merupakan newLine.
 * @param t kata yang dicek apakah BLANKF atau tidak
 *
 */
boolean isBlankFB(Teks t);

/**
 * @brief Mengabaikan satu atau beberapa BLANKFB. currentWord bukan BLANKFB setelah dijalankan, bisa MARKF.
 *
 */
void ignoreBlanksFB();

/**
 * @brief Menyiapkan mesin baris untuk pengoperasian dan pita untuk dibaca. Pembaca baris ada pada baris pertama setelah fungsi dijalankan. Bisa langsung berhenti jika hanya satu kata dilanjutkan MARKF.
 * @param namaFile file yang akan dibaca. Gunakan directory file relatif pada directory program, bukan nama file saja.
 *
 */
void startMBFile(char namaFile[]);

/**
 * @brief Memajukan pembacaan ke baris selanjutnya. Dapat menyebabkan mesin berhenti jika kata selanjutnya MARKF.
 *
 */
void advMBFile();

/**
 * @brief Menyimpan baris yang sedang diperiksa. Mesin harus sudah berada pada kata pertama baris yang ingin dijalankan sebelum fungsi dijalankan.
 *
 */
void saveBarisF();

#endif