#include "commands.h"
#include <stdio.h>
#include "../Input/input.h"
#include <stdlib.h>

void olahMakanan(Teks command, FoodQueue *inventory, FoodQueue *delivery, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState, boolean *isChangeState)
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
    boolean isChoiceValid;
    do
    {
        isChoiceValid = true;
        printf("Pilih makanan yang akan dibuat(%d - %d): ", 1, ListNodeNEff(daftarMakananTemp));
        startMBInput();
        if (panjangLDinTeks(currentRowI) != 1)
        {
            isChoiceValid = false;
        }
        else
        {
            if (!isTeksInt(elmtLDT(currentRowI, 0)))
            {
                isChoiceValid = false;
            }
            else
            {
                choice = teksToInt(elmtLDT(currentRowI, 0));
                if (choice <= 0 || choice > ListNodeNEff(daftarMakananTemp))
                {
                    isChoiceValid = false;
                }
            }
        }
        if (!isChoiceValid)
        {
            printf("Pilihan tidak dikenali!\n");
        }
    } while (!isChoiceValid);
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
        *isChangeState = true;
    }
    else
    {
        *isChangeState = false;
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

void buyFood(FoodQueue *DQ, LStatMakanan lMakanan, State *currState, AksiLokasi telepon, boolean *isChangeState)
{
    if (!IsAdjacent(lokasiAL(telepon), posisiState(*currState)))
    {
        printf("\nBNMO tidak berada pada area telepon!\n");
        printf("Pindah ke ");
        TulisPOINT(lokasiAL(telepon));
        printf(" untuk melakukan aksi BUY");
        *isChangeState = false;
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
    Waktu time;
    time = buatWaktu(0, 0, 1, 0);
    majukanWaktuState(currState, time);
    *isChangeState = true;
};
void undo(State *currState, Stack *stackUndo, Stack *stackRedo, State salinanState)
{
    // KAMUS LOKAL
    // ALGORITMA

    if (!IsEmptyStack(*stackUndo)) // Jika stack redo tak kosong
    {
        if (IsFullStack(*stackRedo))
        {
            expandStack(stackRedo, 10);
        }
        Pop(stackUndo, currState);     // Ubah currState menjadi state satu aksi sebelumnya
        Push(stackRedo, salinanState); // Push salinanState ke dalam stackRedo

        if ((Top(*stackUndo) + 1) < (Capacity(*stackUndo) / 2)) // Shrink stackUndo jika hanya terisi < 50%
        {
            shrinkStack(stackUndo, ((Capacity(*stackUndo) / 2) - 5));
        }
    }
}

void redo(State *currState, Stack *stackUndo, Stack *stackRedo, State salinanState)
{
    // KAMUS LOKAL
    // ALGORITMA
    if (!IsEmptyStack(*stackRedo)) // Jika stack redo tak kosong
    {
        if (IsFullStack(*stackUndo))
        {
            expandStack(stackUndo, 10);
        }
        Pop(stackRedo, currState);                              // Ubah currState menjadi state satu aksi setelahnya
        Push(stackUndo, salinanState);                          // Push salinanState ke dalam stackUndo
        if ((Top(*stackRedo) + 1) < (Capacity(*stackRedo) / 2)) // Shrink stackRedo jika hanya terisi < 50%
        {
            shrinkStack(stackRedo, ((Capacity(*stackRedo) / 2) - 5));
        }
    }
}
void moveS(State *currState, Matriks *peta, Simulator *S, boolean *isChangeState, Teks direction, int displacement, AksiLokasi MIX, AksiLokasi BOIL, AksiLokasi CHOP, AksiLokasi FRY, AksiLokasi TELEPON)
{
    // KAMUS LOKAL
    Teks north, east, south, west;
    int arah; // 1: utara, 2: timur, 3: selatan, 4: barat
    POINT dest;
    Waktu waktu;
    // ALGORITMA

    // Inisialisasi teks
    buatTeks("NORTH", &north);
    buatTeks("EAST", &east);
    buatTeks("SOUTH", &south);
    buatTeks("WEST", &west);

    // Menentukan dest
    if (teksSama(north, direction))
    {
        dest = PlusDelta(lokasiS(*S), (-1) * displacement, 0); // Dest Bergeser ke utara
        arah = 1;
    }
    else if (teksSama(east, direction))
    {
        dest = PlusDelta(lokasiS(*S), 0, displacement); // Dest Bergeser ke timur
        arah = 2;
    }
    else if (teksSama(south, direction))
    {
        dest = PlusDelta(lokasiS(*S), displacement, 0); // Dest Bergeser ke selatan
        arah = 3;
    }
    else if (teksSama(west, direction))
    {
        dest = PlusDelta(lokasiS(*S), 0, (-1) * displacement); // Dest Bergeser ke barat
        arah = 4;
    }
    TulisPOINT(lokasiS(*S));
    TulisPOINT(dest);
    // Pemindahan Simulator
    if (!isCollide(*peta, dest)) // Jika bisa berpindah
    {
        *isChangeState = true;
        moveSimulator(peta, &lokasiS(*S), dest);
        printf("Simulator berhasil berpindah ke ");
        if (arah == 1)
        {
            printf("Utara!\n");
        }
        else if (arah == 2)
        {
            printf("Timur!\n");
        }
        if (arah == 3)
        {
            printf("Selatan!\n");
        }
        if (arah == 4)
        {
            printf("Barat!\n");
        }
        waktu = buatWaktu(0, 0, 1, 0);
        posisiState(*currState) = dest;
        majukanWaktuState(currState, waktu);
        TulisPOINT(lokasiS(*S));
    }
    else // Jika tak bisa berpindah
    {
        *isChangeState = false;
        if (EQ(dest, lokasiAL(MIX)))
        {
            printf("Tidak bisa berpindah karena merupakan lokasi mixing!\n");
        }
        else if (EQ(dest, lokasiAL(BOIL)))
        {
            printf("Tidak bisa berpindah karena merupakan lokasi boiling!\n");
        }
        else if (EQ(dest, lokasiAL(CHOP)))
        {
            printf("Tidak bisa berpindah karena merupakan lokasi chopping!\n");
        }
        else if (EQ(dest, lokasiAL(TELEPON)))
        {
            printf("Tidak bisa berpindah karena merupakan lokasi telepon!\n");
        }
        else if (EQ(dest, lokasiAL(FRY)))
        {
            printf("Tidak bisa berpindah karena merupakan lokasi frying!\n");
        }
        else
        {
            if (isBorder(*peta, dest))
            {
                printf("Tidak bisa berpindah karena merupakan batas peta!\n");
            }
            else
            {
                printf("Tidak bisa berpindah karena merupakan tembok!\n");
            }
        }
    }
}
