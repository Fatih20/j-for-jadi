#include "Loader.h"

void loader(Matriks *peta, LStatMakanan *lSMakanan, ListNode *lNMakanan, POINT *lokasiSimulator, AksiLokasi *MIX, AksiLokasi *BOIL, AksiLokasi *CHOP, AksiLokasi *FRY, AksiLokasi *TELEPON)
{
    readMatriks(peta, "../../../config/peta.txt", lokasiSimulator, MIX, BOIL, CHOP, FRY, TELEPON);
    AksiLokasi aLArray[5] = {*MIX, *BOIL, *CHOP, *FRY, *TELEPON};
    readLStatMakanan(lSMakanan, "../../../config/makanan.txt", aLArray);
    readListNode(lNMakanan, "../../../config/resep.txt", *lSMakanan);
}