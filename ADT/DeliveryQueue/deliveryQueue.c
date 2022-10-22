#include "deliveryQueue.h"

DeliveryQueueEl headElDQ(DeliveryQueue DQ)
{
    return elmtLDM(DQ.content, DQ.headDQ);
};

DeliveryQueueEl tailElDQ(DeliveryQueue DQ)
{
    return elmtLDM(DQ.content, DQ.tailDQ);
};

DeliveryQueueEl elmtDQ(DeliveryQueue DQ, int i)
{
    return elmtLDM(DQ.content, i);
};

boolean isEmptyDQ(DeliveryQueue DQ)
{
    return isEmptyLDinMakanan(DQ.content);
};

int nElmt(DeliveryQueue DQ)
{
    return panjangLDinMakanan(DQ.content);
};

void buatDQKosong(DeliveryQueue *DQ, int max)
{
    buatLDinMakanan(&(DQ->content), max);
    headDQ(*DQ) = Nil;
    tailDQ(*DQ) = Nil;
};

void deAlokasi(DeliveryQueue *DQ)
{

    dealokasiLDinMakanan(&(DQ->content));
    headDQ(*DQ) = Nil;
    tailDQ(*DQ) = Nil;
};

void enqueue(DeliveryQueue *DQ, DeliveryQueueEl X)
{

    // Jika kosong maka lakukan ini
    if (isEmptyDQ(*DQ))
    {
        insertFirstLDinMakanan(&(DQ->content), X);
    }
    else
    {
        int i = lastIdxLDinMakanan(DQ->content);
        boolean lessOrSameFound = false;

        // Jika tidak kosong maka lakukan ini
        while (!lessOrSameFound && i >= 0)
        {
            lessOrSameFound = !sampaiDuluan(X, elmtDQ(*DQ, i));
            if (!lessOrSameFound)
            {
                i--;
            }
            else
            {
                // cetakMakanan(X);
                // printf("%d\n", i);
                insertAtLDinMakanan(&(DQ->content), X, i + 1);
            }
        }

        if (!lessOrSameFound)
        {
            insertAtLDinMakanan(&(DQ->content), X, i + 1);
        }
    }

    if (headDQ(*DQ) == Nil)
    {
        headDQ(*DQ) = 0;
        tailDQ(*DQ) = 0;
    }
    else
    {
        tailDQ(*DQ) += 1;
    }
};
void dequeue(DeliveryQueue *DQ, DeliveryQueueEl *X)
{
    removeFirstLDinMakanan(&(DQ->content), X);
};

void cetakDeliveryQueue(DeliveryQueue DQ)
{
    printLDinMakanan(DQ.content);
};
