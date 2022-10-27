#include "makanan.h"
#include "../Teks/teks.h"

#include <stdio.h>
#include "../boolean.h"

void buatMakanan(Makanan *makanan, Teks namaMakanan, Teks idTipe, Teks idUnik, Waktu waktuBasi, Waktu waktuSampai, AksiLokasi aksiLokasi)
{
    namaMakanan(*makanan) = namaMakanan;
    idTipe(*makanan) = idTipe;
    idUnik(*makanan) = idUnik;
    basiDalam(*makanan) = waktuBasi;
    sampaiDalam(*makanan) = waktuSampai;
    aksiLokasi(*makanan) = aksiLokasi;
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

void majukanWBasiM(Makanan *m, Waktu w)
{
    Waktu currentWB = basiDalam(*m);
    basiDalam(*m) = WLT(w, currentWB) ? detikToWaktu(durasiW(currentWB, w)) : buatWaktu(0, 0, 0, 0);
}

Waktu majukanWSampaiM(Makanan *m, Waktu w)
{
    Waktu currentWS = sampaiDalam(*m);
    boolean overflow = WLT(currentWS, w);
    sampaiDalam(*m) = overflow ? buatWaktu(0, 0, 0, 0) : detikToWaktu(durasiW(currentWS, w));
    return !overflow ? buatWaktu(0, 0, 0, 0) : detikToWaktu(durasiW(currentWS, w));
}