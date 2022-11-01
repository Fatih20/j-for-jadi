#ifndef NOTIFSTATE
#define NOTIFSTATE

#include "../ListDinNotif/listDinNotif.h"

typedef struct
{
    LDinNotif forward;
    LDinNotif backward;
} NotifState;

#define forNS(S) (S).forward
#define backNS(S) (S).backward

/**
 * @brief Membuat notifState dengan forward forward dan backward backward
 *
 * @param notifState
 * @param forward
 * @param backward
 */
void buatNotifState(NotifState *notifState, LDinNotif forward, LDinNotif backward);

#endif