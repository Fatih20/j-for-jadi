#include "makanan.h"
#include "../boolean.h"
#include <stdio.h>

int main(int argc, char const *argv[])
{
    Makanan m1;
    buatMakanan(&m1, "bruh", 100, 100, "100", "100");
    cetakMakanan(m1);

    Makanan m2;
    buatMakanan(&m2, "bruh", 101, 100, "10000000", "101");
    cetakMakanan(m2);

    printf("%d\n", basiBersamaan(m2, m1));

    return 0;
}
