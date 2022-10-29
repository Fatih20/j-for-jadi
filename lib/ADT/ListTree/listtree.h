#ifndef LISTTREE_H
#define LISTTREE_H

#include "../Tree/tree.h"
#include "../ListDinTeks/ldinteks.h"

#define ListTreeCap 100
#define ListTreeELMT(l, i) (l).tree[i]

/**
 * @brief List Tree adalah sebuah list statik yang memuat tree
 *
 */
typedef struct listTree
{
    Tree tree[ListTreeCap];
} ListTree;

/* LIST TREE */
/* KONSTRUKTOR */
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

/* INPUT / OUTPUT */
/**
 * @brief mencetak semua tree pada list tree
 *
 * @param t
 */
void displayListTree(ListTree l);

/**
 * @brief membaca list tree. Proses : Baca n (jumlah resep), n baris selanjutnya adalah elemen tree dan
 * childnya (dibaca dengan readTree pada tree.h )
 *
 * @param t
 */
void readListTree(ListTree *t, char *file, LStatMakanan(listMakanan));

/* OPERASI LAIN-LAIN */
/**
 * @brief mengembalikan parent dengan children lt
 *
 * @param t
 * @param lt
 * @return Tree
 */
Tree getParent(ListTree t, LDinTeks lt);

/**
 * @brief mengecek apakah val telah dialokasi dalam tree yang ada di list l
 *
 * @param val
 * @param l
 * @return Address
 */
Address isAllocated(treeEl val, ListTree l);

/**
 * @brief memasukkan t sebagai elemen terakhir pada l
 *
 * @param t
 * @param l
 */
void insertLastListTree(Tree t, ListTree *l);

#endif