#include "Loader.h"
#include "../String/String.h"
#include <string.h>

void loader(Matriks *peta, LStatMakanan *lSMakanan, ListNode *lNMakanan, POINT *lokasiSimulator, AksiLokasi *MIX, AksiLokasi *BOIL, AksiLokasi *CHOP, AksiLokasi *FRY, AksiLokasi *TELEPON, char alamatFolder[])
{
    int panjangAF = stringLen(alamatFolder);
    char namaPeta[] = "/peta.txt";
    char namaMakanan[] = "/makanan.txt";
    char namaResep[] = "/resep.txt";

    printf("%d\n", stringLen(alamatFolder));
    printf("%d\n", stringLen(namaMakanan));
    char alamatPeta[panjangAF + stringLen(namaPeta) + 1];
    char alamatMakanan[panjangAF + stringLen(namaMakanan) + 1];
    char alamatResep[panjangAF + stringLen(namaResep) + 1];

    stringConcat(alamatFolder, namaPeta, alamatPeta);
    stringConcat(alamatFolder, namaMakanan, alamatMakanan);
    stringConcat(alamatFolder, namaResep, alamatResep);
    readMatriks(peta, alamatPeta, lokasiSimulator, MIX, BOIL, CHOP, FRY, TELEPON);
    AksiLokasi aLArray[5] = {*MIX, *BOIL, *CHOP, *FRY, *TELEPON};
    buatLStatMakanan(lSMakanan);
    readLStatMakanan(lSMakanan, alamatMakanan, aLArray);
    readListNode(lNMakanan, alamatResep, *lSMakanan);
}