#include <stdint.h>
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
    cetakIsiKulkas(k);
    cetakListMakananKulkas(k);
}

void cetakIsiKulkas(Kulkas k)
{
    // KAMUS
    int i, j;

    // ALGORITMA
    printf("Isi Kulkas :\n");
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
    printf("    -");
    for (i = 1; i <= PanjangKulkas; i++)
    {
        printf("---", i);
    }
    printf("\n");
    for (i = 0; i < LebarKulkas; i++)
    {
        if (i < 9)
        {
            printf("%d  | ", i + 1);
        }
        else
        {
            printf("%d | ", i + 1);
        }

        for (j = 0; j < PanjangKulkas; j++)
        {
            if (isiKulkas(k, i, j) == Nil)
            {
                printf("0  ");
            }
            else
            {
                printf("%d  ", isiKulkas(k, i, j) + 1);
            }
        }
        printf("|\n");
    }
    printf("    -");
    for (i = 1; i <= PanjangKulkas; i++)
    {
        printf("---", i);
    }
    printf("\n");
}

void cetakListMakananKulkas(Kulkas k)
{
    printf("Keterangan :\n");
    if (!isEmptyLDinMakanan(makananKulkas(k)))
    {
        for (int i = 0; i < panjangLDinMakanan(makananKulkas(k)); i++)
        {
            printf("%d. Nama makanan: ", i + 1);
            cetakTeks(namaMakanan(elmtLDM(makananKulkas(k), i)), 'b');
            printf("\n");
            printf("   ID makanan: ");
            cetakTeks(idUnik(elmtLDM(makananKulkas(k), i)), 'c');
            printf("\n\n");
        }
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

    // kalau gamuat diliat dari ukurannya aja
    if ((panjang > PanjangKulkas || lebar > LebarKulkas) && (lebar > PanjangKulkas || panjang > LebarKulkas))
    {
        printf("Maaf, makanan terlalu besar untuk kulkas.\n");
    }

    // kalau luasnya masih bisa
    else if (luas < sisaKapasitas(*k))
    {
        inputTrue = true;
        while (inputTrue)
        {
            printf("Masukkan lokasi kiri atas kulkas yang diinginkan\n");
            printf("(input [0,0] untuk membatalkan proses)\n");
            printf("X : ");
            scanf("%d", &pilihanX);
            printf("Y : ");
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
            printf("aman\n");
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
            cetakTeks(namaMakanan(*makanan));
            printf("berhasil dikeluarkan.\n");
            cetakKulkas(*k);
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
            printf("Pilih nomor makanan yang ingin diubah posisinya:\n");
            printf("(0 untuk membatalkan)\n");
            printf(":: ");
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
            copyIsiKulkas(isiBaru, (*k).isi);

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
            cetakIsiKulkas(*k);

            inputTrue = true;
            while (inputTrue)
            {
                printf("Masukkan lokasi kiri atas kulkas yang diinginkan\n");
                printf("(input [0,0] untuk membatalkan proses)\n");
                printf("X : ");
                scanf("%d", &pilihanX);
                printf("Y : ");
                scanf("%d", &pilihanY);
                printf("\n");

                pilihanX--;
                pilihanY--;

                if (pilihanX == Nil && pilihanY == Nil)
                {
                    inputTrue = false;
                    printf("Perubahan dibatalkan.\n");
                    copyIsiKulkas((*k).isi, isiBaru);
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
                        isiHorizontal(k, pilihanIsiKulkas, pilihanX, pilihanY, panjang, lebar);
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
            copyIsiKulkas((*k).isi, isiBaru);
        }
    }
    else
    {
        printf("Maaf, Kulkas kosong.\n");
    }
    printf("Makanan ");
    // cetakTeks(namaMakanan(*makanan), 'b');
    printf("berhasil dikeluarkan.\n");
    cetakKulkas(*k);
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
        printf("Makanan tidak muat di lokasi tersebut.\n");
    }
    else if ((*horizontal) && (*vertikal) && (panjang != lebar))
    {
        printf("Pilih opsi posisi makanan:\n");
        printf("(1) Horizontal\n");
        printf("(2) Vertikal\n");
        int opsi = 0;
        while (opsi != 1 && opsi != 2)
        {
            printf("Pilihan: ");
            scanf("%d", &opsi);
            if (opsi != 1 && opsi != 2)
            {
                printf("Masukan salah! Silahkan ulangi.\n");
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

void copyIsiKulkas(IsiKulkas baru, IsiKulkas lama)
{
    int panjangKulkas = PanjangKulkas;
    int lebarKulkas = LebarKulkas;
    int i, j;
    for (i = 0; i < lebarKulkas; i++)
    {
        for (j = 0; j < panjangKulkas; j++)
        {
            aksesIsiKulkas(baru, i, j) = aksesIsiKulkas(lama, i, j);
        }
    }
}