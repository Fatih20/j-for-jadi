#include "notificationState.h"

void buatNotifState(NotifState *notifState, LDinNotif forward, LDinNotif backward)
{
    forNS(*notifState) = forward;
    backNS(*notifState) = backward;
};

void buatNotifStateR(NotifState *notifState)
{
    LDinNotif forward;
    LDinNotif backward;
    buatLDinNotif(&forward, 5);
    buatLDinNotif(&backward, 5);
    buatNotifState(notifState, forward, backward);
};

void copyNotifState(NotifState nSIn, NotifState *nSOut)
{
    LDinNotif salinanF;
    LDinNotif salinanB;
    copyLDinNotif(forNS(nSIn), &salinanF);
    copyLDinNotif(backNS(nSIn), &salinanB);
    forNS(*nSOut) = salinanF;
    backNS(*nSOut) = salinanB;
};
