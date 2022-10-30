#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

/* TREE */
Address newTreeNode(treeEl val, int childCnt)
{
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        MakananTree(p) = val;
        ListNode temp;
        createListNode(&temp, childCnt);
        Children(p) = temp;
    }
    return p;
}

void displayTree(Tree t)
{
    if (t != NULL)
    {
        for (int i = 0; i < ListNodeNEff(Children(t)); i++)
        {
            displayTree(Child(t, i));
        }
        if (!isEmptyListNode(Children(t)))
        {
            printf("Buat ");
            cetakTeks(NamaMakananTree(t));
            printf(" : ");
            cetakTeks(AksiTree(t));
            printf(" - ");
        }
        for (int i = 0; i < ListNodeNEff(Children(t)); i++)
        {
            cetakTeks(NamaMakananTree(Child(t, i)));
            if (i != ListNodeNEff((Children(t))) - 1)
            {
                printf(", ");
            }
        }
        if (!isEmptyListNode(Children(t)))
        {
            printf("\n");
        }
    }
}

boolean isChildOf(treeEl val, Tree t)
{
    for (int i = 0; i < ListNodeNEff(Children(t)); i++)
    {
        if (isMakananEqual(MakananTree(Child(t, i)), val))
        {
            return true;
        }
    }
    return false;
}

/* LIST NODE */

void createListNode(ListNode *l, int capacity)
{
    (*l).child = malloc((capacity * sizeof(ListNodeEl)));
    ListNodeNEff(*l) = 0;
    ListNodeCap(*l) = capacity;
};

void expandListNode(ListNode *l, int n)
{
    ListNodeCap(*l) += n;
    (*l).child = realloc((*l).child, (ListNodeCap(*l)) * sizeof(ListNodeEl));
}

void insertLastListNode(ListNode *l, Address val)
{
    if (isFullListNode(*l))
    {
        expandListNode(l, 1);
    }
    ListNodeNEff(*l) += 1;
    ListNodeELMT(*l, ListNodeNEff(*l) - 1) = val;
}

boolean isFullListNode(ListNode l)
{
    return ListNodeNEff(l) == ListNodeCap(l);
}

void copyListNode(ListNode l1, ListNode *l2)
{
    createListNode(l2, ListNodeCap(l1));
    for (int i = 0; i < ListNodeNEff(*l2); i++)
    {
        ListNodeELMT(*l2, i) = ListNodeELMT(l1, i);
    }
    ListNodeNEff(*l2) = ListNodeNEff(l1);
    ListNodeCap(*l2) = ListNodeCap(l1);
}

boolean isEmptyListNode(ListNode l)
{
    return ListNodeNEff(l) == 0;
}

void readListNode(ListNode *t, char *file, LStatMakanan listMakanan)
{
    startMBFile(file);
    int n = teksToInt(elmtLDT(currentRow, 0));
    createListNode(t, n);
    for (int i = 0; i < n; i++)
    {
        advMBFile();
        int jumlahChild = teksToInt(elmtLDT(currentRow, 1));
        Teks idTemp = elmtLDT(currentRow, 0);
        treeEl makananTemp = getMakananFromID(listMakanan, idTemp);
        Address addressTemp = isAllocated(makananTemp, *t);
        if (addressTemp != NULL)
        {
            insertLastListNode(t, addressTemp);
        }
        else
        {
            insertLastListNode(t, newTreeNode(makananTemp, jumlahChild));
        }
        int k = 0;
        for (int j = 2; j < panjangLDinTeks(currentRow); j++)
        {

            idTemp = elmtLDT(currentRow, j);
            makananTemp = getMakananFromID(listMakanan, idTemp);
            addressTemp = isAllocated(makananTemp, *t);
            if (addressTemp != NULL)
            {
                insertLastListNode(&Children(ListNodeELMT(*t, i)), addressTemp);
            }
            else
            {
                insertLastListNode(&Children(ListNodeELMT(*t, i)), newTreeNode(makananTemp, 0));
            }
        }
    }
};

void displayListNode(ListNode l)
{
    for (int i = 0; i < ListNodeNEff(l); i++)
    {
        printf("%d. ", i + 1);
        cetakTeks(NamaMakananTree(ListNodeELMT(l, i)));
        printf("\n");
    }
}

Address isAllocated(treeEl val, ListNode l)
{
    for (int i = 0; i < ListNodeNEff(l); i++)

    {
        if (isMakananEqual(MakananTree(ListNodeELMT(l, i)), val))
        {
            return ListNodeELMT(l, i);
        }
        for (int j = 0; j < ListNodeNEff(Children(ListNodeELMT(l, i))); j++)
        {
            if (isMakananEqual(MakananTree(Child(ListNodeELMT(l, i), j)), val))
            {
                return Child(ListNodeELMT(l, i), j);
            }
        }
    }
    return NULL;
}

/* untuk sementara ga perlu */
// Tree getParent(ListNode t, LDinTeks lt)
// {
//     Tree parent = NULL;
//     for (int i = 0; i < panjangListNode(t) && parent == NULL; i++)
//     {
//         boolean isParent = true;
//         for (int j = 0; j < nEffLDT(lt); j++)
//         {
//             if (!isChildOf(elmtLDT(lt, j), ListNodeELMT(t, i)))
//             {
//                 isParent = false;
//             }
//         }
//         if (isParent)
//         {
//             parent = ListNodeELMT(t, i);
//         }
//     }
//     return parent;
// }
// void readTree(ListTree *t, char *file, LStatMakanan(listMakanan))
// {
//     startMBFile(file);
//     int n = teksToInt(elmtLDT(currentRow, 0));
//     buatListTree(t);
//     for (int i = 0; i < n; i++)
//     {
//         advMBFile();
//         int jumlahChild = teksToInt(elmtLDT(currentRow, 1));
//         Teks idTemp = elmtLDT(currentRow, 0);
//         Teks makananTemp = getNameFromID(listMakanan, idTemp);
//         Address addressTemp = isAllocated(makananTemp, *t);
//         if (addressTemp != NULL)
//         {
//             ListTreeELMT(*t, i) = addressTemp;
//         }
//         else
//         {
//             ListTreeELMT(*t, i) = newTreeNode(makananTemp, jumlahChild);
//         }
//         int k = 0;
//         for (int j = 2; j < panjangLDinTeks(currentRow); j++)
//         {

//             idTemp = elmtLDT(currentRow, j);
//             makananTemp = getNameFromID(listMakanan, idTemp);
//             addressTemp = isAllocated(makananTemp, *t);
//             if (addressTemp != NULL)
//             {
//                 insertLastListNode(&Children(ListTreeELMT(*t, i)), addressTemp);
//             }
//             else
//             {
//                 insertLastListNode(&Children(ListTreeELMT(*t, i)), newTreeNode(makananTemp, 0));
//             }
//         }
// }
// for (int i = 0; i < panjangListTree(*t); i++)
// {
//     displayTree(ListTreeELMT(*t, i));
// }
// }
// ;

/* BUAT IS ALLOCATED --> parameternya Tree* listoftree yang mau ditraverse, Teks makanan yang mau dicarii --> returnnya Address*/
// int main()
// {
//     // Teks nasi, lalapan, ayamgorengsambal, nasiuduk, ayamgoreng, sambalgoreng, ayamtepung, minyakgoreng, sambal;
//     // buatTeks("nasi uduk pecel", &nasi);
//     // buatTeks("ayam goreng extra sambal", &ayamgorengsambal);
//     // buatTeks("lalapan", &lalapan);
//     // buatTeks("nasi uduk", &nasiuduk);
//     // buatTeks("ayam goreng", &ayamgoreng);
//     // buatTeks("sambal goreng", &sambalgoreng);
//     // buatTeks("ayam tepung", &ayamtepung);
//     // buatTeks("minyak goreng", &minyakgoreng);
//     // buatTeks("sambal", &sambal);

//     // Tree Nasi = newTreeNode(nasi, 0);
//     // Tree Lalapan = newTreeNode(lalapan, 0);
//     // Tree Ayamgorengsambal = newTreeNode(ayamgorengsambal, 0);
//     // Tree Nasiuduk = newTreeNode(nasiuduk, 0);
//     // Tree Ayamgoreng = newTreeNode(ayamgoreng, 0);
//     // Tree Sambalgoreng = newTreeNode(sambalgoreng, 0);
//     // Tree Ayamtepung = newTreeNode(ayamtepung, 0);
//     // Tree Minyakgoreng = newTreeNode(minyakgoreng, 0);
//     // Tree Sambal = newTreeNode(sambal, 0);

//     // insertLastListNode(&(Children(Nasi)), Lalapan);
//     // insertLastListNode(&(Children(Nasi)), Ayamgorengsambal);
//     // insertLastListNode(&(Children(Nasi)), Nasiuduk);
//     // insertLastListNode(&(Children(Ayamgorengsambal)), Ayamgoreng);
//     // insertLastListNode(&(Children(Ayamgorengsambal)), Sambalgoreng);
//     // insertLastListNode(&(Children(Ayamgoreng)), Ayamtepung);
//     // insertLastListNode(&(Children(Ayamgoreng)), Minyakgoreng);
//     // insertLastListNode(&(Children(Sambalgoreng)), Minyakgoreng);
//     // insertLastListNode(&(Children(Sambalgoreng)), Sambal);

//     // displayTree(Nasi);
//     ListTree t;
//     readTree(&t, "resepcfg.txt");
// }