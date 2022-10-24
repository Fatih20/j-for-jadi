#include "foodQueue.h"

FoodQueueEl headElFQ(FoodQueue FQ)
{
    return elmtFQ(FQ, headFQ(FQ));
};

FoodQueueEl tailElFQ(FoodQueue FQ)
{
    return elmtFQ(FQ, tailFQ(FQ));
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

void enqueueDelivery(FoodQueue *DQ, FoodQueueEl X)
{

    // Jika kosong maka langsung insert first dan definisikan head serta tail
    boolean added = false;
    if (isEmptyFQ(*DQ))
    {
        insertFirstLDinMakanan(&(content(*DQ)), X);
        headFQ(*DQ) = 0;
        tailFQ(*DQ) = 0;
        added = true;
    }
    else
    {
        int i = lastIdxLDinMakanan((content(*DQ)));
        boolean lessOrSameFound = false;

        // Jika tidak kosong maka masukkan manual
        while (!lessOrSameFound && i >= 0)
        {
            lessOrSameFound = !sampaiDuluan(X, elmtFQ(*DQ, i));
            if (!lessOrSameFound)
            {
                i--;
            }
            else
            {
                insertAtLDinMakanan(&(content(*DQ)), X, i + 1);
                added = true;
            }
        }

        if (!lessOrSameFound)
        {
            insertAtLDinMakanan(&(content(*DQ)), X, i + 1);
            added = true;
        }

        tailFQ(*DQ) += added;
    }
};

void enqueueInventory(FoodQueue *IQ, FoodQueueEl X)
{

    // Jika kosong maka lakukan ini
    boolean added = false;
    if (isEmptyFQ(*IQ))
    {
        insertFirstLDinMakanan(&(content(*IQ)), X);
        headFQ(*IQ) = 0;
        tailFQ(*IQ) = 0;
        added = true;
    }
    else
    {
        int i = lastIdxLDinMakanan(content(*IQ));
        boolean lessOrSameFound = false;

        // Jika tidak kosong maka masukkan manual
        while (!lessOrSameFound && i >= 0)
        {
            lessOrSameFound = !basiDuluan(X, elmtFQ(*IQ, i));
            if (!lessOrSameFound)
            {
                i--;
            }
            else
            {
                insertAtLDinMakanan(&(content(*IQ)), X, i + 1);
                added = true;
            }
        }

        if (!lessOrSameFound)
        {
            insertAtLDinMakanan(&(content(*IQ)), X, i + 1);
            added = true;
        }
        tailFQ(*IQ) += added;
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

void hapusBasi(FoodQueue *IQ)
{
    while ((!isEmptyFQ(*IQ)) && basiDalam(headElFQ(*IQ)) == 0)
    {
        FoodQueueEl temp;
        dequeue(IQ, &temp);
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
    for (int i = headFQ(*DQ); i <= tailFQ(*DQ); i++)
    {
        sampaiDalam(elmtFQ((*DQ), i))--;
    }
    hapusSampai(DQ, IQ);
};
void majukanWBasi(FoodQueue *IQ)
{
    for (int i = 0; i <= tailFQ(*IQ); i++)
    {
        basiDalam(elmtFQ((*IQ), i))--;
    }

    hapusBasi(IQ);
};

void majukanWFQ(FoodQueue *DQ, FoodQueue *IQ)
{
    majukanWBasi(IQ);
    majukanWSampai(DQ, IQ);
};
