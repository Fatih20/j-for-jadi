#include "commands.h"
#include <stdio.h>

void olahMakanan(Teks command, FoodQueue *inventory, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState)
{
    for (int i = 0; i < panjangLStatMakanan(*daftarMakanan); i++)
    {
        if (teksSama(aksi(aksiLokasi(elmtLSM(*daftarMakanan, i))), command))
        {
            if (EQ(lokasi(aksiLokasi(elmtLSM(*daftarMakanan, i))), posisiState(*currState)))
            {
                break;
            }
            else
            {
                printf("Anda tidak berada pada lokasi ");
                cetakTeks(command);
                printf("\n");
                return;
            }
        }
    }
    Teks MIX, FRY, CHOP, BOIL;
    ListNode daftarMakananTemp;
    printf("==================================================\n");
    printf("                       \n");
    cetakTeks(command);
    printf("                       \n");
    printf("==================================================\n");
    buatTeks("MIX", &MIX);
    buatTeks("FRY", &FRY);
    buatTeks("CHOP", &CHOP);
    buatTeks("BOIL", &BOIL);
    printf("Daftar Makanan yang Bisa dibuat");
    printf(": \n");
    int j = 0;
    for (int i = 0; i < panjangListNode(*daftarResep); i++)
    {
        if (teksSama(command, AksiTree(ListNodeELMT(*daftarResep, i))))
        {
            ListNodeELMT(daftarMakananTemp, j) = ListNodeELMT(*daftarResep, i);
            printf("%d. ", j + 1);
            cetakTeks(namaMakanan(elmtLSM(*daftarMakanan, i)));
            printf("\n");
            j++;
        }
    }
    int choice;
    printf("Pilih makanan yang akan dibuat: ");
    scanf("%d", &choice);
    while (choice <= 0 || choice > panjangListNode(daftarMakananTemp))
    {
        printf("Pilihan tidak dikenali!\n");
        printf("Pilih makanan yang akan dibuat: ");
        scanf("%d", &choice);
    }
}