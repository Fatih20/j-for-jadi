#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

void CreateEmptyStack(Stack *S, int capacity)
{
    // KAMUS LOKAL
    // ALGORITMA
    Top(*S) = Nil;
    Capacity(*S) = capacity;
    Info(*S) = (infoStack *)malloc(capacity * sizeof(infoStack));
}

void dealocateStack(Stack *S)
{
    // KAMUS LOKAL
    // ALGORITMA
    free(Info(*S));
    Top(*S) = Nil;
    Capacity(*S) = 0;
}

void inverseStack(Stack SIn, Stack *SOut)
{
    // KAMUS LOKAL
    State state;
    // ALGORITMA

    CreateEmptyStack(SOut, Capacity(SIn));
    while (!IsEmptyStack(SIn))
    {
        Pop(&SIn, &state);
        Push(SOut, state);
    }
}

void copyStack(Stack SIn, Stack *SOut)
{
    // KAMUS LOKAL
    Stack STemp;
    State state;
    // ALGORITMA
    inverseStack(SIn, &STemp);
    CreateEmptyStack(SOut, Capacity(SIn));
    while (!IsEmptyStack(STemp))
    {
        Pop(&STemp, &state);
        Push(SOut, state);
    }
}

boolean IsEmptyStack(Stack S)
{
    // KAMUS LOKAL
    // ALGORITMA
    return (Top(S) == Nil);
}

boolean IsFullStack(Stack S)
{
    // KAMUS LOKAL
    // ALGORITMA
    return (Top(S) == Capacity(S) - 1);
}
void Push(Stack *S, infoStack X)
{
    // KAMUS LOKAL
    // ALGORITMA
    if (IsEmptyStack(*S))
    {
        Top(*S) = 0;
    }
    else
    {
        Top(*S) += 1;
    }
    InfoTop(*S) = X;
}

void Pop(Stack *S, infoStack *X)
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
    Info(*S) = realloc(Info(*S), (Capacity(*S) + num) * sizeof(infoStack));
    Capacity(*S) += num;
}

void shrinkStack(Stack *S, int num)
{
    Info(*S) = realloc(Info(*S), (Capacity(*S) - num) * sizeof(infoStack));
    Capacity(*S) -= num;
}