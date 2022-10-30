#include "input.h"
#include "stdio.h"

int askForNumber(int min, int max, char prompt[])
{
    int choice;
    int inputV;
    do
    {
        printf(prompt);
        inputV = scanf("%d", &choice);
        if (!inputV)
        {
            while (getchar() != '\n')
                ;
            printf("Masukkan angka!\n");
        }
        else if (choice < min || choice > max)
        {
            printf("Masukkan angka di range yang benar!\n");
        }
    } while (choice < min || choice > max || inputV != 1);
    return choice;
};

int askForNumberNMin(int max, char prompt[])
{
    int choice;
    int inputV;
    do
    {
        printf(prompt);
        inputV = scanf("%d", &choice);
        if (!inputV)
        {
            while (getchar() != '\n')
                ;
            printf("Masukkan angka!\n");
        }
        else if (choice > max)
        {
            printf("Masukkan angka di range yang benar!\n");
        }
    } while (choice > max || inputV != 1);
    return choice;
};
int askForNumberNMax(int min, char prompt[])
{
    int choice;
    int inputV;
    do
    {
        printf(prompt);
        inputV = scanf("%d", &choice);
        if (!inputV)
        {
            while (getchar() != '\n')
                ;
            printf("Masukkan angka!\n");
        }
        else if (choice < min)
        {
            printf("Masukkan angka di range yang benar!\n");
        }
    } while (choice < min || inputV != 1);
    return choice;
};
