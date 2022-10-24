#ifndef POHONBINER_H
#define POHONBINER_H

#include "boolean.h"
#include "../Teks/teks.h"

typedef struct treeNode
{
    treeEl resep;
    listNode children;
} TreeNode;