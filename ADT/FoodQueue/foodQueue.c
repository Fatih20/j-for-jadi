#include "foodQueue.h"

FoodQueueEl headElFQ(FoodQueue FQ)
{
    return elmtLDM(FQ.content, FQ.headFQ);
};

FoodQueueEl tailElFQ(FoodQueue FQ)
{
    return elmtLDM(FQ.content, FQ.tailFQ);
};

FoodQueueEl elmtFQ(FoodQueue FQ, int i)
{
    return elmtLDM(FQ.content, i);
};

boolean isEmptyFQ(FoodQueue FQ)
{
    return isEmptyLDinMakanan(FQ.content);
};

int nElmt(FoodQueue FQ)
{
    return panjangLDinMakanan(FQ.content);
};

void buatFQKosong(FoodQueue *FQ, int max)
{
    buatLDinMakanan(&(FQ->content), max);
    headFQ(*FQ) = Nil;
    tailFQ(*FQ) = Nil;
};

void deAlokasi(FoodQueue *FQ)
{

    dealokasiLDinMakanan(&(FQ->content));
    headFQ(*FQ) = Nil;
    tailFQ(*FQ) = Nil;
};

void enqueueDelivery(FoodQueue *FQ, FoodQueueEl X)
{

    // Jika kosong maka lakukan ini
    if (isEmptyFQ(*FQ))
    {
        insertFirstLDinMakanan(&(FQ->content), X);
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
                insertAtLDinMakanan(&(FQ->content), X, i + 1);
            }
        }

        if (!lessOrSameFound)
        {
            insertAtLDinMakanan(&(FQ->content), X, i + 1);
        }
    }

    if (headFQ(*FQ) == Nil)
    {
        headFQ(*FQ) = 0;
        tailFQ(*FQ) = 0;
    }
    else
    {
        tailFQ(*FQ) += 1;
    }
};

void enqueueInventory(FoodQueue *FQ, FoodQueueEl X)
{

    // Jika kosong maka lakukan ini
    if (isEmptyFQ(*FQ))
    {
        insertFirstLDinMakanan(&(FQ->content), X);
    }
    else
    {
        int i = lastIdxLDinMakanan(FQ->content);
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
                insertAtLDinMakanan(&(FQ->content), X, i + 1);
            }
        }

        if (!lessOrSameFound)
        {
            insertAtLDinMakanan(&(FQ->content), X, i + 1);
        }
    }

    if (headFQ(*FQ) == Nil)
    {
        headFQ(*FQ) = 0;
        tailFQ(*FQ) = 0;
    }
    else
    {
        tailFQ(*FQ) += 1;
    }
};
void dequeue(FoodQueue *FQ, FoodQueueEl *X)
{
    removeFirstLDinMakanan(&(FQ->content), X);
};

void cetakFoodQueue(FoodQueue FQ)
{
    printLDinMakanan(FQ.content);
};

void copyFoodQueue(FoodQueue FQ1, FoodQueue *FQ2)
{
    headFQ(*FQ2) = headFQ(FQ1);
    tailFQ(*FQ2) = tailFQ(FQ1);
    copyLDinMakanan(FQ1.content, &(FQ2->content));
};

void deleteByID(FoodQueue *FQ, Teks idTipe){

};
