#include <stdio.h>
#include "kulkas.h"

void buatKulkas(Kulkas *k)
{
    // KAMUS
    int i, j;

    // ALGORITMA

    // inisiasi matriks dengan nilai Nil
    for (i = 0; i < LebarKulkas; i++)
    {
        for (j = 0; j < PanjangKulkas; j++)
        {
            isiKulkas(*k, i, j) = Nil;
        }
    }

    // inisiasi free space
    sisaKapasitas(*k) = PanjangKulkas * LebarKulkas;

    // inisiasi listdin makanan
    buatLDinMakanan(&makananKulkas(*k), sisaKapasitas(*k));
}

void cetakKulkas(Kulkas k)
{
    cetakIsiKulkas((k).isi);
    cetakListMakananKulkas(k);
}

void cetakIsiKulkas(IsiKulkas k)
{
    // KAMUS
    int i, j;
    char coloredKulkas[3];

    // ALGORITMA
    printSGreen("Isi Kulkas :\n");
    printf("     ");
    for (i = 1; i <= PanjangKulkas; i++)
    {
        if (i < 10)
        {
            printf("%d  ", i);
        }
        else
        {
            printf("%d ", i);
        }
    }
    printf("\n");
    printSBlue("    -");
    for (i = 1; i <= PanjangKulkas; i++)
    {
        printSBlue("---");
    }
    printf("\n");
    for (i = 0; i < LebarKulkas; i++)
    {
        if (i < 9)
        {
            printf("%d", i + 1);
            printSBlue("  | ");
        }
        else
        {
            printf("%d", i + 1);
            printSBlue(" | ");
        }

        for (j = 0; j < PanjangKulkas; j++)
        {
            if (aksesIsiKulkas(k, i, j) == Nil)
            {
                printf("0  ");
            }
            else
            {
                printColored(aksesIsiKulkas(k, i, j) + 1);
            }
        }
        printSBlue("|\n");
    }
    printSBlue("    -");
    for (i = 1; i <= PanjangKulkas; i++)
    {
        printSBlue("---");
    }
    printf("\n");
}

void printColored(int val)
{
    char charVal;
    if (val > 99)
    {
        charVal = (char)(val / 100 + 48);
        printCyan(charVal);
        val = val - (val / 100) * 100;
        charVal = (char)(val / 10 + 48);
        printCyan(charVal);
        val = val - (val / 10) * 10;
        charVal = (char)(val + 48);
        printCyan(charVal);
    }
    else if (val > 9)
    {
        charVal = (char)(val / 10 + 48);
        printCyan(charVal);
        val = val - (val / 10) * 10;
        charVal = (char)(val + 48);
        printCyan(charVal);
        charVal = ' ';
        printCyan(charVal);
    }
    else
    {
        charVal = (char)(val + 48);
        printCyan(charVal);
        charVal = ' ';
        printCyan(charVal);
        charVal = ' ';
        printCyan(charVal);
    }
}

void cetakListMakananKulkas(Kulkas k)
{
    printSGreen("Keterangan :\n");
    if (!isEmptyLDinMakanan(makananKulkas(k)))
    {
        for (int i = 0; i < panjangLDinMakanan(makananKulkas(k)); i++)
        {
            printf("%d.", i + 1);
            printSCyan(" Nama makanan: ");
            cetakTeks(namaMakanan(elmtLDM(makananKulkas(k), i)), 'b');
            printf("\n");
            printSCyan("   ID makanan: ");
            cetakTeks(idUnik(elmtLDM(makananKulkas(k), i)), 'c');
        }
        printf("\n\n");
    }
    else
    {
        printf("Kulkas kosong.\n");
    }
}

void tambahIsiKulkas(Kulkas *k, Makanan makanan)
{
    // KAMUS
    int i, j, idx;
    int panjang = panjang(makanan);
    int lebar = lebar(makanan);
    int luas = luasMakanan(makanan);
    int pilihanX, pilihanY;
    boolean inputTrue, horizontal, vertikal;

    // ALGORITMA

    // ini gunanya biar yang lebih panjang selalu 'panjang'
    if (lebar > panjang)
    {
        i = panjang;
        panjang = lebar;
        lebar = i;
    }

    // cek apakah dimensi makanan lebih besar dari kulkas
    if ((panjang > PanjangKulkas || lebar > LebarKulkas) && (lebar > PanjangKulkas || panjang > LebarKulkas))
    {
        printf("Maaf, makanan terlalu besar untuk kulkas.\n");
    }

    // kalau luasnya masih muat
    else if (luas < sisaKapasitas(*k))
    {
        inputTrue = true;
        while (inputTrue)
        {
            printSGreen("Masukkan ");
            printSRed("lokasi kiri atas");
            printSGreen(" kulkas yang diinginkan\n");
            printSGreen("(input ");
            printSRed("[0,0]");
            printSGreen(" untuk membatalkan proses)\n");
            printSRed("X : ");
            scanf("%d", &pilihanX);
            printSRed("Y : ");
            scanf("%d", &pilihanY);
            printf("\n");

            pilihanX--;
            pilihanY--;

            if (pilihanX == Nil && pilihanY == Nil)
            {
                inputTrue = false;
                printf("Proses dibatalkan.\n");
            }
            else if (isiKulkas(*k, pilihanY, pilihanX) == Nil)
            {
                // Cek apakah horizontal atau vertikal
                cekHorizontalVertical(&horizontal, &vertikal, *k, pilihanX, pilihanY, panjang, lebar);

                // Masukkin makanan ke lisdin
                if (horizontal || vertikal)
                {
                    inputTrue = false;
                    insertLastLDinMakanan(&makananKulkas(*k), makanan);
                    idx = lastIdxLDinMakanan(makananKulkas(*k));
                    printf("Makanan berhasil dimasukkan.\n");
                    sisaKapasitas(*k) -= luas;
                }

                // Horizontal
                if (horizontal)
                {
                    isiHorizontal(k, idx, pilihanX, pilihanY, panjang, lebar);
                }
                // Vertikal
                else if (vertikal)
                {
                    isiVertikal(k, idx, pilihanX, pilihanY, panjang, lebar);
                }
            }
            else
            {
                printf("Maaf, slot tersebut sudah diisi.\n");
            }
        }
    }
    else
    {
        printf("Maaf, kulkas telah penuh.\n");
    }
}

void keluarkanIsiKulkas(Kulkas *k, Makanan *makanan)
{
    // KAMUS
    int idxKeluar = Nil;
    int idxMax = panjangLDinMakanan(makananKulkas(*k));
    int i, j;

    // ALGORITMA
    if (sisaKapasitas(*k) != PanjangKulkas * LebarKulkas)
    {
        cetakKulkas(*k);
        while (idxKeluar < 0 || idxKeluar > idxMax)
        {
            printf("Pilih nomor makanan yang ingin dikeluarkan :\n");
            printf("(0 untuk membatalkan)\n");
            printf(":: ");
            scanf("%d", &idxKeluar);
            if (idxKeluar < 0 || idxKeluar > idxMax)
            {
                printf("Tidak ada makanan dengan nomor %d.\n\n", idxKeluar);
            }
        }
        if (idxKeluar)
        {
            idxKeluar--;
            removeAtLDinMakanan(&makananKulkas(*k), makanan, idxKeluar);
            sisaKapasitas(*k) += luasMakanan(*makanan);
            for (i = 0; i < LebarKulkas; i++)
            {
                for (j = 0; j < PanjangKulkas; j++)
                {
                    if (isiKulkas(*k, i, j) == idxKeluar)
                    {
                        isiKulkas(*k, i, j) = Nil;
                    }
                }
            }
            for (i = 0; i < LebarKulkas; i++)
            {
                for (j = 0; j < PanjangKulkas; j++)
                {
                    if (isiKulkas(*k, i, j) > idxKeluar)
                    {
                        isiKulkas(*k, i, j) -= 1;
                    }
                }
            }

            printf("Makanan ");
            cetakTeks(namaMakanan(*makanan), 'b');
            printf(" berhasil dikeluarkan.\n");
        }
        else
        {
            printf("Perubahan dibatalkan.\n\n");
        }
    }
    else
    {
        printf("Maaf, Kulkas kosong.\n\n");
    }
}

void ubahIsiKulkas(Kulkas *k)
{
    // KAMUS
    int pilihanIsiKulkas = Nil;
    int idxMax = panjangLDinMakanan(makananKulkas(*k));
    IsiKulkas isiBaru;
    int i, j;
    int pilihanX, pilihanY;
    boolean inputTrue, horizontal, vertikal;
    int panjang, lebar;

    // ALGORITMA
    if (sisaKapasitas(*k) != PanjangKulkas * LebarKulkas)
    {
        cetakKulkas(*k);
        while (pilihanIsiKulkas < 0 || pilihanIsiKulkas > idxMax)
        {
            printSGreen("Pilih nomor makanan yang ingin diubah posisinya:\n");
            printSRed("(0 untuk membatalkan)\n");
            printSGreen(":: ");
            scanf("%d", &pilihanIsiKulkas);
            if (pilihanIsiKulkas < 0 || pilihanIsiKulkas > idxMax)
            {
                printf("Tidak ada makanan dengan nomor %d.\n\n", pilihanIsiKulkas);
            }
        }
        if (pilihanIsiKulkas)
        {
            int panjang = panjang(elmtLDM((*k).makananKulkas, pilihanIsiKulkas - 1));
            int lebar = lebar(elmtLDM((*k).makananKulkas, pilihanIsiKulkas - 1));

            // Untuk jaga" kalau dibatalkan
            copyIsiKulkas(&isiBaru, &(*k).isi);

            for (i = 0; i < LebarKulkas; i++)
            {
                for (j = 0; j < PanjangKulkas; j++)
                {
                    if (isiKulkas(*k, i, j) == pilihanIsiKulkas - 1)
                    {
                        isiKulkas(*k, i, j) = Nil;
                    }
                }
            }
            cetakIsiKulkas((*k).isi);

            inputTrue = true;
            while (inputTrue)
            {
                printSGreen("Masukkan ");
                printSRed("lokasi kiri atas");
                printSGreen(" kulkas yang diinginkan\n");
                printSGreen("(input ");
                printSRed("[0,0]");
                printSGreen(" untuk membatalkan proses)\n");
                printSRed("X : ");
                scanf("%d", &pilihanX);
                printSRed("Y : ");
                scanf("%d", &pilihanY);
                printf("\n");

                pilihanX--;
                pilihanY--;

                if (pilihanX == Nil && pilihanY == Nil)
                {
                    inputTrue = false;
                    printf("Perubahan dibatalkan.\n");
                    copyIsiKulkas(&(*k).isi, &isiBaru);
                }
                else if (isiKulkas(*k, pilihanY, pilihanX) == Nil)
                {
                    // Cek apakah horizontal atau vertikal
                    cekHorizontalVertical(&horizontal, &vertikal, *k, pilihanX, pilihanY, panjang, lebar);

                    if (horizontal || vertikal)
                    {
                        inputTrue = false;
                        pilihanIsiKulkas--;
                    }
                    // Horizontal
                    if (horizontal)
                    {
                        isiHorizontal(k, pilihanIsiKulkas, pilihanX, pilihanY, panjang, lebar);
                    }
                    // Vertikal
                    else if (vertikal)
                    {
                        isiVertikal(k, pilihanIsiKulkas, pilihanX, pilihanY, panjang, lebar);
                    }
                }
                else
                {
                    printf("Maaf, slot tersebut sudah diisi.\n");
                }
            }
        }
        else
        {
            printf("Perubahan dibatalkan.\n\n");
        }
    }
    else
    {
        printf("Maaf, Kulkas kosong.\n");
    }
}

boolean cekHorizontal(Kulkas k, int pilihanX, int pilihanY, int panjang, int lebar)
{
    int i, j;
    boolean horizontal = true;

    i = pilihanY;
    j = pilihanX;

    if ((i + lebar) > LebarKulkas || (j + panjang) > PanjangKulkas)
    {
        horizontal = false;
    }
    while (horizontal && i < pilihanY + lebar)
    {
        if (isiKulkas(k, i, j) != Nil)
        {
            horizontal = false;
        }
        if (j == pilihanX + panjang - 1)
        {
            i++;
            j = pilihanX;
        }
        else
        {
            j++;
        }
    }
    return horizontal;
}

boolean cekVertikal(Kulkas k, int pilihanX, int pilihanY, int panjang, int lebar)
{
    int i, j;
    boolean vertikal = true;

    i = pilihanY;
    j = pilihanX;

    if ((i + panjang) > LebarKulkas || (j + lebar) > PanjangKulkas)
    {
        vertikal = false;
    }
    while (vertikal && i < pilihanY + panjang)
    {
        if (isiKulkas(k, i, j) != Nil)
        {
            vertikal = false;
        }
        if (j == pilihanX + lebar - 1)
        {
            i++;
            j = pilihanX;
        }
        else
        {
            j++;
        }
    }
    return vertikal;
}

void cekHorizontalVertical(boolean *horizontal, boolean *vertikal, Kulkas k, int pilihanX, int pilihanY, int panjang, int lebar)
{
    *horizontal = cekHorizontal(k, pilihanX, pilihanY, panjang, lebar);
    *vertikal = cekVertikal(k, pilihanX, pilihanY, panjang, lebar);
    if (!(*horizontal) && !(*vertikal))
    {
        printSGreen("Makanan tidak muat di lokasi tersebut.\n");
    }
    else if ((*horizontal) && (*vertikal) && (panjang != lebar))
    {
        printSGreen("Pilih opsi posisi makanan:\n");
        printSGreen("(1) ");
        printSRed("Horizontal\n");
        printSGreen("(2) ");
        printSRed("Vertikal\n");
        int opsi = 0;
        while (opsi != 1 && opsi != 2)
        {
            printSGreen("Pilihan: ");
            scanf("%d", &opsi);
            if (opsi != 1 && opsi != 2)
            {
                printSGreen("Masukan salah! Silahkan ulangi.\n");
            }
        }
        if (opsi == 1)
        {
            (*vertikal) = false;
        }
        else
        {
            (*horizontal) = false;
        }
    }
}

void isiVertikal(Kulkas *k, int idx, int pilihanX, int pilihanY, int panjang, int lebar)
{
    int i, j;
    for (i = pilihanY; i < pilihanY + panjang; i++)
    {
        for (j = pilihanX; j < pilihanX + lebar; j++)
        {
            isiKulkas(*k, i, j) = idx;
        }
    }
}

void isiHorizontal(Kulkas *k, int idx, int pilihanX, int pilihanY, int panjang, int lebar)
{
    int i, j;
    for (i = pilihanY; i < pilihanY + lebar; i++)
    {
        for (j = pilihanX; j < pilihanX + panjang; j++)
        {
            isiKulkas(*k, i, j) = idx;
        }
    }
}

void copyIsiKulkas(IsiKulkas *baru, IsiKulkas *lama)
{
    int panjangKulkas = PanjangKulkas;
    int lebarKulkas = LebarKulkas;
    int i, j;
    for (i = 0; i < lebarKulkas; i++)
    {
        for (j = 0; j < panjangKulkas; j++)
        {
            aksesIsiKulkas(*baru, i, j) = aksesIsiKulkas(*lama, i, j);
        }
    }
}