#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Address newTreeNode(treeEl val)
{
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        MAKANAN(p) = val;
        ListNode temp;
        createListNode(&temp, CAPACITY);
        CHILDREN(p) = temp;
    }
    return p;
}

void CreateTree(treeEl makanan, ListNode children, Tree *p)
{
    if ((*p) != NULL)
    {
        MAKANAN((*p)) = makanan;
        ListNode temp;
        copyListNode(children, &temp);
        CHILDREN(*p) = temp;
    }
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

void createListNode(ListNode *l, int capacity)
{
    (*l).child = malloc((capacity * sizeof(ListNodeEl)));
    ListNodeNEff(*l) = 0;
    ListNodeCap(*l) = capacity;
};

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
void displayTree(Tree t)
{
    if (t != NULL)
    {
        for (int i = 0; i < ListNodeNEff(CHILDREN(t)); i++)
        {
            displayTree(CHILD(t, i));
        }
        if (!isEmptyListNode(CHILDREN(t)))
        {
            cetakTeks(MAKANAN(t));
            printf(" - ");
        }
        for (int i = 0; i < ListNodeNEff(CHILDREN(t)); i++)
        {
            cetakTeks(MAKANAN(CHILD(t, i)));
            printf(",");
        }
        if (!isEmptyListNode(CHILDREN(t)))
        {
            printf("\n");
        }
    }
}

int main()
{
    Tree t;
    Teks t1, t2, t3, t4, t5, t6;
    buatTeks("ayam", &t1);
    buatTeks("ayam potong", &t2);
    buatTeks("bawang", &t3);
    buatTeks("wortel", &t4);
    buatTeks("putih", &t5);
    Tree ayam = newTreeNode(t1);
    Tree bawang = newTreeNode(t3);
    Tree ayampotong = newTreeNode(t2);
    Tree wortel = newTreeNode(t4);
    Tree putih = newTreeNode(t5);
    insertLastListNode(&CHILDREN(ayam), bawang);
    insertLastListNode(&CHILDREN(ayam), ayampotong);
    insertLastListNode(&CHILDREN(ayam), wortel);
    insertLastListNode(&CHILDREN(bawang), putih);
    displayTree(ayam);
}