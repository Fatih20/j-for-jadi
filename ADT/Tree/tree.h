#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../Teks/teks.h"

/* Selektor */
#define Child(p, i) (p)->children.child[i]
#define Children(p) (p)->children
#define MakananTree(p) (p)->makanan
#define AksiTree(p) (p)->aksi
#define ListNodeCap(l) (l).capacity
#define ListNodeELMT(l, i) (l).child[i]
#define ListTreeCap 100
#define ListTreeELMT(l, i) (l).tree[i]
#define ListNodeNEff(l) (l).nEff

typedef Teks treeEl;
typedef struct treeNode *Address;
typedef Address ListNodeEl;
typedef struct listNode
{
   Address *child;
   int capacity;
   int nEff;
} ListNode;

typedef struct treeNode
{
   treeEl aksi;
   treeEl makanan;
   ListNode children;
} TreeNode;

/* Definisi PohonBiner */
/* pohon Biner kosong p = NULL */

typedef Address Tree;
typedef struct listTree
{
   Tree tree[ListTreeCap];
} ListTree;

/* LIST NODE */

void expandListNode(ListNode *l, int n);

void insertLastListNode(ListNode *l, Address val);

void createListNode(ListNode *l, int capacity);

void copyListNode(ListNode l1, ListNode *l2);

boolean isFullListNode(ListNode l);

boolean isEmptyListNode(ListNode l);

/* TREE */
/* KONSTRUKTOR */
Address newTreeNode(treeEl val, int childCnt);
/* Alokasi sebuah address p, bernilai tidak NULL jika berhasil */
/* Mengirimkan address hasil alokasi sebuah elemen bernilai val
   Jika alokasi berhasil, maka address tidak NULL, dan misalnya
   menghasilkan p, maka p↑.info=val, p↑.left=NULL, p↑.right=NULL
   Jika alokasi gagal, mengirimkan NULL */
void displayTree(Tree t);

void readTree(ListTree *t, char *file);

/* LIST TREE */

void buatListTree(ListTree *l);

Tree getMarkListTree();

int panjangListTree(ListTree l);

void displayListTree(ListTree t);

#endif