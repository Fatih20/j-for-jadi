#include "input.h"
#include "../../ADT/MBInput/mBInput.h"
#include "stdio.h"

int askForNumber(int min, int max, char prompt[])
{
    int choice;
    Teks choiceR;
    int inputV;
    do
    {
        printf("%s", prompt);
        startMBInput();
        inputV = false;
        if (panjangLDinTeks(currentRowI) == 1)
        {
            choiceR = elmtLDT(currentRowI, 0);
            if (isTeksInt(choiceR))
            {
                choice = teksToInt(choiceR);
                inputV = true;
            }
        }
        if (!inputV)
        {
            printf("Masukkan angka!\n");
        }
        else if (choice < min || choice > max)
        {
            printf("Masukkan angka di range yang benar!\n");
        }
    } while (choice < min || choice > max || !inputV);
    return choice;
};

int askForNumberNMin(int max, char prompt[])
{
    int choice;
    Teks choiceR;
    int inputV;
    do
    {
        printf("%s", prompt);
        startMBInput();
        inputV = false;
        if (panjangLDinTeks(currentRowI) == 1)
        {
            choiceR = elmtLDT(currentRowI, 0);
            if (isTeksInt(choiceR))
            {
                choice = teksToInt(choiceR);
                inputV = true;
            }
        }
        if (!inputV)
        {
            printf("Masukkan angka!\n");
        }
        else if (choice > max)
        {
            printf("Masukkan angka di range yang benar!\n");
        }
    } while (choice > max || !inputV);
    return choice;
};
int askForNumberNMax(int min, char prompt[])
{
    int choice;
    Teks choiceR;
    int inputV;
    do
    {
        printf("%s", prompt);
        startMBInput();
        inputV = false;
        if (panjangLDinTeks(currentRowI) == 1)
        {
            choiceR = elmtLDT(currentRowI, 0);
            if (isTeksInt(choiceR))
            {
                choice = teksToInt(choiceR);
                inputV = true;
            }
        }
        if (!inputV)
        {
            printf("Masukkan angka!\n");
        }
        else if (choice < min)
        {
            printf("Masukkan angka di range yang benar!\n");
        }
    } while (choice < min || !inputV);
    return choice;
};
