#include "../Teks/teks.h"
#include "../ListDinKar/ldinkar.h"
#include "notification.h"

int main(int argc, char const *argv[])
{
    Notif n1;
    Teks nT1;
    buatTeks("Ayam Goreng", &nT1);
    buatNotif('p', nT1, &n1);
    cetakNotif(n1);
    /* code */
    return 0;
}
