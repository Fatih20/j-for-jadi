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

LDinMakanan ingredientGenerator(Address resepMakanan, int id)
{
    int jumlah = ListNodeNEff(Children(resepMakanan));
    LDinMakanan ingredients;
    buatLDinMakanan(&ingredients, jumlah);
    for (int i = 0; i < jumlah; i++)
    {
        insertLastLDinMakanan(&ingredients, MakananTree(Child(resepMakanan, i)));
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
    buatTeks("* Prekursor yang tidak dimiliki tapi telah direkomendasikan untuk dibuat\n", &pNoteT);
    Teks iNoteT;
    buatTeks("* Bahan makanan yang sudah ada di inventory\n", &iNoteT);
    cetakTeks(iNoteT, 'g');
    cetakTeks(pNoteT, 'r');

    Teks iRecT;
    buatTeks("Makanan yang bisa langsung dibuat :\n", &iRecT);
    cetakTeks(iRecT, 'e');
    for (int i = 0; i < ListNodeNEff(iRec); i++)
    {
        int idxOResep = searchResep(resep, elmtLDT(iRec, i), 0, ListNodeNEff(resep) - 1);
        Tree observedResep = ListNodeELMT(resep, idxOResep);
        LDinMakanan ingredients = ingredientGenerator(observedResep, teksToInt(elmtLDT(iRec, i)));
        cetakTeks(NamaMakananTree(observedResep), 'e');
        printf(" : ");
        int j;
        for (j = 0; j < nEffLDM(ingredients) - 1; j++)
        {
            cetakTeks(namaMakanan(elmtLDM(ingredients, j)), 'g');
            printf(" - ");
        }
        cetakTeks(namaMakanan(elmtLDM(ingredients, j)), 'g');
        printf("\n");
    }

    Teks pRecT;
    buatTeks("Makanan yang perlu dibuat dulu bahan-bahannya :\n", &pRecT);
    cetakTeks(pRecT, 'e');
    for (int k = 0; k < ListNodeNEff(pRec); k++)
    {
        int idxOResep = searchResep(resep, elmtLDT(pRec, k), 0, ListNodeNEff(resep) - 1);
        Tree observedResep = ListNodeELMT(resep, idxOResep);
        LDinMakanan ingredients = ingredientGenerator(observedResep, teksToInt(elmtLDT(pRec, k)));
        cetakTeks(NamaMakananTree(observedResep), 'e');
        printf(" : ");
        int m;
        for (m = 0; m < nEffLDM(ingredients) - 1; m++)
        {
            cetakTeks(namaMakanan(elmtLDM(ingredients, m)), ElmtFS(inventorySet, teksToInt(idTipe(elmtLDM(ingredients, m)))) ? 'g' : 'r');
            printf(" - ");
        }
        cetakTeks(namaMakanan(elmtLDM(ingredients, m)), ElmtFS(inventorySet, teksToInt(idTipe(elmtLDM(ingredients, m)))) ? 'g' : 'r');
        printf("\n");
    }
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
    printRecommendation(iRec, pRec, resep, inv);
};

boolean isFoodRecommended(Tree observedFood, LDinFoodSet resepLDFS, FoodSet inventory)
{
    boolean isRec = false;
    Teks idObservedT = IdTipeTree(observedFood);
    int idObserved = teksToInt(idObservedT);
    int idxOResep = searchOrderedLDFS(resepLDFS, idObservedT);
    if (idxOResep == -1)
    {
        printf("ID not found in recipe\n");
        return false;
    }

    FoodSet observedResep = elmtLDFS(resepLDFS, idxOResep);
    boolean isSubset = isSubsetfs(observedResep, inventory);
    if (isSubset)
    {
        printf("It's recommended from subset\n");
        return true;
    }

    printf("Not subset, entering union-find\n");
    boolean recConclusive = false;
    while (!recConclusive)
    {
        FoodSet diff = differenceFoodSet(observedResep, inventory);
        LDinTeks idOfUFood = setToList(diff);
        // cetakFoodSet(diff);
        printLDinTeks(idOfUFood);
        boolean noLeaves = true;
        int j = 0;
        while (noLeaves && j <= lastIdxLDinTeks(idOfUFood))
        {
            Teks curIdT = elmtLDT(idOfUFood, j);
            int idxResepToA = searchOrderedLDFS(resepLDFS, curIdT);
            noLeaves = idxResepToA != -1;
            if (!noLeaves)
            {
                printf("One of the food is leaves : ");
                cetakTeks(curIdT, 'e');
                printf("\n");
                recConclusive = true;
            }
            else
            {
                FoodSet resepToAdd = elmtLDFS(resepLDFS, j);
                int idOfMResepToAdd = IdFS(resepToAdd);
                decrementFS(&observedResep, teksToInt(curIdT));
                observedResep = addFoodSet(observedResep, resepToAdd);
            }
            j += noLeaves;
        }
        if (!recConclusive)
        {
            boolean isSubset = isSubsetfs(observedResep, inventory);
            if (isSubset)
            {
                isRec = true;
                recConclusive = true;
                printf("It's recommended from union-find\n");
            }
        }
    }
    return isRec;
}

void recommendTiered(LDinFoodSet resepLDFS, FoodQueue inventory, ListNode resep)
{
    FoodSet rec;
    Teks recSet;
    buatTeks("Inventory", &recSet);
    buatIdLFSKosong(&rec, recSet);

    Teks inventoryName;
    buatTeks("Inventory", &inventoryName);
    FoodSet invFS = FQToFS(inventory, inventoryName);

    for (int i = 0; i < nEffLDFS(resep); i++)
    {
        Tree observedFood = ListNodeELMT(resep, i);
        int idObserved = teksToInt(IdTipeTree(observedFood));
        incrementIFS(&rec, idObserved, isFoodRecommended(observedFood, resepLDFS, invFS));
    }
    LDinTeks test;
    buatLDinTeks(&test, 10);
    printRecommendation(setToList(rec), test, resep, invFS);
}
