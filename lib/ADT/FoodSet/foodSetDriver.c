#include "foodSet.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    FoodSet fsa;
    buatFSKosong(&fsa);

    FoodSet fsb;
    buatFSKosong(&fsb);

    FoodSet fsc;
    buatFSKosong(&fsc);

    for (int i = 0; i < 20; i++)
    {
        ElmtFS(fsa, i) = true;
    }

    for (int i = 0; i < capacityFS; i++)
    {
        ElmtFS(fsb, i) = i % 2 == 0;
    }

    for (int i = 0; i < 20; i++)
    {
        ElmtFS(fsb, i) = i % 2 == 0;
    }

    printf("Food Set A\n");
    cetakFoodSet(fsa);

    printf("Food Set B\n");
    cetakFoodSet(fsb);

    printf("Food Set Union A dan B\n");
    cetakFoodSet(unionFoodSet(fsa, fsb));

    printf("Food Set Intersection A dan B\n");
    cetakFoodSet(intersectionFoodSet(fsa, fsb));

    printf("Food Set Subset A dan B\n");
    printf("%d\n", isSubsetfs(fsa, fsb));

    printf("Food Set Subset B dan C\n");
    printf("%d\n", isSubsetfs(fsc, fsb));

    /* code */
    return 0;
}
