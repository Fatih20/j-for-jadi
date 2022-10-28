/* LIST TREE */

#include "listtree.h"
#include <stdio.h>

Tree getMarkListTree()
{
    Teks MARK;
    buatTeks("#", &MARK);
    Tree ret = newTreeNode(MARK, 0);
    return ret;
}

void buatListTree(ListTree *l)
{
    for (int i = 0; i < ListTreeCap; i++)
    {
        ListTreeELMT(*l, i) = getMarkListTree();
    }
}

int panjangListTree(ListTree l)
{
    int res = 0;
    for (int i = 0; i < ListTreeCap; i++)
    {
        if (!teksSama(MakananTree(ListTreeELMT(l, i)), MakananTree(getMarkListTree())))
        {
            res += 1;
        }
    }
    return res;
}
Address isAllocated(treeEl val, ListTree l)
{
    for (int i = 0; i < panjangListTree(l); i++)
    {
        if (teksSama(MakananTree(ListTreeELMT(l, i)), val))
        {
            return ListTreeELMT(l, i);
        }
        for (int j = 0; j < ListNodeNEff(Children(ListTreeELMT(l, i))); j++)
        {
            if (teksSama(MakananTree(Child(ListTreeELMT(l, i), j)), val))
            {
                return Child(ListTreeELMT(l, i), j);
            }
        }
    }
    return NULL;
}

void displayListTree(ListTree l)
{

    /* bagian cookbooknya nnti dipindahin ke mainn*/
    printf("==================================\n");
    printf("             COOKBOOK             \n");
    printf("==================================\n");
    for (int i = 0; i < panjangListTree(l); i++)
    {
        printf("%d. ", i + 1);
        cetakTeks(MakananTree(ListTreeELMT(l, i)));
        printf("\n");
    }
    int makanan;
    scanf("%d", &makanan);
    printf("==================================\n");
    printf("          Resep ");
    cetakTeks(MakananTree(ListTreeELMT(l, makanan - 1)));
    printf("          \n");
    printf("==================================\n");
    displayTree(ListTreeELMT(l, makanan - 1));
}

void readListTree(ListTree *t, char *file, LStatMakanan(listMakanan))
{
    startMBFile(file);
    int n = teksToInt(elmtLDT(currentRow, 0));
    buatListTree(t);
    for (int i = 0; i < n; i++)
    {
        advMBFile();
        int jumlahChild = teksToInt(elmtLDT(currentRow, 1));
        Teks idTemp = elmtLDT(currentRow, 0);
        Teks makananTemp = getNameFromID(listMakanan, idTemp);
        Address addressTemp = isAllocated(makananTemp, *t);
        if (addressTemp != NULL)
        {
            ListTreeELMT(*t, i) = addressTemp;
        }
        else
        {
            ListTreeELMT(*t, i) = newTreeNode(makananTemp, jumlahChild);
        }
        int k = 0;
        for (int j = 2; j < panjangLDinTeks(currentRow); j++)
        {

            idTemp = elmtLDT(currentRow, j);
            makananTemp = getNameFromID(listMakanan, idTemp);
            addressTemp = isAllocated(makananTemp, *t);
            if (addressTemp != NULL)
            {
                insertLastListNode(&Children(ListTreeELMT(*t, i)), addressTemp);
            }
            else
            {
                insertLastListNode(&Children(ListTreeELMT(*t, i)), newTreeNode(makananTemp, 0));
            }
        }
    }
    // for (int i = 0; i < panjangListTree(*t); i++)
    // {
    //     displayTree(ListTreeELMT(*t, i));
    // }
};

Tree getParent(ListTree t, LDinTeks lt)
{
    Tree parent = NULL;
    for (int i = 0; i < panjangListTree(t) && parent == NULL; i++)
    {
        boolean isParent = true;
        for (int j = 0; j < nEffLDT(lt); j++)
        {
            if (!isChildOf(elmtLDT(lt, j), ListTreeELMT(t, i)))
            {
                isParent = false;
            }
        }
        if (isParent)
        {
            parent = ListTreeELMT(t, i);
        }
    }
    return parent;
}