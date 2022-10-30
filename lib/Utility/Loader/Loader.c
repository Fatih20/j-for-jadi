#include "Loader.h"

void loader(Matriks *peta, LStatMakanan *lSMakanan, ListNode *lNMakanan, POINT *lokasiSimulator, AksiLokasi *MIX, AksiLokasi *BOIL, AksiLokasi *CHOP, AksiLokasi *FRY, AksiLokasi *TELEPON)
{
    char alamatPeta[] = "config/peta.txt";
    char alamatMakanan[] = "config/makanan.txt";
    char alamatResep[] = "config/resep.txt";
    readMatriks(peta, alamatPeta, lokasiSimulator, MIX, BOIL, CHOP, FRY, TELEPON);
    AksiLokasi aLArray[5] = {*MIX, *BOIL, *CHOP, *FRY, *TELEPON};
    buatLStatMakanan(lSMakanan);
    readLStatMakanan(lSMakanan, alamatMakanan, aLArray);
    readListNode(lNMakanan, alamatResep, *lSMakanan);
}