#include "notificationState.h"

void buatNotifState(NotifState *notifState, LDinNotif forward, LDinNotif backward)
{
    forNS(*notifState) = forward;
    backNS(*notifState) = backward;
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
