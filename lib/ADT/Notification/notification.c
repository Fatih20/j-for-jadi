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
    if (teksSama(command, fryT))
    {
        kodeNTF = 'f';
    }
    else if (teksSama(command, chopT))
    {
        kodeNTF = 'c';
    }
    else if (teksSama(command, boilT))
    {
        kodeNTF = 'b';
    }
    else if (teksSama(command, mixT))
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
    cetakTeks(notifTeks(notif));
};
