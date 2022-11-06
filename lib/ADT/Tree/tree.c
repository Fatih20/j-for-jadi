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
            cetakTeks(NamaMakananTree(t), 'b');
            printf(" : ");
            cetakTeks(AksiTree(t), 'm');
            printf(" - ");
        }
        for (int i = 0; i < ListNodeNEff(Children(t)); i++)
        {
            cetakTeks(NamaMakananTree(Child(t, i)), 'b');
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
        printf("    %d. ", i + 1);
        cetakTeks(NamaMakananTree(ListNodeELMT(l, i)), 'b');
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
