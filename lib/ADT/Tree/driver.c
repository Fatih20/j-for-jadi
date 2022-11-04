#include <stdio.h>
#include "tree.h"

int main()
{
    ListNode t;
    LStatMakanan daftarMakanan;
    AksiLokasi al;
    buatLStatMakanan(&daftarMakanan);
    readLStatMakanan(&daftarMakanan, "../../../config/tc1/makanan.txt", &al);
    printLStatMakanan(daftarMakanan);
    readListNode(&t, "../../../config/tc1/resep.txt", daftarMakanan);
    displayListNode(t);
    printf("%d", ListNodeNEff(t));
    // Teks minyak;
    // buatTeks("Minyak Goreng", &minyak);
    // Teks ayamTepung;
    // buatTeks("Ayam Tepung", &ayamTepung);
    // LDinTeks temp;
    // buatLDinTeks(&temp, 5);
    // insertLastLDinTeks(&temp, minyak);
    // insertLastLDinTeks(&temp, ayamTepung);
    /* UNTUK VALIDASI MAKANAN */
    // Address jadiApa;
    // jadiApa = getParent(t, temp);
    // cetakTeks(minyak);
    // printf(" + ");
    // cetakTeks(ayamTepung);
    // printf(" = ");
    // cetakTeks(MakananTree(jadiApa));
}