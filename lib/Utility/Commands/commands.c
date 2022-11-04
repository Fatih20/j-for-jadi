#include "commands.h"
#include <stdio.h>
#include "../Input/input.h"
#include <stdlib.h>

void olahMakanan(Teks command, ListNode *daftarResep, Simulator *currSimulator, boolean *isChangeSimulator, NotifState *notifS)
{
    for (int i = 0; i < ListNodeNEff(*daftarResep); i++)
    {
        if (teksSamaCI(AksiTree(ListNodeELMT(*daftarResep, i)), command))
        {
            if (IsAdjacent(lokasiAL(AksiLokasiTree(ListNodeELMT(*daftarResep, i))), posisiSimulator(*currSimulator)))
            {
                break;
            }
            else
            {
                printf("Pindah ke ");
                TulisPOINT(lokasiAL(AksiLokasiTree(ListNodeELMT(*daftarResep, i))));
                printf(" untuk melakukan aksi ");
                cetakTeks(toUpper(command));
                printf("\n");
                return;
            }
        }
    }
    ListNode daftarMakananTemp;
    createListNode(&daftarMakananTemp, 0);
    printf("==================================================\n");
    printf("                       ");
    cetakTeks(toUpper(command));
    printf("                       \n");
    printf("==================================================\n\n");
    printf("Ketik 0 untuk keluar.\n\n");
    printf("Daftar Makanan yang Bisa dibuat");
    printf(": \n");
    int cnt = 1;
    for (int i = 0; i < ListNodeNEff(*daftarResep); i++)
    {
        if (teksSamaCI(command, AksiTree(ListNodeELMT(*daftarResep, i))))
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
    boolean isExit = false;
    do
    {
        isChoiceValid = true;
        printf("\nPilih makanan yang akan dibuat(%d - %d): ", 1, ListNodeNEff(daftarMakananTemp));
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
                if (choice == 0)
                {
                    return;
                }
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
        else
        {
            boolean success = true;
            boolean isFirst = true;
            Tree foodChoice = ListNodeELMT(daftarMakananTemp, choice - 1);
            FoodQueue *inventory = &inventorySimulator(*currSimulator);
            FoodQueue *delivery = &deliverySimulator(*currSimulator);
            cnt = 1;
            for (int i = 0; i < ListNodeNEff(Children(foodChoice)); i++)
            {
                if (!isMakananInList(&content(*inventory), NamaMakananTree(Child(foodChoice, i))))
                {
                    if (isFirst)
                    {
                        printf("\nGagal membuat ");
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
                printf(" berhasil dibuat dan sudah masuk ke inventory!\n");
                for (int i = 0; i < ListNodeNEff(Children(foodChoice)); i++)
                {
                    Makanan temp;
                    deleteByIdTipe(inventory, IdTipeTree(Child(foodChoice, i)), &temp);
                    Notif notifTemp;
                    buatNotifCookUndo(toUpper(command), namaMakanan(temp), &notifTemp);
                    insertLastLDinNotif(&backNS(*notifS), notifTemp);
                }
                waktuSimulator(*currSimulator) = jumlahWaktu(waktuSimulator(*currSimulator), durasi(AksiLokasiTree(foodChoice)));
                majukanWFQ(delivery, inventory, durasi(AksiLokasiTree(foodChoice)), notifS);
                enqueueInventory(inventory, MakananTree(foodChoice));
                *isChangeSimulator = true;
            }
            else
            {
                *isChangeSimulator = false;
            }
            free(daftarMakananTemp.child);
        }
    } while (!isChoiceValid || !isExit);
}

void displayCookbook(ListNode *daftarResep)
{
    printf("==================================================\n");
    printf("                      COOKBOOK                    \n");
    printf("==================================================\n");
    displayListNode(*daftarResep);
    boolean isExit = false;
    do
    {
        int choice = askForNumber(0, ListNodeNEff(*daftarResep), "Pilih resep yang ingin dilihat: ");
        if (choice == 0)
        {
            isExit = true;
            return;
        }
        printf("==================================================\n");
        printf("               Resep ");
        cetakTeks(NamaMakananTree(ListNodeELMT(*daftarResep, choice - 1)));
        printf("               \n");
        printf("==================================================\n\n");
        displayTree(ListNodeELMT(*daftarResep, choice - 1));
    } while (!isExit);
}

void displayCatalog(LStatMakanan *daftarMakanan)
{

    printf("==================================================\n");
    printf("                    DAFTAR MAKANAN                \n");
    printf("==================================================\n");
    printf("Nama Makanan - Waktu Kadaluarsa - Aksi yang Diperlukan - Lama Pengiriman\n");
    printLStatMakanan(*daftarMakanan);
}

void displayDelivery(FoodQueue dQ)
{

    int panjangDQ = nElmt(dQ);
    if (panjangDQ == 0)
    {
        printf("Tidak ada makanan yang sedang dalam proses pengiriman! Pesan makanan yuk dengan pergi ke telepon dan menggunakan command BUY!");
    }
    else
    {
        printf("List Nama Makanan di Perjalanan\n");
        printf("(nama - waktu sisa delivery)\n");
        for (int i = 0; i < panjangDQ; i++)
        {
            printf("    %d. ", i + 1);
            Makanan mToShow = elmtFQ(dQ, i);
            cetakTeks(namaMakanan(mToShow));
            printf(" - ");
            tulisWaktu(sampaiDalam(mToShow));
            printf("\n");
        }
    }
    printf("\n");
}

void displayInventory(FoodQueue iQ)
{

    int panjangIQ = nElmt(iQ);
    if (panjangIQ == 0)
    {
        printf("Tidak ada makanan di dalam inventory kamu!");
    }
    else
    {
        printf("List Nama Makanan di Perjalanan\n");
        printf("(nama - waktu sisa kadaluarsa)\n");
        for (int i = 0; i < panjangIQ; i++)
        {
            printf("%d. ", i + 1);
            Makanan mToShow = elmtFQ(iQ, i);
            cetakTeks(namaMakanan(mToShow));
            printf(" - ");
            tulisWaktu(basiDalam(mToShow));
            printf("\n");
        }
    }
    printf("\n");
}

void buyFood(LStatMakanan lMakanan, Simulator *currSimulator, AksiLokasi telepon, boolean *isChangeSimulator, NotifState *notifS)
{
    if (!IsAdjacent(lokasiAL(telepon), posisiSimulator(*currSimulator)))
    {
        printf("\nBNMO tidak berada pada area telepon!\n");
        printf("Pindah ke ");
        TulisPOINT(lokasiAL(telepon));
        printf(" untuk melakukan aksi BUY");
        *isChangeSimulator = false;
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
    buatTeks("BUY", &buyT);

    LDinMakanan mBuyableList;
    buatLDinMakanan(&mBuyableList, 20);
    for (int i = 0; i <= lastIdx; i++)
    {
        Teks teksAksiM = aksi(aksiLokasi(elmtLSM(lMakanan, i)));
        // cetakMakanan(elmtLSM(lMakanan, i));
        if (teksSamaCI(buyT, teksAksiM))
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

    Makanan boughtFood = elmtLDM(mBuyableList, choice);
    printf("Berhasil memesan ");
    cetakTeks(namaMakanan(boughtFood));
    printf(". ");
    cetakTeks(namaMakanan(boughtFood));
    printf(" akan diantar dalam ");
    tulisWaktu(sampaiDalam(boughtFood));
    printf("\n");
    insertLastLDinNotifRaw(&backNS(*notifS), 'p', namaMakanan(boughtFood));
    Waktu time;
    time = buatWaktu(0, 0, 1, 0);
    majukanWaktuSimulator(currSimulator, time, notifS);
    *isChangeSimulator = true;
    enqueueDelivery(&deliverySimulator(*currSimulator), boughtFood);
};
void undo(Simulator *currSimulator, Stack *stackUndo, Stack *stackRedo, Simulator salinanSimulator, Matriks *peta)
{
    // KAMUS LOKAL
    POINT p;
    // ALGORITMA

    if (!IsEmptyStack(*stackUndo) && Absis(posisiSimulator(InfoTop(*stackUndo))) != -1) // Jika stack undo tak kosong dan elemen top-nya bukan initialState
    {
        if (IsFullStack(*stackRedo))
        {
            expandStack(stackRedo, 10);
        }

        Pop(stackUndo, currSimulator);     // Ubah currState menjadi state satu aksi sebelumnya
        Push(stackRedo, salinanSimulator); // Push salinanState ke dalam stackRedo

        if (!EQ(posisiSimulator(salinanSimulator), posisiSimulator(*currSimulator))) // Mengembalikan posisi simulator
        {
            CreatePoint(&p, Absis(posisiSimulator(salinanSimulator)), Ordinat(posisiSimulator(salinanSimulator))); // Salin posisi salinan agar salinan tak berubah
            moveSimulator(peta, &p, posisiSimulator(*currSimulator));
        }

        if ((Top(*stackUndo) + 1) < (Capacity(*stackUndo) / 2)) // Shrink stackUndo jika hanya terisi < 50%
        {
            shrinkStack(stackUndo, ((Capacity(*stackUndo) / 2) - 5));
        }
    }
    else if (!IsEmptyStack(*stackUndo) && Absis(posisiSimulator(InfoTop(*stackUndo))) == -1)
    {
        LDinNotif notifF;
        LDinNotif notifB;
        buatLDinNotif(&notifF, 5);
        buatLDinNotif(&notifB, 5);
        NotifState notifS;
        buatNotifState(&notifS, notifF, notifB);
        notifSimulator(InfoTop(*stackUndo)) = notifS;
    }
}

void redo(Simulator *currSimulator, Stack *stackUndo, Stack *stackRedo, Simulator salinanSimulator, Matriks *peta)
{
    // KAMUS LOKAL
    POINT p;
    // ALGORITMA
    if (!IsEmptyStack(*stackRedo)) // Jika stack redo tak kosong
    {
        if (IsFullStack(*stackUndo))
        {
            expandStack(stackUndo, 10);
        }
        Pop(stackRedo, currSimulator);                                               // Ubah currState menjadi state satu aksi setelahnya
        Push(stackUndo, salinanSimulator);                                           // Push salinanState ke dalam stackUndo
        if (!EQ(posisiSimulator(salinanSimulator), posisiSimulator(*currSimulator))) // Mengembalikan posisi simulator
        {
            CreatePoint(&p, Absis(posisiSimulator(salinanSimulator)), Ordinat(posisiSimulator(salinanSimulator))); // Salin posisi salinan agar salinan tak berubah
            moveSimulator(peta, &p, posisiSimulator(*currSimulator));
        }

        if ((Top(*stackRedo) + 1) < (Capacity(*stackRedo) / 2)) // Shrink stackRedo jika hanya terisi < 50%
        {
            shrinkStack(stackRedo, ((Capacity(*stackRedo) / 2) - 5));
        }
    }
}
void moveS(Simulator *currSimulator, Matriks *peta, boolean *isChangeSimulator, Teks direction, int displacement, AksiLokasi MIX, AksiLokasi BOIL, AksiLokasi CHOP, AksiLokasi FRY, AksiLokasi TELEPON, NotifState *notifS)
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
    if (teksSamaCI(north, direction))
    {
        dest = PlusDelta(posisiSimulator(*currSimulator), (-1) * displacement, 0); // Dest Bergeser ke utara
        arah = 1;
    }
    else if (teksSamaCI(east, direction))
    {
        dest = PlusDelta(posisiSimulator(*currSimulator), 0, displacement); // Dest Bergeser ke timur
        arah = 2;
    }
    else if (teksSamaCI(south, direction))
    {
        dest = PlusDelta(posisiSimulator(*currSimulator), displacement, 0); // Dest Bergeser ke selatan
        arah = 3;
    }
    else if (teksSamaCI(west, direction))
    {
        dest = PlusDelta(posisiSimulator(*currSimulator), 0, (-1) * displacement); // Dest Bergeser ke barat
        arah = 4;
    }
    // Pemindahan Simulator
    if (!isCollide(*peta, dest)) // Jika bisa berpindah
    {
        *isChangeSimulator = true;
        moveSimulator(peta, &posisiSimulator(*currSimulator), dest);
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
        majukanWaktuSimulator(currSimulator, waktu, notifS);
    }
    else // Jika tak bisa berpindah
    {
        *isChangeSimulator = false;
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
