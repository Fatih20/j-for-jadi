#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../Teks/teks.h"
#include "../ListStatMakanan/lstatmakanan.h"
#include "../ListDinTeks/ldinteks.h"

/*  ADT TREE  */
/* ADT TREE adalah ADT berupa Tree yang memuat resep makanan,
 sehingga elemen yang disimpan pada setiap node adalah info makanan.
 Pada ADT ini juga dimanfaatkan ADT ListNode dan ADT ListTree. */

/* ADT ListNode */
/* ADT ini adalah sebuah list dinamis dengan elemen berupa Tree.
ADT ini digunakan untuk menyimpan children dari sebuah node.*/

/* ADT ListTree */
/* ADT ini adalah sebuah list statis dengan elemen berupa Tree.
ADT ini digunakan untuk menyimapan semua resep dalam file config.
Kapasitas maksimumnya = 100 */

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

/**
 * @brief List Node adalah list untuk menyimpan children dari sebuah tree
 *
 * @param child adalah array dinamis yang berisi alamat dari child tree
 * @param capacity adalah kapasitas array dinamis (default = 100)
 * @param nEff adalah jumlah child
 */
typedef struct listNode
{
   Address *child;
   int capacity;
   int nEff;
} ListNode;

/**
 * @brief Tree Node adalah semua node yang berada dalam sebuah tree
 *
 * @param makanan adalah info nama makanan pada node
 * @param children adalah ListNode yang berisi child dari node
 */
typedef struct treeNode
{
   treeEl aksi;
   treeEl makanan;
   ListNode children;
} TreeNode;

typedef Address Tree;

/**
 * @brief List Tree adalah sebuah list statik yang memuat tree
 *
 */
typedef struct listTree
{
   Tree tree[ListTreeCap];
} ListTree;

typedef Tree *ListOfTree;
/**
 * @brief memasukkan val sebagai elemen terakhir dalam list l
 *
 * @param l
 * @param val nilai yang akan dimasukkan ke dalam list l
 */
void insertLastListNode(ListNode *l, Address val);

/**
 * @brief membuat list node kosong dengan kapasitas capacity
 *
 * @param l
 * @param capacity
 */
void createListNode(ListNode *l, int capacity);

/**
 * @brief menyalin isi dari l1 ke l2
 *
 * @param l1
 * @param l2
 */
void copyListNode(ListNode l1, ListNode *l2);

/**
 * @brief mengirimkan ture jika list node l full
 *
 * @param l
 * @return boolean
 */
boolean isFullListNode(ListNode l);
/**
 * @brief mengirimkan false jika list node l kosong
 *
 * @param l
 * @return boolean
 */
boolean isEmptyListNode(ListNode l);

/**
 * @brief memperbesar memory listnode l sebesar n
 *
 * @param l
 * @param n
 */
void expandListNode(ListNode *l, int n);

/* TREE */
/* KONSTRUKTOR */
/**
 * @brief membuat tree node baru dengan jumlah child sebesar childCnt
 *
 * @param val info pada tree node
 * @param childCnt jumlah child
 * @return Address
 */
Address newTreeNode(treeEl val, int childCnt);

/**
 * @brief mencetak Tree
 *
 * @param t
 */
void displayTree(Tree t);

/**
 * @brief membaca tree dari file
 *
 * @param t
 * @param file
 * @param listMakanan
 */
void readTree(ListTree *t, char *file, LStatMakanan listMakanan);

/* LIST TREE */
/**
 * @brief membuat list statik kosong l dengan kapasitas 100
 *
 * @param l
 */
void buatListTree(ListTree *l);

/**
 * @brief men-generate mark untuk List Tree
 *
 * @return Tree
 */
Tree getMarkListTree();

/**
 * @brief mengembalikan panjang dari List Tree
 *
 * @param l
 * @return int
 */
int panjangListTree(ListTree l);

/**
 * @brief mencetak semua tree pada list tree
 *
 * @param t
 */
void displayListTree(ListTree t);

/**
 * @brief mengembalikan parent dengan children lt
 *
 * @param t
 * @param lt
 * @return Tree
 */
Tree getParent(ListTree t, LDinTeks lt);

/**
 * @brief mengecek apakah val merupakan child dari t
 *
 * @param val
 * @param t
 * @return boolean
 */
boolean isChildOf(Teks val, Tree t);

#endif