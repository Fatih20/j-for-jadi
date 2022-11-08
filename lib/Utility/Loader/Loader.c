#include "Loader.h"
#include "../String/String.h"
#include "../../ADT/Teks/teks.h"
#include <string.h>

void loader(Matriks *peta, LStatMakanan *lSMakanan, ListNode *lNMakanan, POINT *lokasiSimulator, AksiLokasi *MIX, AksiLokasi *BOIL, AksiLokasi *CHOP, AksiLokasi *FRY, AksiLokasi *TELEPON, AksiLokasi *KULKAS, Teks alamatFolder)
{

    Teks namaPeta;
    buatTeks("/peta.txt", &namaPeta);
    Teks namaMakanan;
    buatTeks("/makanan.txt", &namaMakanan);
    Teks namaResep;
    buatTeks("/resep.txt", &namaResep);

    Teks alamatPetaT;
    Teks alamatResepT;
    Teks alamatMakananT;
    gabungkanTeks(alamatFolder, namaPeta, &alamatPetaT);
    gabungkanTeks(alamatFolder, namaMakanan, &alamatMakananT);
    gabungkanTeks(alamatFolder, namaResep, &alamatResepT);

    char alamatPeta[panjangT(alamatPetaT) + 1];
    char alamatResep[panjangT(alamatResepT) + 1];
    char alamatMakanan[panjangT(alamatMakananT) + 1];

    teksKeString(alamatPeta, alamatPetaT);
    teksKeString(alamatMakanan, alamatMakananT);
    teksKeString(alamatResep, alamatResepT);

    readMatriks(peta, alamatPeta, lokasiSimulator, MIX, BOIL, CHOP, FRY, TELEPON, KULKAS);
    AksiLokasi aLArray[5] = {*MIX, *BOIL, *CHOP, *FRY, *TELEPON};
    buatLStatMakanan(lSMakanan);
    readLStatMakanan(lSMakanan, alamatMakanan, aLArray);
    readListNode(lNMakanan, alamatResep, *lSMakanan);
}