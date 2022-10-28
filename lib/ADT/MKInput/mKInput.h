/* File: wordmachine.h */
/* Definisi Word Machine: Model Akuisisi Versi I */

#ifndef mKInput
#define mKInput

#include "../boolean.h"
#include "../MCInput/mCInput.h"
#include "../Teks/teks.h"

#define BLANK ' '

/**
 * @brief Mesin masih berjalan atau tidak
 *
 */
extern boolean endMKI;

/**
 * @brief Kata yang sedang dibaca oleh mesin.
 *
 */
extern Teks currentWord;

/**
 * @brief Mengabaikan satu atau beberapa BLANK. currentChar bukan blank setelah dijalankan, bisa MARKI.
 *
 */
void ignoreBlanksI();

/**
 * @brief Menyiapkan mesin untuk pengoperasian dan pita untuk dibaca. Pembaca kata ada pada kata pertama setelah fungsi dijalankan. Bisa langsung berhenti jika hanya satu kata dilanjutkan MARKI.
 *
 */
void startMKInput();

/**
 * @brief Memajukan pembacaan ke kata selanjutnya. Dapat menyebabkan mesin berhenti jika kata selanjutnya MARKI.
 *
 */
void advMKInput();

/**
 * @brief Menyimpan kata yang sedang diperiksa. Mesin harus sudah berada pada karakter kata pertama sebelum fungsi dijalankan.
 *
 */
void saveKataI();

#endif