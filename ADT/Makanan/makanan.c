#include "makanan.h"
#include "../Teks/teks.h"

#include <stdio.h>
#include "../boolean.h"

void buatMakanan(Makanan *makanan, char namaMakanan[], char idTipe[], char idUnik[], Waktu waktuBasi, Waktu waktuSampai)
{
    int i = 0;

    buatTeks(namaMakanan, &namaMakanan(*makanan));
    basiDalam(*makanan) = waktuBasi;
    sampaiDalam(*makanan) = waktuSampai;
    buatTeks(idUnik, &idUnik(*makanan));
    buatTeks(idTipe, &idTipe(*makanan));
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