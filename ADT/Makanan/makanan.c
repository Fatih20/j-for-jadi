#include "makanan.h"
#include <string.h>

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
    IDDari(*makanan) = idBaru;
}
