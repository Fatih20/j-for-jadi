#include "../boolean.h"
#include "../MCInput/mCInput.h"
#include "../MKInput/mKInput.h"
#include "../Teks/teks.h"
#include "../ListDinTeks/ldinteks.h"

#ifndef mBInput
#define mBInput

/**
 * @brief Mesin masih berjalan atau tidak
 *
 */
extern boolean endMBI;

/**
 * @brief Baris yang sudah dibaca mesin
 *
 */
extern LDinTeks currentRowI;

/**
 * @brief Menyiapkan mesin untuk pengoperasian dan pita untuk dibaca. Pembaca kata ada pada kata pertama setelah fungsi dijalankan. Bisa langsung berhenti jika hanya satu kata dilanjutkan MARKI.
 *
 */
void startMBInput();

/**
 * @brief Memajukan pembacaan ke kata selanjutnya. Dapat menyebabkan mesin berhenti jika kata selanjutnya MARKI.
 *
 */
void advMBInput();

/**
 * @brief Menyimpan kata yang sedang diperiksa. Mesin harus sudah berada pada karakter kata pertama sebelum fungsi dijalankan.
 *
 */
void saveBarisI();

#endif