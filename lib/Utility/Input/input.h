/**
 * @brief Fungsi untuk meminta masukan angka dari pengguna. Melakukan validasi input dengan meminta ulang sampai masukan benar.
 *
 * @param min Nilai minimum yang bisa dimasukkan
 * @param max Nilai maximum yang bisa dimasukkan
 * @param prompt Teks yang ditampilkan untuk meminta masukan
 * @return int
 */
int askForNumber(int min, int max, char prompt[]);

/**
 * @brief Fungsi untuk meminta masukan angka dari pengguna. Melakukan validasi input dengan meminta ulang sampai masukan benar.
 *
 * @param max Nilai maximum yang bisa dimasukkan
 * @param prompt Teks yang ditampilkan untuk meminta masukan
 * @return int
 */
int askForNumberNMin(int max, char prompt[]);

/**
 * @brief Fungsi untuk meminta masukan angka dari pengguna. Melakukan validasi input dengan meminta ulang sampai masukan benar.
 *
 * @param min Nilai minimum yang bisa dimasukkan
 * @param prompt Teks yang ditampilkan untuk meminta masukan
 * @return int
 */
int askForNumberNMax(int min, char prompt[]);