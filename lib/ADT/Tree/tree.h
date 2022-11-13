#ifndef TREE_H
#define TREE_H

#include "../boolean.h"
#include "../Teks/teks.h"
#include "../ListStatMakanan/lstatmakanan.h"
#include "../ListDinTeks/ldinteks.h"
#include "../MBFile/mBFile.h"

/*  ADT TREE  */
/* ADT TREE adalah ADT berupa Tree yang memuat resep makanan,
 sehingga elemen yang disimpan pada setiap node adalah info makanan.
 Pada ADT ini juga dimanfaatkan ADT ListNode. */

/* ADT ListNode */
/* ADT ini adalah sebuah list dinamis dengan elemen berupa Tree.
ADT ini digunakan untuk menyimpan children dari sebuah node dan menyimpan daftar tree.*/

/* Selektor */
#define Child(p, i) (p)->children.child[i]
#define Children(p) (p)->children
#define MakananTree(p) (p)->makanan
#define NamaMakananTree(p) namaMakanan((p)->makanan)
#define AksiLokasiTree(p) aksiLokasi((p)->makanan)
#define IdTipeTree(p) idTipe((p)->makanan)
#define IdUnikTree(p) idUnik((p)->makanan)
#define AksiTree(p) aksi(aksiLokasi((p)->makanan))
#define ListNodeCap(l) (l).capacity
#define ListNodeELMT(l, i) (l).child[i]
#define ListNodeNEff(l) (l).nEff

typedef Makanan treeEl;
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
   treeEl makanan;
   ListNode children;
} TreeNode;

typedef Address Tree;

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
 * @brief mengecek apakah val merupakan child dari t
 *
 * @param val
 * @param t
 * @return boolean
 */
boolean isChildOf(treeEl val, Tree t);

/* LIST NODE */
/**
 * @brief membuat list node kosong dengan kapasitas capacity
 *
 * @param l
 * @param capacity
 */
void createListNode(ListNode *l, int capacity);

/**
 * @brief mengembalikan true jika index merupakan index efektif
 *
 * @param l
 * @param idx
 */
boolean isIdxEffListNode(ListNode l, int idx);

/**
 * @brief memperbesar memory listnode l sebesar n
 *
 * @param l
 * @param n
 */
void expandListNode(ListNode *l, int n);

/**
 * @brief mengirimkan ture jika list node l full
 *
 * @param l
 * @return boolean
 */
boolean isFullListNode(ListNode l);

/**
 * @brief memasukkan val sebagai elemen terakhir dalam list l
 *
 * @param l
 * @param val nilai yang akan dimasukkan ke dalam list l
 */
void insertLastListNode(ListNode *l, Address val);
/**
 * @brief memasukkan val sebagai elemen pertama pada List Node
 *
 * @param l
 * @param val
 */
void insertFirstListNode(ListNode *l, Address val);

/**
 * @brief memasukkan val sebagai elemen pada list
 *
 * @param l
 * @param val
 * @param idx
 */
void insertAtListNode(ListNode *l, Address val, IdxType idx);

/**
 * @brief memasukkan val ke dalam list l dengan terurut membesar dan mengembalikan indeks tempat val tersebut disimpan
 *
 * @param l
 * @param val
 */
int sortedInsertListNode(ListNode *l, Address val);

/**
 * @brief menyalin isi dari l1 ke l2
 *
 * @param l1
 * @param l2
 */
void copyListNode(ListNode l1, ListNode *l2);

/**
 * @brief mengirimkan false jika list node l kosong
 *
 * @param l
 * @return boolean
 */
boolean isEmptyListNode(ListNode l);

/* INPUT / OUTPUT */
/**
 * @brief mencetak semua tree pada list tree
 *
 * @param t
 */
void displayListNode(ListNode l);

/**
 * @brief membaca list tree. Proses : Baca n (jumlah resep), n baris selanjutnya adalah elemen tree dan
 * childnya (dibaca dengan readTree pada tree.h )
 *
 * @param t
 */
void readListNode(ListNode *t, char *file, LStatMakanan(listMakanan));

/* OPERASI LAIN-LAIN */
/**
 * @brief mengembalikan parent dengan children lt
 *
 * @param t
 * @param lt
 * @return Tree
 */
Tree getParent(ListNode t, LDinTeks lt);

/**
 * @brief mengecek apakah val telah dialokasi dalam tree yang ada di list l
 *
 * @param val
 * @param l
 * @return Address
 */
Address isAllocated(treeEl val, ListNode l);

/**
 * @brief mencari resep pada list resep dengan binary search dan
 * mengembalikan indeks resep tersebut
 *
 * @param l
 * @param val
 * @return int
 */
int searchResep(ListNode l, Makanan val, int lo, int hi);
#endif