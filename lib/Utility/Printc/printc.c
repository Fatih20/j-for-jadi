#include <stdio.h>
#include "printc.h"

void printRed(char c)
{
    printf("%s%c", RED, c);
    printf("%s", NORMAL);
}

void printGreen(char c)
{
    printf("%s%c", GREEN, c);
    printf("%s", NORMAL);
};

void printYellow(char c)
{
    printf("%s%c", YELLOW, c);
    printf("%s", NORMAL);
};

void printBlue(char c)
{
    printf("%s%c", BLUE, c);
    printf("%s", NORMAL);
};

void printMagenta(char c)
{
    printf("%s%c", MAGENTA, c);
    printf("%s", NORMAL);
};

void printCyan(char c)
{
    printf("%s%c", CYAN, c);
    printf("%s", NORMAL);
};

void printPurple(char c)
{
    printf("%s%c", PURPLE, c);
    printf("%s", NORMAL);
};

void printSRed(char *c)
{
    printf("%s%s", RED, c);
    printf("%s", NORMAL);
};

void printSGreen(char *c)
{
    printf("%s%s", GREEN, c);
    printf("%s", NORMAL);
};

void printSYellow(char *c)
{
    printf("%s%s", YELLOW, c);
    printf("%s", NORMAL);
};

void printSBlue(char *c)
{
    printf("%s%s", BLUE, c);
    printf("%s", NORMAL);
};

void printSMagenta(char *c)
{
    printf("%s%s", MAGENTA, c);
    printf("%s", NORMAL);
};

void printSCyan(char *c)
{
    printf("%s%s", CYAN, c);
    printf("%s", NORMAL);
};

void printSPurple(char *c)
{
    printf("%s%s", PURPLE, c);
    printf("%s", NORMAL);
};