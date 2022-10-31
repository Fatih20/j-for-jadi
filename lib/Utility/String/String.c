#include "String.h"
#include "stdio.h"
boolean stringSame(char a[], char b[])
{
    int i = 0;
    boolean sameSoFar = true;
    while (a[i] != '\0' && b[i] != '\0' && sameSoFar)
    {
        sameSoFar = a[i] == b[i];
        i += sameSoFar;
    }
    return sameSoFar;
};

int stringLen(char a[])
{
    int i = 0;
    for (char kar = *a; kar != '\0'; kar = *++a)
    {
        i += 1;
    }
    return i;
};

void stringConcat(char a[], char b[], char c[])
{
    int i = 0;
    for (char karA = *a; karA != '\0'; karA = *++a)
    {
        c[i] = karA;
        i++;
    }

    for (char karB = *b; karB != '\0'; karB = *++b)
    {
        c[i] = karB;
        i++;
    }
    c[i] = '\0';
}