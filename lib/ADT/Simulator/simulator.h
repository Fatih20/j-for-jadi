#ifndef STATE_H
#define STATE_H

#include "../boolean.h"
#include "../Point/Point.h"
#include "../FoodQueue/foodQueue.h"
#include "../Waktu/waktu.h"
#include "../NotificationState/notificationState.h"
#include "../Kulkas/kulkas.h"

/**
 * @brief Tipedata State
 * @param userName: ADT Teks untuk menunjukkan username simulator
 * @param posisi: ADT Point tempat aksi tersebut dilakukan
 * @param waktu: ADT Waktu penunjuk waktu sebuah state
 * @param inventory: ADT FoodQueue sebagai inventory
 * @param delivery: ADT FoodQueue sebagai delivery
 * @param notifS: ADT notifState sebagai notifikasi
 * @param kulkas: ADT Kulkas sebagai kulkas
 */
typedef struct
{
    Teks userName;
    POINT posisi;
    Waktu waktu;
    FoodQueue inventory;
    FoodQueue delivery;
    NotifState notifS;
    Kulkas kulkas;
} Simulator;

/**
 * @brief Notasi Akses: Selektor AksiLokasi
 */
#define userNameSimulator(S) (S).userName
#define posisiSimulator(S) (S).posisi
#define waktuSimulator(S) (S).waktu
#define inventorySimulator(S) (S).inventory
#define deliverySimulator(S) (S).delivery
#define notifSimulator(S) (S).notifS
#define kulkasSimulator(S) (S).kulkas

/**
 * @brief Membuat simulator baru
 * @param userName: ADT Teks untuk menunjukkan username simulator
 * @param x : absis posisi
 * @param y : ordinat posisi
 * @param HH : hari dari waktu state
 * @param JJ : jam dari waktu state
 * @param MM : menit dari waktu state
 * @param DD : detik dari waktu state
 * @param inventory: ADT FoodQueue sebagai inventory
 * @param delivery: ADT FoodQueue sebagai delivery
 * @param kulkas: ADT Kulkas sebagai kulkas
 */
void buatSimulator(Simulator *S, Teks userName, int x, int y, int HH, int JJ, int MM, int DD, FoodQueue inventory, FoodQueue delivery, Kulkas kulkas);

/**
 * @brief Menampilkan Tipedata Simulator
 * @param S: Tipedata Simulator yang akan ditampilkan
 */
void cetakSimulator(Simulator S);

/**
 * @brief Mengisi SOut dengan salinan dari SIn
 *
 * @param SIn: Simulator yang akan dicopy
 * @param SOut: Simulator copy-an
 */
void copySimulator(Simulator SIn, Simulator *SOut);

/**
 * @brief Memajukan waktu state sebesar waktu
 *
 * @param S: Simulator yang akan berubah
 * @param waktu: Waktu yang dimajukan
 * @param nS: Notifikasi simulator
 * @param kulkas: Kulkas simulator
 */
void majukanWaktuSimulator(Simulator *S, Waktu waktu, NotifState *nS);
/**
 * @brief Mengembalikan true jika kedua simulator sama
 *
 * @param S1
 * @param S2
 * @return boolean
 */
boolean isEqualSimulator(Simulator S1, Simulator S2);

/**
 * @brief Menambahkan notif forward ke simulator
 *
 * @param kode
 * @param subject
 * @param S : Simulator
 */
void tambahNotifF(char kode, Teks subject, Simulator *S);

/**
 * @brief Menambahkan notif backward ke simulator
 *
 * @param kode
 * @param subject
 * @param state
 */
void tambahNotifB(char kode, Teks subject, Simulator *state);

#endif