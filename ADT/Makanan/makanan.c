#include "makanan.h"
#include <string.h>
#include <stdio.h>
#include "../boolean.h"

void buatMakanan(Makanan *makanan, char *namaMakanan, int waktuBasi, int waktuSampai, int idBaru)
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
    idDari(*makanan) = idBaru;
}

void cetakMakanan(Makanan makanan)
{
    printf("Nama makanan : ");
    for (int i = 0; i < strlen(namaMakanan(makanan)); i++)
    {
        printf("%c", namaMakanan(makanan)[i]);
    }
    printf("\n");
    printf("Makanan memiliki ID : %d\n", idDari(makanan));
    printf("Basi dalam : %d menit\n", basiDalam(makanan));
    printf("Sampai dalam : %d menit\n", sampaiDalam(makanan));
}

boolean namaMakananSama(Makanan m1, Makanan m2)
{
    boolean samaSekarang = strlen(namaMakanan(m1)) == strlen(namaMakanan(m2));
    int stringLength = strlen(namaMakanan(m1));
    int i = 0;
    while (samaSekarang && i < stringLength)
    {
        samaSekarang = namaMakanan(m1)[i] == namaMakanan(m2)[i];
        if (samaSekarang)
        {
            i++;
        }
    }

    return samaSekarang;
};

boolean tipeMakananSama(Makanan m1, Makanan m2)
{
    return idDari(m1) % 1000 == idDari(m2) % 1000;
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
