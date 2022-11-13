#include "recommendation.h"

FoodSet FQToFS(FoodQueue FQ, Teks nama)
{
    FoodSet fs;
    buatIdLFSKosong(&fs, nama);
    for (int i = headFQ(FQ); i <= tailFQ(FQ); i++)
    {
        int idToAdd = teksToInt(idTipe(elmtFQ(FQ, i)));
        ElmtFS(fs, idToAdd) = true;
    }
    return fs;
};

LDinFoodSet resepToLDFS(ListNode resep)
{
    LDinFoodSet resepLDFS;
    buatLDinFoodSet(&resepLDFS, ListNodeCap(resep));
    for (int i = 0; i < ListNodeNEff(resep); i++)
    {
        Address observedRecipe = ListNodeELMT(resep, i);
        Makanan observedMakanan = MakananTree(observedRecipe);
        FoodSet fsToAdd;
        buatFSKosong(&fsToAdd, namaMakanan(observedMakanan), idTipe(observedMakanan));
        ListNode ingredients = Children(observedRecipe);
        for (int j = 0; j < ListNodeNEff(ingredients); j++)
        {
            Makanan observedIngredient = MakananTree(ListNodeELMT(ingredients, j));
            ElmtFS(fsToAdd, teksToInt(idTipe(observedIngredient))) = true;
        }
        insertOrderedLDFS(&resepLDFS, fsToAdd);
    }
    return resepLDFS;
};

LDinTeks ingredientGenerator(Address resepMakanan, int id)
{
    int jumlah = ListNodeNEff(Children(resepMakanan));
    LDinTeks ingredients;
    buatLDinTeks(&ingredients, jumlah);
    for (int i = 0; i < jumlah; i++)
    {
        insertLastLDinTeks(&ingredients, NamaMakananTree(Child(resepMakanan, i)));
    }

    return ingredients;
};

void printRecommendation(LDinTeks iRec, LDinTeks pRec, ListNode resep, FoodSet inventorySet)
{
    Teks recommendT;
    buatTeks("REKOMENDASI", &recommendT);
    printSGreen("============================================================\n");
    printf("                               ");
    cetakTeks(recommendT, 'y');
    printf("                       \n");
    printSGreen("============================================================\n\n");

    Teks pNoteT;
    buatTeks("* Prekursor yang tidak dimiliki tapi direkomendasikan untuk dibuat\n", &pNoteT);
    Teks iNoteT;
    buatTeks("* Bahan makanan yang sudah ada di inventory\n", &iNoteT);
    cetakTeks(pNoteT, 'r');
    cetakTeks(iNoteT, 'g');

    Teks iRecT;
    buatTeks("Makanan yang bisa langsung dibuat :\n", &iRecT);
    for (int i = 0; i < ListNodeNEff(iRec); i++)
    {
        int idxOResep = searchResep(resep, elmtLDT(iRec, i), 0, ListNodeNEff(resep));
        Tree observedResep = ListNodeELMT(resep, idxOResep);
        LDinTeks =
    }

    Teks pRecT;
    buatTeks("Makanan yang perlu dibuat dulu bahan-bahannya :\n", &pRecT);

    cetakTeks(iRecT, 'e');
    cetakTeks(pRecT, 'e');
};

void recommend(LDinFoodSet resepLDFS, FoodQueue inventory, ListNode resep)
{
    if (isEmptyFQ(inventory))
    {
        Teks noRec;
        buatTeks("Inventory kosong, tidak ada makanan yang bisa direkomendasikan!\n", &noRec);
        cetakTeks(noRec, 'r');
        return;
    }

    int nResep = nEffLDFS(resepLDFS);

    Teks inventoryName;
    buatTeks("Inventory", &inventoryName);
    FoodSet inv = FQToFS(inventory, inventoryName);

    Teks aInventoryName;
    buatTeks("Augmented Inventory", &aInventoryName);
    FoodSet augInv = FQToFS(inventory, aInventoryName);

    Teks iRecSetN;
    buatTeks("Immediately Cookable", &iRecSetN);
    FoodSet iRecSet;
    buatIdLFSKosong(&iRecSet, iRecSetN);

    Teks pRecSetN;
    buatTeks("Not Immediately Cookable", &pRecSetN);
    FoodSet pRecSet;
    buatIdLFSKosong(&pRecSet, pRecSetN);

    Teks sRecSetN;
    buatTeks("Cookable", &sRecSetN);
    FoodSet sRecSet;
    buatIdLFSKosong(&sRecSet, sRecSetN);

    LDinTeks sRec;
    buatLDinTeks(&sRec, 20);
    LDinTeks iRec;
    buatLDinTeks(&iRec, 10);
    LDinTeks pRec;
    buatLDinTeks(&pRec, 10);

    boolean recMade = false;
    boolean firstIteration = true;
    do
    {
        for (int i = 0; i < nEffLDFS(resepLDFS); i++)
        {
            recMade = false;
            FoodSet observedRSet = elmtLDFS(resepLDFS, i);
            if (!ElmtFS(augInv, IdFS(observedRSet)))
            {
                boolean isORSubset = isSubsetfs(observedRSet, augInv);
                printf("%d\n", isORSubset);
                if (isORSubset)
                {
                    recMade = true;
                    int recID = IdFS(observedRSet);
                    ElmtFS(augInv, recID) = true;
                    ElmtFS(sRecSet, recID) = true;
                    ElmtFS(iRecSet, recID) = firstIteration;
                    ElmtFS(pRecSet, recID) = !firstIteration;
                    insertLastLDinTeks(&sRec, intToTeks(recID));
                    if (firstIteration)
                    {
                        insertLastLDinTeks(&iRec, intToTeks(recID));
                    }
                    else
                    {
                        insertLastLDinTeks(&pRec, intToTeks(recID));
                    }
                }
            }
        }
        recMade = nEffLDT(sRec) == nResep ? false : recMade;
        firstIteration = false;

    } while (recMade);
};

void printRecommendation(Teks idMakanan, ListNode resep, FoodSet inventorySet)
{
    for (int i = 0; i < ListNodeNEff(resep); i++)
    {
    }
};