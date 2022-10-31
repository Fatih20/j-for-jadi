#include "commands.h"
#include <stdio.h>
#include "../Input/input.h"

void olahMakanan(Teks command, FoodQueue *inventory, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState)
{
    for (int i = 0; i < ListNodeNEff(*daftarResep); i++)
    {
        if (teksSama(AksiTree(ListNodeELMT(*daftarResep, i)), command))
        {
            if (EQ(lokasiAL(AksiLokasiTree(ListNodeELMT(*daftarResep, i))), posisiState(*currState)))
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
    }
}

void buyFood(FoodQueue *DQ, LStatMakanan lMakanan, State *currState, AksiLokasi telepon)
{
    if (!IsAdjacent(lokasiAL(telepon), posisiState(*currState)))
    {
        printf("\nBNMO tidak berada pada area telepon!\n");
        return;
    }

    printf("==================================================\n");
    printf("                       \n");
    printf("BUY");
    printf("                       \n");
    printf("==================================================\n");
    printf("List Bahan Makanan:\n");
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
void undo(State *currState, Stack *stackUndo, Stack *stackRedo)
{
    // KAMUS LOKAL
    // ALGORITMA
}

void redo(State *currState, Stack *stackUndo, Stack *stackRedo)
{
    // KAMUS LOKAL
    // ALGORITMA
}