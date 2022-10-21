#include "makanan.h"
#include <string.h>
// #include <strings.h>
#include <stdio.h>
#include "../boolean.h"

void buatMakanan(Makanan *makanan, char *namaMakanan, int waktuBasi, int waktuSampai, char *idUnik, char *idTipe)
{
    int i = 0;
    int stringLength = strlen(namaMakanan);
    for (i = 0; i < stringLength; i++)
    {
        namaMakanan(*makanan)[i] = namaMakanan[i];
    }
    namaMakanan(*makanan)[i] = '\0';

    basiDalam(*makanan) = waktuBasi;
    sampaiDalam(*makanan) = waktuSampai;
    idUnik(*makanan) = idUnik;
    idTipe(*makanan) = idTipe;
}

void cetakMakanan(Makanan makanan)
{
    printf("Nama makanan : ");
    for (int i = 0; i < strlen(namaMakanan(makanan)); i++)
    {
        printf("%c", namaMakanan(makanan)[i]);
    }
    printf("\n");
    printf("Makanan memiliki ID Tipe : %s\n", idTipe(makanan));
    printf("Makanan memiliki ID Unik : %s\n", idUnik(makanan));

    // printf("%s", id);
    // printf("\n");
    printf("Basi dalam : %d menit\n", basiDalam(makanan));
    printf("Sampai dalam : %d menit\n", sampaiDalam(makanan));
}

boolean namaMakananSama(Makanan m1, Makanan m2)
{
    return strcmp(namaMakanan(m1), namaMakanan(m2)) == 0;
};

boolean tipeMakananSama(Makanan m1, Makanan m2)
{
    return strcmp(idUnik(m1), idUnik(m2)) == 0;
};

boolean basiBersamaan(Makanan m1, Makanan m2)
{
    return basiDalam(m1) == basiDalam(m2);
};

boolean basiDuluan(Makanan m1, Makanan m2)
{
    return basiDalam(m1) < basiDalam(m2);
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
    return sampaiDalam(m1) == sampaiDalam(m2);
};

boolean sampaiDuluan(Makanan m1, Makanan m2)
{
    return sampaiDalam(m1) < sampaiDalam(m2);
};

boolean sampaiDuluanAtauSama(Makanan m1, Makanan m2)
{
    return sampaiDuluan(m1, m2) || sampaiBersamaan(m1, m2);
};

boolean sampaiSetelahAtauSama(Makanan m1, Makanan m2)
{
    return !sampaiDuluan(m1, m2) || sampaiBersamaan(m1, m2);
};
