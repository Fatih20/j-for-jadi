#ifndef NOTIF
#define NOTIF

#include "../Teks/teks.h"

/**
 * @brief Notification ADT
 * @param kodeNotif kode menunjukkan notifikasi ini tentang apa
 * @param subject notifikasi ini concerning bahan makanan apa
 */
typedef struct
{
    char kodeNotif;
    Teks subject;

} Notif;

#define kodeNTF(S) (S).kodeNotif
#define subNTF(S) (S).subject

/**
 * @brief Memproduksi teks notifikasi dari ntf
 *
 * @param ntf
 * @return Teks
 */
Teks notifTeks(Notif ntf);

/**
 * @brief Membuat sebuah notif dengan kodeNotif kode dan subject subject
 *
 * @param kode
 * @param subject
 * @param notif
 */
void buatNotif(char kode, Teks subject, Notif *notif);

/**
 * @brief Membuat sebuah notif khusus masak sesuai command yang diberikan dan subject
 *
 * @param command
 * @param subject
 * @param notif
 */
void buatNotifCookUndo(Teks command, Teks subject, Notif *notif);

/**
 * @brief Mencetak notif dengan format sesuai spek
 *
 * @param notif
 */
void cetakNotif(Notif notif);

#endif