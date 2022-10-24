#ifndef stack_H
#define stack_H

#include "../boolean.h"
#include "../State/state.h"

#define Nil -1

typedef State infoStack;
typedef int address; /* indeks tabel */

/**
 * @brief Stack of State
 * @param T: tabel penyimpan elemen
 * @param TOP: alamat elemen puncak
 * @param capacity: kapasitas Stack
 */
typedef struct
{
    infoStack *T;
    address TOP;
    int capacity;
} Stack;

#define Top(S) (S).TOP
#define InfoTop(S) (S).T[(S).TOP]
#define Info(S) (S).T
#define Capacity(S) (S).capacity

/**
 * @brief Konstruktor: Create Stack Kosong
 * @param S: Stack of State
 * @param capacity: Kapasitas Maksimum dari state
 * @return Terbentuk sebuah stack kosong(TOP bernilai Nil) dengan kapasitas capacity
 */
void CreateEmptyStack(Stack *S, int capacity);

/**
 * @brief Mengirim true jika Stack kosong
 * @param S: Stack of State
 * @return boolean
 */
boolean IsEmptyStack(Stack S);

/**
 * @brief Mengirim true jika tabel penampung nilai elemen stack penuh
 * @param S: Stack of State
 * @return boolean
 */
boolean IsFullStack(Stack S);

/**
 * @brief Menambahkan X sebagai elemen Stack S
 * @param S: Stack of State
 * @param X: State
 * @return X menjadi TOP yang baru,TOP bertambah 1
 */
void Push(Stack *S, infoStack X);

/**
 * @brief Menghapus X dari Stack S
 * @param S: Stack of State
 * @param X: State
 * @return X adalah nilai elemen TOP yang lama, TOP berkurang 1
 */
void Pop(Stack *S, infoStack *X);

/**
 * @brief Menambahkan capacity S sebanyak num
 * @param S: Stack of State
 * @param num: Banyak capacity tambahan
 * @return Ukuran Stack bertambah sebanyak num
 */
void expandStack(Stack *S, int num);

/**
 * @brief Mengurangi capacity sebanyak num
 * @param S: Stack of State
 * @param num: Banyak capacity yang dikurangi
 */
void shrinkStack(Stack *S, int num);

#endif