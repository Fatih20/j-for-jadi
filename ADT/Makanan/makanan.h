#ifndef makanan_H
#define makanan_H

typedef int makananID;

/**
 * @brief Makanan yang menjadi fokus dari tubes ini
 * @param nama nama makanan yang dibatasi 100 karakter
 * @param id id untuk tiap makanan yang 3 digit pertamanya adalah identifier tipe dan 3 digit sisanya adalah unique identifier. Mirip seperti NIM
 * @param waktuSampai waktu sebuah makanan sampai pada BNMO. Jika makanan ada di inventory, memiliki nilai 0.
 * @param waktuBasi waktu sebuah makanan basi. Jika makanan ada di queue pengiriman, makanan memiliki waktuBasi default sesuai konfigurasi file yang tidak dipengaruhi waktu selama dikirim.
 */
typedef struct
{
    /// @brief Nama makanan yang dibatasi 100 karakter
    char nama[100]; // Nama makanan
    makananID id;
    int waktuBasi;
    int waktuSampai;
} Makanan;

#define namaMakanan(S) (S).nama
#define basiDalam(S) (S).waktuBasi
#define sampaiDalam(S) (S).waktuSampai
#define IDDari(S) (S).id

/**
 * @brief Fungsi untuk menginisialisasi makanan
 * @param makanan pointer ke makanan yang ingin dibuat
 * @param waktuBasi waktuBasi yang akan diberikan ke makanan yang dibuat
 * @param waktuSampai waktuSampai yang akan diberikan ke makanan yang dibuat
 * @param idBaru id dari makanan yang dibuat
 *
 * @return Makanan pada address yang diberikan terdefinisi dengan parameter yang diberikan
 */
void buatMakanan(Makanan *makanan, char *namaMakanan, int waktuBasi, int waktuSampai, makananID idBaru);

#endif