#include "../ListTree/listtree.h"
#include <stdio.h>

int main()
{
    ListTree t;
    LStatMakanan daftarMakanan;
    buatLStatMakanan(&daftarMakanan);
    readLStatMakanan(&daftarMakanan, "../../../config/makanancfg.txt");
    printLStatMakanan(daftarMakanan);
    readListTree(&t, "../../../config/resepcfg.txt", daftarMakanan);
    displayListTree(t);
    Teks minyak;
    buatTeks("Minyak Goreng", &minyak);
    Teks ayamTepung;
    buatTeks("Ayam Tepung", &ayamTepung);
    LDinTeks temp;
    buatLDinTeks(&temp, 5);
    insertLastLDinTeks(&temp, minyak);
    insertLastLDinTeks(&temp, ayamTepung);
    /* UNTUK VALIDASI MAKANAN */
    Address jadiApa;
    jadiApa = getParent(t, temp);
    cetakTeks(minyak);
    printf(" + ");
    cetakTeks(ayamTepung);
    printf(" = ");
    cetakTeks(MakananTree(jadiApa));
}