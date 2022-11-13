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

void recommend(LDinFoodSet resepLDFS, FoodQueue inventory)
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
    FoodSet augInv = FQToFS(inventory, inventoryName);
    cetakFoodQueue(inventory);
    cetakFoodSet(augInv);

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
                    insertLastLDinTeks(&sRec, NameFS(observedRSet));
                    if (firstIteration)
                    {
                        insertLastLDinTeks(&iRec, NameFS(observedRSet));
                    }
                    else
                    {
                        insertLastLDinTeks(&pRec, NameFS(observedRSet));
                    }
                }
            }
        }
        recMade = nEffLDT(sRec) == nResep ? false : recMade;
        firstIteration = false;

    } while (recMade);
    Teks iRecT;
    buatTeks("Makanan yang bisa langsung dibuat :\n", &iRecT);
    Teks pRecT;
    buatTeks("Makanan yang perlu dibuat dulu bahan-bahannya :\n", &pRecT);

    cetakTeks(iRecT, 'g');
    printLDinTeks(iRec);
    cetakTeks(pRecT, 'c');
    printLDinTeks(pRec);
};