#include "commands.h"
#include <stdio.h>

void olahMakanan(Teks command, FoodQueue *inventory, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState)
{
    for (int i = 0; i < ListNodeNEff(*daftarResep); i++)
    {
        if (teksSama(AksiTree(ListNodeELMT(*daftarResep, i)), command))
        {
            if (EQ(lokasi(AksiLokasiTree(ListNodeELMT(*daftarResep, i))), posisiState(*currState)))
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
    ListNode daftarMakananTemp;
    printf("==================================================\n");
    printf("                       \n");
    cetakTeks(command);
    printf("                       \n");
    printf("==================================================\n");
    printf("Daftar Makanan yang Bisa dibuat");
    printf(": \n");
    int cnt = 1;
    for (int i = 0; i < ListNodeNEff(*daftarResep); i++)
    {
        if (teksSama(command, AksiTree(ListNodeELMT(*daftarResep, i))))
        {
            insertLastListNode(&daftarMakananTemp, ListNodeELMT(*daftarResep, i));
            printf("%d. ", cnt);
            cetakTeks(namaMakanan(elmtLSM(*daftarMakanan, i)));
            printf("\n");
            cnt++;
        }
    }
    int choice;
    printf("Pilih makanan yang akan dibuat(%d - %d): ", 1, ListNodeNEff(daftarMakananTemp));
    scanf("%d", &choice);
    while (choice <= 0 || choice > ListNodeNEff(daftarMakananTemp))
    {
        printf("Pilihan tidak dikenali!\n");
        printf("Pilih makanan yang akan dibuat: ");
        scanf("%d", &choice);
    }
    boolean success = true;
    boolean isFirst = true;
    Tree foodChoice = ListNodeELMT(daftarMakananTemp, choice - 1);
    cnt = 1;
    for (int i = 0; i < ListNodeNEff(Children(foodChoice)); i++)
    {
        if (!isMakananInList(content(*inventory), NamaMakananTree(Child(foodChoice, i))))
        {
            if (isFirst)
            {
                printf("Gagal membuat ");
                cetakTeks(NamaMakananTree(foodChoice));
                printf("karena kamu tidak memiliki bahan berikut: \n");
            }
            printf("%d. ", cnt);
            cetakTeks(NamaMakananTree(Child(foodChoice, i)));
            printf("\n");
            success = false;
            cnt++;
        }
    }
    if (success)
    {
        cetakTeks(NamaMakananTree(foodChoice));
        printf(" berhasil dibuat dan sudah masuk ke inventory!");
        /* TO DO --> 
        1. buat generate IDUnik (ini juga dipakai di BUY)
        2. enqueue makanan ke inventory
        3. ubah currState (waktunya)
        */
    }
}

void displayCookbook(ListNode *daftarResep)
{
    printf("==================================================\n");
    printf("                      COOKBOOK                    \n");
    printf("==================================================\n");
    displayListNode(*daftarResep);
    int makanan;
    printf("Pilih resep yang ingin dilihat (%d - %d): ", 1, ListNodeNEff(*daftarResep));
    scanf("%d", &makanan);
    while (makanan < 1 || makanan > ListNodeNEff(*daftarResep))
    {
        printf("Pilihan tidak dikenali!\n");
        printf("Pilih resep yang ingin dilihat (%d - %d): ", 1, ListNodeNEff(*daftarResep));
        scanf("%d", &makanan);
    }
    printf("==================================================\n");
    printf("               Resep ");
    cetakTeks(NamaMakananTree(ListNodeELMT(*daftarResep, makanan - 1)));
    printf("               \n");
    printf("==================================================\n");
    displayTree(ListNodeELMT(*daftarResep, makanan - 1));
}

void displayCatalog(LStatMakanan *daftarMakanan)
{
    
    printf("==================================================\n");
    printf("                    DAFTAR MAKANAN                \n");
    printf("==================================================\n");
    printf("Nama Makanan - Waktu Kadaluarsa - Aksi yang Diperlukan - Lama Pengiriman\n");
    printLStatMakanan(*daftarMakanan);
}