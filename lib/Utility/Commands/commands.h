#ifndef COMMANDS_H
#define COMMANDS_H
#include "../../ADT/Tree/tree.h"
#include <stdio.h>
#include "../../ADT/State/state.h"

void olahMakanan(Teks command, FoodQueue *inventory, ListNode *daftarResep, LStatMakanan *daftarMakanan, State *currState);

void displayCookbook(ListNode *daftarResep);

void displayCatalog(LStatMakanan *daftarMakanan);

#endif