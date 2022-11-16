#include "notification.h"

Teks notifTeks(Notif ntf)
{
    Teks result;
    buatTeksKosong(&result);
    char kodeNtf = kodeNTF(ntf);
    Teks subject = subNTF(ntf);
    Teks toAppend;
    switch (kodeNtf)
    {
    case 'd':
        buatTeks(" sudah diterima oleh BNMO!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 'e':
        buatTeks(" sudah kadaluarsa!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 's':
        buatTeks(" batal sampai!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 'n':
        buatTeks(" tidak jadi kadaluarsa dan telah kembali ke inventory!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 'f':
        buatTeks(" batal digoreng!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 'b':
        buatTeks(" batal direbus!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 'm':
        buatTeks(" batal dicampur!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 'c':
        buatTeks(" batal dipotong!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    case 'p':
        buatTeks(" batal dibeli!", &toAppend);
        tambahkanTeks(&result, subject);
        tambahkanTeks(&result, toAppend);
        break;
    default:
        break;
    }
    return result;
};

void buatNotif(char kode, Teks subject, Notif *notif)
{
    subNTF(*notif) = subject;
    kodeNTF(*notif) = kode;
};

void buatNotifCookUndo(Teks command, Teks subject, Notif *notif)
{
    Teks fryT;
    buatTeks("FRY", &fryT);
    Teks chopT;
    buatTeks("CHOP", &chopT);
    Teks boilT;
    buatTeks("BOIL", &boilT);
    Teks mixT;
    buatTeks("MIX", &mixT);
    char kodeNTF;
    if (teksSamaCI(command, fryT))
    {
        kodeNTF = 'f';
    }
    else if (teksSamaCI(command, chopT))
    {
        kodeNTF = 'c';
    }
    else if (teksSamaCI(command, boilT))
    {
        kodeNTF = 'b';
    }
    else if (teksSamaCI(command, mixT))
    {
        kodeNTF = 'm';
    }
    else
    {
        kodeNTF = 'f';
    }
    buatNotif(kodeNTF, subject, notif);
};

void cetakNotif(Notif notif)
{
    char kN = kodeNTF(notif);
    char colorP;
    switch (kN)
    {
    case 'd':
        colorP = 'b';
        break;
    case 'e':
        colorP = 'r';
        break;
    case 's':
        colorP = 'r';
        break;
    case 'n':
        colorP = 'g';
        break;
    case 'f':
        colorP = 'm';
        break;
    case 'b':
        colorP = 'm';
        break;
    case 'm':
        colorP = 'm';
        break;
    case 'c':
        colorP = 'm';
        break;
    case 'p':
        colorP = 'm';
        break;

    default:
        colorP = 'e';
        break;
    }
    cetakTeks(notifTeks(notif), colorP);
};
