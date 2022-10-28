#include <stdio.h>
#include "matriks.h"

int main()
{
    AksiLokasi MIX, BOIL, TELEPON, FRY, CHOP;
    Matriks Peta, CopyPeta;
    POINT lokasiSimulator, dest, mix;
    char namaFile[] = "peta.txt";
    readMatriks(&Peta, namaFile, &lokasiSimulator, &MIX, &BOIL, &CHOP, &FRY, &TELEPON);
    displayMatriks(Peta);
    printf("isMatriksIdxValid\n");
    printf("%d\n", isMatriksIdxValid(10, 10));
    printf("%d\n", isMatriksIdxValid(10, 1000));

    printf("IsIdxEff\n");
    printf("%d\n", isIdxEff(Peta, 0, 0));
    printf("%d\n", isIdxEff(Peta, 12, 11));

    CreatePoint(&mix, 2, 1);

    copyMatriks(Peta, &CopyPeta);
    displayMatriks(CopyPeta);

    CreatePoint(&dest, 0, 1);
    displayMatriks(Peta);
    printf("IsAdjacent: %d\n", IsAdjacent(lokasiSimulator, mix));
    printf("IsCollideDest: %d\n", isCollide(Peta, dest));
    moveSimulator(&Peta, &lokasiSimulator, dest);

    displayMatriks(Peta);
    CreatePoint(&dest, 1, 1);
    printf("IsAdjacent: %d\n", IsAdjacent(lokasiSimulator, mix));
    printf("IsCollideDest: %d\n", isCollide(Peta, dest));
    moveSimulator(&Peta, &lokasiSimulator, dest);

    displayMatriks(Peta);
    CreatePoint(&dest, 2, 1);
    printf("IsAdjacent: %d\n", IsAdjacent(lokasiSimulator, mix));
    printf("IsCollideDest: %d\n", isCollide(Peta, dest));

    printf("lokasi Simulator:");
    TulisPOINT(lokasiSimulator);
    printf("\n");

    displayAksiLokasi(MIX);
    printf("\n");
    displayAksiLokasi(BOIL);
    printf("\n");
    displayAksiLokasi(CHOP);
    printf("\n");
    displayAksiLokasi(FRY);
    printf("\n");
    displayAksiLokasi(TELEPON);
    printf("\n");

    return 0;
}