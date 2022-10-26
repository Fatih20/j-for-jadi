#include "setID.h"
#include "../Teks/teks.h"
#include <stdio.h>

setIDEl getMarkSetID()
{
    setIDEl MARK;
    char blank[] = "#";
    buatTeks(blank, &MARK);
    return MARK;
}

void createSet(SetID *S)
{
    int i;

    for (i = 0; i < capacitySetID; i++)
    {
        elmtSetID(*S, i) = getMarkSetID();
    }
}

boolean isEmptySet(SetID S)
{
    return (lengthSet(S) == 0);
}

int lengthSet(SetID S)
{
    int i;

    i = 0;
    while (teksToInt(elmtSetID(S, i)) != teksToInt(getMarkSetID()))
    {
        i = i + 1;
    }
    return i;
}

void addElmtSet(SetID *S, setIDEl val)
{
    int i;

    i = 0;
    while (teksToInt(elmtSetID(*S, i)) != teksToInt(getMarkSetID()))
    {
        i = i + 1;
    }
    elmtSetID(*S, i) = val;
}

/* remove belum selesai */
void removeElmtSet(SetID *S, setIDEl val)
{
    int idx, i;
    boolean foundIdx;

    if (isElmtInSet(*S, val))
    {
        idx = 0;
        foundIdx = false;
        while (!foundIdx)
        {
            if (teksToInt(elmtSetID(*S, idx)) == teksToInt(val))
            {
                foundIdx = true;
            }
            idx = idx + 1;
        }

        idx = idx - 1;
        for (i = idx; i < (length(S) - 2); i++)
        {
            elmtSetID(*S, idx) = elmtSetID(*S, (idx + 1));
        }
    }
}

boolean isElmtInSet(SetID S, setIDEl val)
{
    int i;
    boolean found;

    i = 0;
    found = false;
    while ((i < lengthSet(S)) && (!found))
    {
        if (teksToInt(elmtSetID(S, i)) == teksToInt(val))
        {
            found = true;
        }
        i = i + 1;
    }
    return found;
}

boolean isSetEqual(SetID S1, SetID S2)
{
    boolean equal, found;
    int i, j;

    if (lengthSet(S1) != lengthSet(S2))
    {
        equal = false;
    }
    else
    {
        i = 0;
        equal = true;
        while (equal && (i < lengthSet(S1)))
        {
            j = 0;
            found = false;
            while (!found && (j < lengthSet(S2)))
            {
                if (teksToInt(elmtSetID(S1, i)) == teksToInt(elmtSetID(S2, j)))
                {
                    found = true;
                }
                else
                {
                    j = j + 1;
                }
            }
            if (!found)
            {
                equal = false;
            }
            i = i + 1;
        }
    }
    return equal;
}

SetID setUnion(SetID S1, SetID S2)
{
    SetID S3;
    int i, j;

    createSet(&S3);
    if ((lengthSet(S1) + lengthSet(S2)) <= capacitySetID)
    {

        i = 0;
        while (i < lengthSet(S1))
        {
            addElmtSet(&S3, elmtSetID(S1, i));
            i = i + 1;
        }

        j = 0;
        while (j < lengthSet(S2))
        {
            if (!isElmtInSet(S3, elmtSetID(S2, j)))
            {
                addElmtSet(&S3, elmtSetID(S2, j));
            }
            j = j + 1;
        }
    }
    return S3;
}

SetID setIntersection(SetID S1, SetID S2)
{
    SetID S3;
    int i;

    for (i = 0; i < lengthSet(S1); i++)
    {
        if (isElmtInSet(S2, elmtSetID(S1, i)))
        {
            addElmtSet(&S3, elmtSetID(S1, i));
        }
    }
    return S3;
}

SetID setDifference(SetID S1, SetID S2)
{
    SetID S3;
    int i;

    for (i = 0; i < lengthSet(S1); i++)
    {
        if (!isElmtInSet(S2, elmtSetID(S1, i)))
        {
            addElmtSet(&S3, elmtSetID(S1, i));
        }
    }
    return S3;
}

SetID copySet(SetID S)
{
    SetID copy;
    int i;

    for (i = 0; i < lengthSet(S); i++)
    {
        addElmtSet(&copy, elmtSetID(S, i));
    }
    return copy;
}

boolean isSubset(SetID S1, SetID S2)
{
    boolean subset;
    int i;

    i = 0;
    subset = true;
    while (i < lengthSet(S1) && subset)
    {
        if (!isElmtInSet(S2, elmtSetID(S1, i)))
        {
            subset = false;
        }
        i = i + 1;
    }
    return subset;
}

void printSetID(SetID S)
{
    int i;

    printf('[');
    if (!isEmptySet(S))
    {
        i = 0;
        for (i = 0; i < (lengthSet(S) - 1); i++)
        {
            cetakTeks(elmtSetID(S, i));
            printf(",");
        }
        cetakTeks(elmtSetID(S, (lengthSet(S) - 1)));
    }
    printf(']');
}