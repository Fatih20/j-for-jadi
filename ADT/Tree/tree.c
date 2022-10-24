#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

Address newTreeNode(treeEl val)
{
    Address p = (Address)malloc(sizeof(TreeNode));
    if (p != NULL)
    {
        MakananTree(p) = val;
        ListNode temp;
        createListNode(&temp, CAPACITY);
        Children(p) = temp;
    }
    return p;
}

void CreateTree(treeEl makanan, ListNode children, Tree *p)
{
    if ((*p) != NULL)
    {
        MakananTree((*p)) = makanan;
        ListNode temp;
        copyListNode(children, &temp);
        Children(*p) = temp;
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
        for (int i = 0; i < ListNodeNEff(Children(t)); i++)
        {
            displayTree(Child(t, i));
        }
        if (!isEmptyListNode(Children(t)))
        {
            cetakTeks(MakananTree(t));
            printf(" - ");
        }
        for (int i = 0; i < ListNodeNEff(Children(t)); i++)
        {
            cetakTeks(MakananTree(Child(t, i)));
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

Tree *readTree()
{
    int n;
    printf("Masukkan jumlah resep: ");
    scanf("%d", &n);
    Teks mark;
    buatTeks("#", &mark);
    Tree ListResep[n];
    for (int i = 0; i < n; i++)
    {
        ListResep[i] = newTreeNode(mark);
    }
    for (int i = 0; i < n; i++)
    {
        char temp[100];
        scanf("%s", &temp);
        Teks tempTeks;
        buatTeks(temp, &tempTeks);
        MakananTree(ListResep[i]) = tempTeks;
        cetakTeks(MakananTree(ListResep[i]));
        printf("Masukkan jumlah bahan untuk resep ini: ");
        int c;
        scanf("%d", &c);
        for (int j = 0; j < c; j++)
        {
            char bahan[100];
            scanf("%s", &bahan);
            Teks Bahan;
            buatTeks(bahan, &Bahan);
            Tree BAHAN = newTreeNode(Bahan);
            insertLastListNode(&Children(ListResep[i]), BAHAN);
        }
    }
    for (int i = 0; !teksSama(MakananTree(ListResep[i]), mark); i++)
    {
        displayTree(ListResep[i]);
    }
};

/* BUAT IS ALLOCATED --> parameternya Tree* listoftree yang mau ditraverse, Teks makanan yang mau dicarii --> returnnya Address*/
int main()
{
    Teks nasi, lalapan, ayamgorengsambal, nasiuduk, ayamgoreng, sambalgoreng, ayamtepung, minyakgoreng, sambal;
    buatTeks("nasi uduk pecel", &nasi);
    buatTeks("ayam goreng extra sambal", &ayamgorengsambal);
    buatTeks("lalapan", &lalapan);
    buatTeks("nasi uduk", &nasiuduk);
    buatTeks("ayam goreng", &ayamgoreng);
    buatTeks("sambal goreng", &sambalgoreng);
    buatTeks("ayam tepung", &ayamtepung);
    buatTeks("minyak goreng", &minyakgoreng);
    buatTeks("sambal", &sambal);

    Tree Nasi = newTreeNode(nasi);
    Tree Lalapan = newTreeNode(lalapan);
    Tree Ayamgorengsambal = newTreeNode(ayamgorengsambal);
    Tree Nasiuduk = newTreeNode(nasiuduk);
    Tree Ayamgoreng = newTreeNode(ayamgoreng);
    Tree Sambalgoreng = newTreeNode(sambalgoreng);
    Tree Ayamtepung = newTreeNode(ayamtepung);
    Tree Minyakgoreng = newTreeNode(minyakgoreng);
    Tree Sambal = newTreeNode(sambal);

    insertLastListNode(&(Children(Nasi)), Lalapan);
    insertLastListNode(&(Children(Nasi)), Ayamgorengsambal);
    insertLastListNode(&(Children(Nasi)), Nasiuduk);
    insertLastListNode(&(Children(Ayamgorengsambal)), Ayamgoreng);
    insertLastListNode(&(Children(Ayamgorengsambal)), Sambalgoreng);
    insertLastListNode(&(Children(Ayamgoreng)), Ayamtepung);
    insertLastListNode(&(Children(Ayamgoreng)), Minyakgoreng);
    insertLastListNode(&(Children(Sambalgoreng)), Minyakgoreng);
    insertLastListNode(&(Children(Sambalgoreng)), Sambal);

    displayTree(Nasi);

    readTree();
}