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
