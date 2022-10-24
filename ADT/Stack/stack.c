#include <stdio.h>
#include "stack.h"

void CreateEmptyStack(Stack *S, int capacity)
{
    // KAMUS LOKAL
    // ALGORITMA
    Top(*S) = Nil;
}

boolean IsEmpty(Stack S)
{
    // KAMUS LOKAL
    // ALGORITMA
    return (Top(S) == Nil);
}

boolean IsFull(Stack S)
{
    // KAMUS LOKAL
    // ALGORITMA
    return (Top(S) == Capacity(S) - 1);
}
void Push(Stack *S, infotype X)
{
    // KAMUS LOKAL
    // ALGORITMA
    if (IsEmpty(*S))
    {
        Top(*S) = 0;
    }
    else
    {
        Top(*S) += 1;
    }
    InfoTop(*S) = X;
}

void Pop(Stack *S, infotype *X)
{
    // KAMUS LOKAL
    // ALGORITMA
    *X = InfoTop(*S);
    if (Top(*S) == 0)
    {
        Top(*S) = Nil;
    }
    else
    {
        Top(*S)--;
    }
}

void expandStack(Stack *S, int num)
{
    *S->T = realloc(*S->T, (Capacity(*S) + num) * sizeof(infotype));
    Capacity(*S) += num;
}

void shrinkStack(Stack *S, int num)
{
    *S->T = realloc(*S->T, (Capacity(*S) - num) * sizeof(infotype));
    Capacity(*S) -= num;
}