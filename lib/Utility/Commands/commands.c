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
                printf("Pindah ke posisi yang berhadapan dengan ");
                TulisPOINT(lokasiAL(AksiLokasiTree(ListNodeELMT(*daftarResep, i))));
                printf(" untuk melakukan aksi ");
                cetakTeks(toUpper(command), 'y');
                printf("\n");
                return;
            }
        }
    }
    ListNode daftarMakananTemp;
    createListNode(&daftarMakananTemp, 0);
    printSCyan("============================================================\n");
    printf("                               ");
    cetakTeks(toUpper(command), 'y');
    printf("                       \n");
    printSCyan("============================================================\n\n");
    printf("Ketik ");
    printRed('0');
    printf(" untuk keluar.\n\n");
    printSYellow("Daftar Makanan yang Bisa dibuat");
    printf(": \n");
    int cnt = 1;
    for (int i = 0; i < ListNodeNEff(*daftarResep); i++)
    {
        if (teksSamaCI(command, AksiTree(ListNodeELMT(*daftarResep, i))))
        {
            insertLastListNode(&daftarMakananTemp, ListNodeELMT(*daftarResep, i));
            printf("%d. ", cnt);
            cetakTeks(NamaMakananTree(ListNodeELMT(*daftarResep, i)), 'b');
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
            printSRed("Pilihan tidak dikenali!\n");
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
                        printSRed("\nGagal");
                        printf(" membuat ");
                        cetakTeks(NamaMakananTree(foodChoice), 'b');
                        printf(" karena kamu tidak memiliki bahan berikut: \n");
                        isFirst = false;
                    }
                    printf("%d. ", cnt);
                    cetakTeks(NamaMakananTree(Child(foodChoice, i)), 'b');
                    printf("\n");
                    success = false;
                    cnt++;
                }
            }
            if (success)
            {
                cetakTeks(NamaMakananTree(foodChoice), 'b');
                printSGreen(" berhasil");
                printf(" dibuat dan sudah masuk ke inventory!\n");
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
        }
    } while (!isChoiceValid || !isExit);
}

void displayCookbook(ListNode *daftarResep)
{
    printSCyan("============================================================\n");
    printSYellow("                          COOKBOOK                          \n");
    printSCyan("============================================================\n\n");
    displayListNode(*daftarResep);
    boolean isExit = false;
    printf("\nKetik ");
    printRed('0');
    printf(" untuk keluar.\n\n");
    do
    {
        printf("\n");
        int choice = askForNumber(0, ListNodeNEff(*daftarResep), "Pilih resep yang ingin dilihat: ");
        if (choice == 0)
        {
            isExit = true;
            return;
        }
        printSCyan("============================================================\n");
        printSBlue("                      Resep ");
        cetakTeks(NamaMakananTree(ListNodeELMT(*daftarResep, choice - 1)), 'b');
        printf("               \n");
        printSCyan("============================================================\n\n");
        displayTree(ListNodeELMT(*daftarResep, choice - 1));
    } while (!isExit);
}

void displayCatalog(LStatMakanan *daftarMakanan)
{

    printSCyan("============================================================\n");
    printSYellow("                        DAFTAR MAKANAN                      \n");
    printSCyan("============================================================\n\n");
    printf("Nama Makanan - Waktu Kadaluarsa - Aksi yang Diperlukan - Lama Pengiriman\n");
    printLStatMakanan(*daftarMakanan);
}

void displayDelivery(FoodQueue dQ)
{

    int panjangDQ = nElmt(dQ);
    if (panjangDQ == 0)
    {
        printSRed("Tidak ada makanan yang sedang dalam proses pengiriman!\n");
        printf("Pesan makanan yuk dengan pergi ke telepon dan menggunakan command ");
        printSBlue("BUY\n");
    }
    else
    {
        printSYellow("List Makanan di dalam Perjalanan\n\n");
        printf("Nama Makanan - Waktu Sisa Delivery\n");
        for (int i = 0; i < panjangDQ; i++)
        {
            printf("    %d. ", i + 1);
            Makanan mToShow = elmtFQ(dQ, i);
            cetakTeks(namaMakanan(mToShow), 'b');
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
        printSRed("Tidak ada makanan di dalam inventory kamu!\n");
    }
    else
    {
        printSYellow("List Makanan di Dalam Inventory\n\n");
        printf("Nama Makanan - Waktu Sisa Kadaluarsa)\n");
        for (int i = 0; i < panjangIQ; i++)
        {
            printf("    %d. ", i + 1);
            Makanan mToShow = elmtFQ(iQ, i);
            cetakTeks(namaMakanan(mToShow), 'b');
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
        printf("\nSimulator tidak berada pada area telepon!\n");
        printf("Pindah ke lokasi yang berhadapan dengan ");
        TulisPOINT(lokasiAL(telepon));
        printf(" untuk melakukan aksi BUY");
        *isChangeSimulator = false;
        return;
    }

    printSCyan("============================================================\n");
    printSYellow("                             BUY                            \n");
    printSCyan("============================================================\n\n");
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
            insertLastLDinMakanan(&mBuyableList, mBuyable);
            nBuyable++;
        }
    }

    printf("\nKetik ");
    printRed('0');
    printf(" untuk keluar.\n\n");

    // scanf("%d", &choice);

    int choice;
    do
    {
        printSYellow("List Bahan Makanan yang Bisa Dibeli:\n\n");
        printf("Nama Makanan - Waktu pengiriman\n");
        for (int i = 0; i <= lastIdxLDinMakanan(mBuyableList); i++)
        {
            Makanan mBuyable = elmtLSM(mBuyableList, i);
            printf("    %d. ", i + 1);
            cetakTeks(namaMakanan(mBuyable), 'b');
            printf(" - ");
            tulisWaktu(sampaiDalam(mBuyable));
            printf("\n");
        }

        printf("\n");

        choice = askForNumber(0, nBuyable, "Enter food to buy : ");

        if (choice != 0)
        {

            Makanan boughtFood = elmtLDM(mBuyableList, choice - 1);
            printSGreen("\nBerhasil ");
            printf("memesan ");
            cetakTeks(namaMakanan(boughtFood), 'b');
            printf(". ");
            cetakTeks(namaMakanan(boughtFood), 'b');
            printf(" akan sampai dalam ");
            tulisWaktu(sampaiDalam(boughtFood));
            printf("\n\n");
            insertLastLDinNotifRaw(&backNS(*notifS), 'p', namaMakanan(boughtFood));
            Waktu time;
            time = buatWaktu(0, 0, 1, 0);
            majukanWaktuSimulator(currSimulator, time, notifS);
            *isChangeSimulator = true;
            enqueueDelivery(&deliverySimulator(*currSimulator), boughtFood);
        }

    } while (choice != 0);
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
void moveS(Simulator *currSimulator, Matriks *peta, boolean *isChangeSimulator, Teks direction, int displacement, AksiLokasi MIX, AksiLokasi BOIL, AksiLokasi CHOP, AksiLokasi FRY, AksiLokasi TELEPON, AksiLokasi KULKAS, NotifState *notifS)
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
        printf("Simulator ");
        printSGreen("berhasil");
        printf(" berpindah ke ");
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
            printSRed("Tidak bisa berpindah karena merupakan lokasi mixing!\n");
        }
        else if (EQ(dest, lokasiAL(BOIL)))
        {
            printSRed("Tidak bisa berpindah karena merupakan lokasi boiling!\n");
        }
        else if (EQ(dest, lokasiAL(CHOP)))
        {
            printSRed("Tidak bisa berpindah karena merupakan lokasi chopping!\n");
        }
        else if (EQ(dest, lokasiAL(TELEPON)))
        {
            printSRed("Tidak bisa berpindah karena merupakan lokasi telepon!\n");
        }
        else if (EQ(dest, lokasiAL(FRY)))
        {
            printSRed("Tidak bisa berpindah karena merupakan lokasi frying!\n");
        }
        else if (EQ(dest, lokasiAL(KULKAS)))
        {
            printSRed("Tidak bisa berpindah karena merupakan lokasi kulkas!\n");
        }
        else
        {
            if (isBorder(*peta, dest))
            {
                printSRed("Tidak bisa berpindah karena merupakan batas peta!\n");
            }
            else
            {
                printSRed("Tidak bisa berpindah karena merupakan tembok!\n");
            }
        }
    }
}

void openKulkas(Simulator *currSimulator, boolean *isChangeSimulator, NotifState *notifS)
{
    if (!IsAdjacent(lokasiAL(aksiLokasiKulkas(kulkasSimulator(*currSimulator))), posisiSimulator(*currSimulator)))
    {
        printf("\nBNMO tidak berada pada area kulkas!\n");
        printf("Pindah ke ");
        TulisPOINT(lokasiAL(aksiLokasiKulkas(kulkasSimulator(*currSimulator))));
        printf(" untuk melakukan aksi KULKAS");
        *isChangeSimulator = false;
        return;
    }
    boolean isKulkasBerubah;

    printSCyan("============================================================\n");
    printSYellow("                           KULKAS                           \n");
    printSCyan("============================================================\n\n");
    cetakKulkas(kulkasSimulator(*currSimulator));
    int pilihanOpsiKulkas = Nil;
    while (pilihanOpsiKulkas != 0)
    {
        printSYellow("Pilih tindakan yang ingin dilakukan\n");
        printSYellow("(1)");
        printSCyan(" Masukkan makanan\n");
        printSYellow("(2)");
        printSCyan(" Keluarkan makanan\n");
        printSYellow("(3)");
        printSCyan(" Ubah susunan kulkas\n");
        pilihanOpsiKulkas = askForNumber(0, 3, "Pilih tindakan : ");
        printf("\n\n");
        isKulkasBerubah = false;

        if (pilihanOpsiKulkas == 0)
        {
            printSYellow("Operasi dibatalkan.\n\n");
        }
        else
        {
            Makanan operasiMakananKulkas;
            if (pilihanOpsiKulkas == 1)
            {
                if (nElmt(inventorySimulator(*currSimulator)) == 0)
                {
                    printSYellow("Inventory Kosong.\n\n");
                }
                else
                {
                    cetakIsiKulkas((kulkasSimulator(*currSimulator)).isi);
                    printf("\n");
                    printSYellow("Makanan dalam inventory: \n");
                    for (int i = 0; i < panjangLDinMakanan(content(inventorySimulator(*currSimulator))); i++)
                    {
                        printf("%d.", i + 1);
                        printSCyan(" Nama makanan: ");
                        cetakTeks(namaMakanan(elmtLDM(content(inventorySimulator(*currSimulator)), i)), 'b');
                        printf("\n");
                        printSCyan("   ID makanan: ");
                        cetakTeks(idTipe(elmtLDM(content(inventorySimulator(*currSimulator)), i)), 'c');
                        printf("\n");
                    }
                    printf("\n");

                    int pilihanOpsiMasukkanKeKulkas = Nil;

                    printSYellow("Pilih makanan yang ingin dimasukkan\n");
                    printSYellow("(0 untuk membatalkan)\n");
                    pilihanOpsiMasukkanKeKulkas = askForNumber(0, nElmt(inventorySimulator(*currSimulator)), "Pilihan makanan : ");

                    if (pilihanOpsiMasukkanKeKulkas == 0)
                    {
                        printSYellow("Operasi dibatalkan.\n\n");
                    }
                    else
                    {
                        Teks idDimasukkanKulkas = idTipe(elmtLDM(content(inventorySimulator(*currSimulator)), pilihanOpsiMasukkanKeKulkas - 1));
                        int searchInvForKulkas = 0;
                        boolean isSearchInvForKulkasFound = false;
                        while (!isSearchInvForKulkasFound)
                        {
                            isSearchInvForKulkasFound = teksSama(idDimasukkanKulkas, idTipe(elmtLDM(content(inventorySimulator(*currSimulator)), searchInvForKulkas)));
                            if (isSearchInvForKulkasFound)
                            {
                                operasiMakananKulkas = elmtLDM(content(inventorySimulator(*currSimulator)), searchInvForKulkas);
                            }
                            searchInvForKulkas++;
                        }

                        tambahIsiKulkas(&kulkasSimulator(*currSimulator), operasiMakananKulkas, &isKulkasBerubah);
                        if (isKulkasBerubah)
                        {
                            deleteByIdTipe(&inventorySimulator(*currSimulator), idTipe(elmtFQ(inventorySimulator(*currSimulator), pilihanOpsiMasukkanKeKulkas - 1)), &operasiMakananKulkas);
                            insertLastLDinNotifRaw(&backNS(*notifS), 'x', namaMakanan(operasiMakananKulkas));
                        }
                        printf("\n");
                    }
                }
            }
            else if (pilihanOpsiKulkas == 2)
            {
                keluarkanIsiKulkas(&kulkasSimulator(*currSimulator), &operasiMakananKulkas, &isKulkasBerubah);
                if (isKulkasBerubah)
                {
                    enqueueInventory(&inventorySimulator(*currSimulator), operasiMakananKulkas);
                    insertLastLDinNotifRaw(&backNS(*notifS), 'y', namaMakanan(operasiMakananKulkas));
                }
                printf("\n");
            }
            else if (pilihanOpsiKulkas == 3)
            {
                ubahIsiKulkas(&kulkasSimulator(*currSimulator), &isKulkasBerubah);
                printf("\n");
            }
            if (isKulkasBerubah)
            {
                Waktu time;
                time = buatWaktu(0, 0, 1, 0);
                majukanWaktuSimulator(currSimulator, time, notifS);
                *isChangeSimulator = true;
            }
        }
    }
}
