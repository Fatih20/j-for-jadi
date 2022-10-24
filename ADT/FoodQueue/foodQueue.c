#include "foodQueue.h"

FoodQueueEl headElFQ(FoodQueue FQ)
{
    return elmtFQ(FQ, headFQ(FQ));
};

FoodQueueEl tailElFQ(FoodQueue FQ)
{
    return elmtFQ(FQ, tailFQ(FQ));
};

FoodQueueEl elmtFQ(FoodQueue FQ, int i)
{
    return elmtLDM(content(FQ), i);
};

boolean isEmptyFQ(FoodQueue FQ)
{
    return headFQ(FQ) == Nil && tailFQ(FQ) == Nil;
};

int nElmt(FoodQueue FQ)
{
    if (isEmptyFQ(FQ))
    {
        return 0;
    }
    else
    {
        return tailFQ(FQ) - headFQ(FQ) + 1;
    }
};

void buatFQKosong(FoodQueue *FQ, int max)
{
    buatLDinMakanan(&(content(*FQ)), max);
    headFQ(*FQ) = Nil;
    tailFQ(*FQ) = Nil;
};

void deAlokasi(FoodQueue *FQ)
{

    dealokasiLDinMakanan(&(content(*FQ)));
    headFQ(*FQ) = Nil;
    tailFQ(*FQ) = Nil;
};

void enqueueDelivery(FoodQueue *FQ, FoodQueueEl X)
{

    // Jika kosong maka langsung insert first dan definisikan head serta tail
    boolean added = false;
    if (isEmptyFQ(*FQ))
    {
        insertFirstLDinMakanan(&(content(*FQ)), X);
        headFQ(*FQ) = 0;
        tailFQ(*FQ) = 0;
        added = true;
    }
    else
    {
        int i = lastIdxLDinMakanan(FQ->content);
        boolean lessOrSameFound = false;

        // Jika tidak kosong maka lakukan ini
        while (!lessOrSameFound && i >= 0)
        {
            lessOrSameFound = !sampaiDuluan(X, elmtFQ(*FQ, i));
            if (!lessOrSameFound)
            {
                i--;
            }
            else
            {
                // cetakMakanan(X);
                // printf("%d\n", i);
                insertAtLDinMakanan(&(content(*FQ)), X, i + 1);
                added = true;
            }
        }

        if (!lessOrSameFound)
        {
            insertAtLDinMakanan(&(content(*FQ)), X, i + 1);
            added = true;
        }

        tailFQ(*FQ) += added;
    }
};

void enqueueInventory(FoodQueue *FQ, FoodQueueEl X)
{

    // Jika kosong maka lakukan ini
    boolean added = false;
    if (isEmptyFQ(*FQ))
    {
        insertFirstLDinMakanan(&(content(*FQ)), X);
        headFQ(*FQ) = 0;
        tailFQ(*FQ) = 0;
        added = true;
    }
    else
    {
        int i = lastIdxLDinMakanan(content(*FQ));
        boolean lessOrSameFound = false;

        // Jika tidak kosong maka lakukan ini
        while (!lessOrSameFound && i >= 0)
        {
            lessOrSameFound = !basiDuluan(X, elmtFQ(*FQ, i));
            if (!lessOrSameFound)
            {
                i--;
            }
            else
            {
                // cetakMakanan(X);
                // printf("%d\n", i);
                insertAtLDinMakanan(&(content(*FQ)), X, i + 1);
                added = true;
            }
        }

        if (!lessOrSameFound)
        {
            insertAtLDinMakanan(&(content(*FQ)), X, i + 1);
            added = true;
        }
        tailFQ(*FQ) += added;
    }
};
void dequeue(FoodQueue *FQ, FoodQueueEl *X)
{
    if (isEmptyFQ(*FQ))
    {
        return;
    }
    if (nElmt(*FQ) == 1)
    {
        headFQ(*FQ) = Nil;
        tailFQ(*FQ) = Nil;
    }
    else
    {
        tailFQ(*FQ)--;
    }
    removeFirstLDinMakanan(&(content(*FQ)), X);
};

void cetakFoodQueue(FoodQueue FQ)
{
    printLDinMakanan(content(FQ));
};

void copyFoodQueue(FoodQueue FQ1, FoodQueue *FQ2)
{
    headFQ(*FQ2) = headFQ(FQ1);
    tailFQ(*FQ2) = tailFQ(FQ1);
    copyLDinMakanan(FQ1.content, &(content(*FQ2)));
};

void deleteByIdTipe(FoodQueue *FQ, char idTipeS[], Makanan *deletedVal)
{
    int deletedIdx = idxMakanan(*FQ, idTipeS);
    if (deletedIdx != IDX_UNDEF)
    {
        if (nElmt(*FQ) == 1)
        {
            headFQ(*FQ) = Nil;
            tailFQ(*FQ) = Nil;
        }
        else
        {
            tailFQ(*FQ)--;
        }
        removeAtLDinMakanan(&content(*FQ), deletedVal, deletedIdx);
    }
};

int idxMakanan(FoodQueue FQ, char idTipeS[])
{
    int i = 0;
    // int lastIdx = tailFQ(FQ);
    boolean found = false;
    Teks idTipe;
    buatTeks(idTipeS, &idTipe);
    while (!found && i <= tailFQ(FQ))
    {
        found = teksSama(idTipe(elmtFQ((FQ), i)), idTipe);
        if (!found)
        {
            i++;
        }
    }

    return found ? i : IDX_UNDEF;
};

void hapusBasi(FoodQueue *FQ)
{
    while ((!isEmptyFQ(*FQ)) && basiDalam(headElFQ(*FQ)) == 0)
    {
        FoodQueueEl temp;
        dequeue(FQ, &temp);
    }
};
void hapusSampai(FoodQueue *DQ, FoodQueue *IQ)
{
    while ((!isEmptyFQ(*DQ)) && sampaiDalam((headElFQ(*DQ))) == 0)
    {
        FoodQueueEl temp;
        dequeue(DQ, &temp);
        enqueueInventory(IQ, temp);
    }
};
void majukanWSampai(FoodQueue *DQ, FoodQueue *IQ)
{
    // int lastIdx = tailFQ(*DQ);
    for (int i = headFQ(*DQ); i <= tailFQ(*DQ); i++)
    {
        // sampaiDalam(elmtFQ((*DQ), i))--;
        elmtLDM((*DQ).content, i).waktuSampai--;
    }
    hapusSampai(DQ, IQ);
};
void majukanWBasi(FoodQueue *IQ)
{
    // int lastIdx = tailFQ(*IQ);
    // int lastIdx = lastIdxLDinMakanan((*IQ).content);
    for (int i = 0; i <= tailFQ(*IQ); i++)
    {
        elmtLDM((*IQ).content, i).waktuBasi--;
    }

    hapusBasi(IQ);
};

void majukanWFQ(FoodQueue *DQ, FoodQueue *IQ)
{
    majukanWBasi(IQ);
    majukanWSampai(DQ, IQ);
};
