#include "makanan.h"
#include "../Teks/teks.h"

#include <stdio.h>
#include "../boolean.h"

void buatMakanan(Makanan *makanan, Teks namaMakanan, Teks idTipe, Teks idUnik, Waktu waktuBasi, Waktu waktuSampai, AksiLokasi aksiLokasi, int panjang, int lebar)
{
    namaMakanan(*makanan) = namaMakanan;
    idTipe(*makanan) = idTipe;
    idUnik(*makanan) = idUnik;
    basiDalam(*makanan) = waktuBasi;
    sampaiDalam(*makanan) = waktuSampai;
    aksiLokasi(*makanan) = aksiLokasi;
    panjang(*makanan) = panjang;
    lebar(*makanan) = lebar;
}

void cetakMakanan(Makanan makanan)
{
    printf("Nama makanan : ");
    cetakTeks(namaMakanan(makanan));
    printf("\n");
    printf("Makanan memiliki ID  : ");
    cetakTeks(idMakanan(makanan));
    printf("\n");

    printf("Basi dalam : ");
    tulisWaktu(basiDalam(makanan));
    printf("\n");
    printf("Sampai dalam : ");
    tulisWaktu(sampaiDalam(makanan));
    printf("\n");
    displayAksiLokasi(aksiLokasi(makanan));
    printf("\n");
    printf("Ukuran makanan : [%dx%d]", panjang(makanan), lebar(makanan));
    printf("\n");
}

Teks idMakanan(Makanan makanan)
{
    Teks retTeks;
    gabungkanTeks(idTipe(makanan), idUnik(makanan), &retTeks);
    return retTeks;
};

boolean namaMakananSama(Makanan m1, Makanan m2)
{
    return teksSama(namaMakanan(m1), namaMakanan(m2));
};

boolean tipeMakananSama(Makanan m1, Makanan m2)
{
    return teksSama(idTipe(m1), idTipe(m2));
};

boolean basiBersamaan(Makanan m1, Makanan m2)
{
    return WEQ(basiDalam(m1), basiDalam(m2));
};

boolean basiDuluan(Makanan m1, Makanan m2)
{
    return WLT(basiDalam(m1), basiDalam(m2));
};

boolean basiDuluanAtauSama(Makanan m1, Makanan m2)
{
    return basiDuluan(m1, m2) || basiBersamaan(m1, m2);
};

boolean basiSetelahAtauSama(Makanan m1, Makanan m2)
{
    return !basiDuluan(m1, m2) || basiBersamaan(m1, m2);
};

boolean sampaiBersamaan(Makanan m1, Makanan m2)
{
    return WEQ(sampaiDalam(m1), sampaiDalam(m2));
};

boolean sampaiDuluan(Makanan m1, Makanan m2)
{
    return WLT(sampaiDalam(m1), sampaiDalam(m2));
};

boolean sampaiDuluanAtauSama(Makanan m1, Makanan m2)
{
    return sampaiDuluan(m1, m2) || sampaiBersamaan(m1, m2);
};

boolean sampaiSetelahAtauSama(Makanan m1, Makanan m2)
{
    return !sampaiDuluan(m1, m2) || sampaiBersamaan(m1, m2);
};

boolean isMakananEqual(Makanan m1, Makanan m2)
{
    return teksSama(namaMakanan(m1), namaMakanan(m2)) && teksSama(idTipe(m1), idTipe(m2)) && teksSama(idUnik(m1), idUnik(m2)) && WEQ(basiDalam(m1), basiDalam(m2)) && WEQ(sampaiDalam(m1), sampaiDalam(m2));
}

void majukanWMInventory(Makanan *m, Waktu w)
{
    Waktu currentWB = basiDalam(*m);
    basiDalam(*m) = WLT(w, currentWB) ? detikToWaktu(durasiW(currentWB, w)) : buatWaktu(0, 0, 0, 0);
}

void majukanWMDelivery(Makanan *m, Waktu w, char newPosisi)
{

    if (newPosisi == 'c')
    {
        newPosisi = newPosisiMDelivery(*m, w);
        printf("%c\n", newPosisi);
    }

    switch (newPosisi)
    {
    case 'd':
        sampaiDalam(*m) = kurangWaktu(sampaiDalam(*m), w);
        break;
    case 'i':
        basiDalam(*m) = kurangWaktu(jumlahWaktu(basiDalam(*m), sampaiDalam(*m)), w);
        sampaiDalam(*m) = buatWaktu(0, 0, 0, 0);
        break;
    case 'b':
        sampaiDalam(*m) = buatWaktu(0, 0, 0, 0);
        basiDalam(*m) = buatWaktu(0, 0, 0, 0);
        break;

    default:
        break;
    }
}

char newPosisiMDelivery(Makanan m, Waktu w)
{
    Waktu totalTime = jumlahWaktu(basiDalam(m), sampaiDalam(m));
    char result;
    if (WGT(sampaiDalam(m), w))
    {
        // Makanan masih ada di delivery queue
        result = 'd';
    }
    else if (WGT(totalTime, w))
    {
        // Makanan berpindah ke inventory queue
        result = 'i';
    }
    else
    {
        // Makanan berpindah ke inventory queue lalu basi
        result = 'b';
    }
    return result;
}

int luasMakanan(Makanan m)
{
    return panjang(m) * lebar(m);
}
