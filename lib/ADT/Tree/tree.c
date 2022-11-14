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

boolean isIdxEffListNode(ListNode l, int idx)
{
    return idx >= 0 && idx < ListNodeNEff(l);
}

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

void insertFirstListNode(ListNode *l, Address val)
{
    insertAtListNode(l, val, 0);
}

void insertAtListNode(ListNode *l, Address val, IdxType idx)
{
    if (isFullListNode(*l))
    {
        expandListNode(l, 1);
    }
    ListNodeNEff(*l) += 1;
    if (isIdxEffListNode(*l, idx))
    {
        for (int i = ListNodeNEff(*l) - 1; i > idx; i--)
        {
            ListNodeELMT(*l, i) = ListNodeELMT(*l, i - 1);
        }
        ListNodeELMT(*l, idx) = val;
    }
    else
    {
        printf("idx tidak efektif!\n");
    }
};

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
    return (ListNodeNEff(l) == 0);
}

int sortedInsertListNode(ListNode *l, Address val)
{
    if (isEmptyListNode(*l))
    {
        insertLastListNode(l, val);
        return 0;
    }
    else
    {
        if (teksToInt(IdTipeTree(ListNodeELMT(*l, 0))) > teksToInt(IdTipeTree(val)))
        {
            insertFirstListNode(l, val);
            return 0;
        }
        else if (teksToInt(IdTipeTree(ListNodeELMT(*l, ListNodeNEff(*l) - 1))) < teksToInt(IdTipeTree(val)))
        {
            insertLastListNode(l, val);
            return ListNodeNEff(*l) - 1;
        }
        else
        {
            for (int i = 0; i < ListNodeNEff(*l); i++)
            {
                if (teksToInt(IdTipeTree(ListNodeELMT(*l, i))) >= teksToInt(IdTipeTree(val)))
                {
                    insertAtListNode(l, val, i);
                    return i;
                    break;
                }
            }
        }
    }
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
        int idx = -1;
        if (addressTemp != NULL)
        {
            idx = sortedInsertListNode(t, addressTemp);
        }
        else
        {
            idx = sortedInsertListNode(t, newTreeNode(makananTemp, jumlahChild));
        }
        int temp;
        for (int j = 2; j < panjangLDinTeks(currentRow); j++)
        {
            idTemp = elmtLDT(currentRow, j);
            makananTemp = getMakananFromID(listMakanan, idTemp);
            addressTemp = isAllocated(makananTemp, *t);
            if (addressTemp != NULL)
            {
                if (i == 9 && j == 3)
                {
                    displayTree(ListNodeELMT(*t, idx));
                }

                temp = sortedInsertListNode(&Children(ListNodeELMT(*t, idx)), addressTemp);
            }
            else
            {
                temp = sortedInsertListNode(&Children(ListNodeELMT(*t, idx)), newTreeNode(makananTemp, 0));
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
        Address temp = isAllocated(val, Children(ListNodeELMT(l, i)));
        if (temp != NULL)
        {
            return temp;
        }
        // for (int j = 0; j < ListNodeNEff(Children(ListNodeELMT(l, i))); j++)
        // {
        //     // if (isMakananEqual(MakananTree(Child(ListNodeELMT(l, i), j)), val))
        //     // {
        //     //     return Child(ListNodeELMT(l, i), j);
        //     // }
        // }
    }
    return NULL;
}

int searchResep(ListNode l, Teks idTipe, int lo, int hi)
{
    if (hi >= lo)
    {
        int mid = lo + ((hi - lo) / 2);
        int idTipeCurr = teksToInt(IdTipeTree(ListNodeELMT(l, mid)));
        int idTipeVal = teksToInt(idTipe);

        if (idTipeCurr == idTipeVal)
        {
            return mid;
        }
        if (idTipeCurr > idTipeVal)
        {
            return searchResep(l, idTipe, lo, mid - 1);
        }
        return searchResep(l, idTipe, mid + 1, hi);
    }
    return IDX_UNDEF;
}