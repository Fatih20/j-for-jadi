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

    Waktu wSampaiReset;
    wSampaiReset = buatWaktu(0, 0, 0, 0);
    sampaiDalam(X) = wSampaiReset;
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

void deleteByIdTipe(FoodQueue *FQ, Teks idTipe, Makanan *deletedVal)
{
    int deletedIdx = idxMakanan(*FQ, idTipe);
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

int idxMakanan(FoodQueue FQ, Teks idTipe)
{
    int i = 0;
    boolean found = false;
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

void hapusBasi(FoodQueue *IQ, NotifState *nS)
{
    while ((!isEmptyFQ(*IQ)) && isWZero(basiDalam(headElFQ(*IQ))))
    {
        FoodQueueEl temp;
        dequeue(IQ, &temp);
        insertLastLDinNotifRaw(&forNS(*nS), 'e', namaMakanan(temp));
        insertLastLDinNotifRaw(&backNS(*nS), 'n', namaMakanan(temp));
    }
};

void majukanWDQ(FoodQueue *DQ, FoodQueue *IQ, Waktu w, NotifState *nS)
{
    if (isEmptyFQ(*DQ))
    {
        return;
    }
    Makanan currentM = headElFQ(*DQ);
    char nP = newPosisiMDelivery(currentM, w);
    while (nP != 'd' && !isEmptyFQ(*DQ))
    {
        Makanan movedFood;
        dequeue(DQ, &movedFood);
        majukanWMDelivery(&movedFood, w, nP);
        if (nP == 'i')
        {
            insertLastLDinNotifRaw(&forNS(*nS), 'd', namaMakanan(movedFood));
            insertLastLDinNotifRaw(&backNS(*nS), 's', namaMakanan(movedFood));

            enqueueInventory(IQ, movedFood);
        }
        else
        {
            insertLastLDinNotifRaw(&forNS(*nS), 'e', namaMakanan(movedFood));
            insertLastLDinNotifRaw(&backNS(*nS), 'n', namaMakanan(movedFood));
        }
        currentM = headElFQ(*DQ);
        nP = newPosisiMDelivery(currentM, w);
    }

    if (isEmptyFQ(*DQ))
    {
        return;
    }

    for (int i = headFQ(*DQ); i <= tailFQ(*DQ); i++)
    {
        majukanWMDelivery(&elmtFQ(*DQ, i), w, 'd');
    }
};

void majukanWIQ(FoodQueue *IQ, Waktu w, NotifState *nS)
{
    for (int i = headFQ(*IQ); i <= tailFQ(*IQ); i++)
    {
        majukanWMInventory(&elmtFQ(*IQ, i), w);
    }

    hapusBasi(IQ, nS);
};

void majukanWFQ(FoodQueue *DQ, FoodQueue *IQ, Waktu w, NotifState *nS)
{
    majukanWIQ(IQ, w, nS);
    majukanWDQ(DQ, IQ, w, nS);
};
