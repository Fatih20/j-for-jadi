#include "notificationState.h"

void buatNotifState(NotifState *notifState, LDinNotif forward, LDinNotif backward)
{
    forNS(*notifState) = forward;
    backNS(*notifState) = backward;
};
