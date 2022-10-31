#include "commands.h"
#include <stdio.h>
#include "../Input/input.h"
#include <stdlib.h>

void olahMakanan(Teks command, FoodQueue *inventory, FoodQueue *delivery, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState)
{
    for (int i = 0; i < ListNodeNEff(*daftarResep); i++)
    {
        if (teksSama(AksiTree(ListNodeELMT(*daftarResep, i)), command))
        {
            if (IsAdjacent(lokasiAL(AksiLokasiTree(ListNodeELMT(*daftarResep, i))), posisiState(*currState)))
            {
                break;
            }
            else
            {
                printf("Pindah ke ");
                TulisPOINT(lokasiAL(AksiLokasiTree(ListNodeELMT(*daftarResep, i))));
                printf(" untuk melakukan aksi ");
                cetakTeks(command);
                printf("\n");
                return;
            }
        }
    }
    ListNode daftarMakananTemp;
    createListNode(&daftarMakananTemp, 0);
    printf("==================================================\n");
    printf("                       ");
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
            cetakTeks(NamaMakananTree(ListNodeELMT(*daftarResep, i)));
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
        printf("Pilih makanan yang akan dibuat(%d - %d): ", 1, ListNodeNEff(daftarMakananTemp));
        scanf("%d", &choice);
    }
    boolean success = true;
    boolean isFirst = true;
    Tree foodChoice = ListNodeELMT(daftarMakananTemp, choice - 1);
    cnt = 1;
    for (int i = 0; i < ListNodeNEff(Children(foodChoice)); i++)
    {
        if (!isMakananInList(&content(*inventory), NamaMakananTree(Child(foodChoice, i))))
        {
            if (isFirst)
            {
                printf("Gagal membuat ");
                cetakTeks(NamaMakananTree(foodChoice));
                printf(" karena kamu tidak memiliki bahan berikut: \n");
                isFirst = false;
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
        waktuState(*currState) = jumlahWaktu(waktuState(*currState), durasi(AksiLokasiTree(foodChoice)));
        majukanWFQ(delivery, inventory, durasi(AksiLokasiTree(foodChoice)));
        enqueueInventory(inventory, MakananTree(foodChoice));
        inventoryState(*currState) = *inventory;
    }
    free(daftarMakananTemp.child);
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

void buyFood(FoodQueue *DQ, LStatMakanan lMakanan, State *currState, AksiLokasi telepon)
{
    if (!IsAdjacent(lokasiAL(telepon), posisiState(*currState)))
    {
        printf("\nBNMO tidak berada pada area telepon!\n");
        printf("Pindah ke ");
        TulisPOINT(lokasiAL(telepon));
        printf(" untuk melakukan aksi BUY");
        return;
    }

    printf("==================================================\n");
    printf("                        BUY                       \n");
    printf("==================================================\n");
    printf("List Bahan Makanan yang bisa Dibeli:\n");
    printf("Nama Makanan - Waktu pengiriman\n");
    int lastIdx = lastIdxLStatMakanan(lMakanan);
    int nBuyable = 0;
    Teks buyT;
    buatTeks("Buy", &buyT);

    LDinMakanan mBuyableList;
    buatLDinMakanan(&mBuyableList, 20);
    for (int i = 0; i <= lastIdx; i++)
    {
        Teks teksAksiM = aksi(aksiLokasi(elmtLSM(lMakanan, i)));
        // cetakMakanan(elmtLSM(lMakanan, i));
        if (teksSama(buyT, teksAksiM))
        {
            Makanan mBuyable = elmtLSM(lMakanan, i);
            printf("%d.", nBuyable + 1);
            cetakTeks(namaMakanan(mBuyable));
            printf(" ( ");
            tulisWaktu(sampaiDalam(mBuyable));
            printf(")\n");
            insertLastLDinMakanan(&mBuyableList, mBuyable);
            nBuyable++;
        }
    }
    printf("\n");
    printf("Kirim 0 untuk exit.\n");
    printf("\n");

    // scanf("%d", &choice);

    int choice = askForNumber(0, nBuyable, "Enter command : ");

    if (choice == 0)
    {
        return;
    }
    choice--;

    if (choice >= nBuyable)
    {
        printf("Pilihannya cuma sampai %d!", nBuyable);
        return;
    }

    Makanan boughtFood = elmtLDM(mBuyableList, choice);
    printf("Berhasil memesan ");
    cetakTeks(namaMakanan(boughtFood));
    printf(". ");
    cetakTeks(namaMakanan(boughtFood));
    printf(" akan diantar dalam ");
    tulisWaktu(sampaiDalam(boughtFood));
    printf("\n");
    enqueueDelivery(DQ, boughtFood);
};
