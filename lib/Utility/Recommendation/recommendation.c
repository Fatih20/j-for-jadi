#include "recommendation.h"

FoodSet FQToFS(FoodQueue FQ, Teks nama)
{
    FoodSet fs;
    buatIdLFSKosong(&fs, nama);
    for (int i = headFQ(FQ); i < tailFQ(FQ); i++)
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
