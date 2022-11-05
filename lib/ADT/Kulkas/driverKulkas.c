#include <stdio.h>
#include <stdlib.h>
#include "kulkas.h"

int main()
{
    Kulkas k;
    buatKulkas(&k);
    cetakKulkas(k);
    int input = 99;

    // DUMMY makanan
    Makanan buangan;
    Makanan takoyakiGuritaKepalaTiga;
    Waktu wB;
    Waktu wS;
    wB = buatWaktu(0, 0, 20, 0);
    wS = buatWaktu(0, 0, 20, 0);

    AksiLokasi aL;
    Teks namaM1, idTM1, idUM1, aLT1;
    int panjang = 4;
    int lebar = 6;
    buatTeks("Bruh", &aLT1);
    buatTeks("Takoyaki Gurita Kepala Tiga", &namaM1);
    buatTeks("095", &idTM1);
    buatTeks("100", &idUM1);
    buatAksiLokasi(&aL, aLT1, 2, 2, 0, 1, 5, 0);
    buatMakanan(&takoyakiGuritaKepalaTiga, namaM1, idTM1, idUM1, wB, wS, aL, panjang, lebar);

    while (input != 0)
    {
        printf("Opsi: ");
        scanf("%d", &input);
        if (input == 1)
        {
            tambahIsiKulkas(&k, takoyakiGuritaKepalaTiga);
        }
        else if (input == 2)
        {
            keluarkanIsiKulkas(&k, &buangan);
        }
        else if (input == 3)
        {
            ubahIsiKulkas(&k);
        }
        cetakKulkas(k);
    }
}

// gcc -o main lib\ADT\Kulkas\driverKulkas.c lib\ADT\Kulkas\kulkas.c lib\ADT\ListDinMakanan\ldinmakanan.c lib\ADT\Teks\teks.c lib\ADT\ListDinKar\ldinkar.c lib\ADT\Makanan\makanan.c lib\ADT\Waktu\waktu.c lib\ADT\AksiLokasi\aksiLokasi.c lib\ADT\Point\Point.c