#include "../ADT/Matriks/matriks.h"
#include "../ADT/ListStatMakanan/lstatmakanan.h"
#include "../ADT/Tree/tree.h"

/**
 * @brief Me-load file konfigurasi ke variabel-variabel yang dipakai di dalam aplikasi
 *
 * @param peta Matriks berisi pointer ke variabel peta yang digunakan di dalam aplikasi
 * @param lSMakanan pointer ke daftar makanan yang berisi
 * @param lNMakanan
 * @param lokasiSimulator
 * @param MIX
 * @param BOIL
 * @param CHOP
 * @param FRY
 * @param TELEPON
 */
void loader(Matriks *peta, LStatMakanan *lSMakanan, ListNode *lNMakanan, POINT *lokasiSimulator, AksiLokasi *MIX, AksiLokasi *BOIL, AksiLokasi *CHOP, AksiLokasi *FRY, AksiLokasi *TELEPON);