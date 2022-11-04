#ifndef PRINTC_H
#define PRINTC_H

#define NORMAL "\x1B[0m"
#define RED "\x1B[31m"
#define GREEN "\x1B[32m"
#define YELLOW "\x1B[33m"
#define BLUE "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN "\x1B[36m"
#define PURPLE "\033[0;35m"

void printRed(char c);
void printGreen(char c);
void printYellow(char c);
void printBlue(char c);
void printMagenta(char c);
void printCyan(char c);
void printPurple(char c);

void printSRed(char *c);
void printSGreen(char *c);
void printSYellow(char *c);
void printSBlue(char *c);
void printSMagenta(char *c);
void printSCyan(char *c);
void printSPurple(char *c);

#endif