// main.cpp - the Client. It only knows about Convention and EventControl;
// it has no idea that a Convention contains an OperationsArea, or that a
// Registration Centre contains a Check-In Desk. Each composite encapsulates
// its own subtree (see e.g. Convention.cpp, OperationsArea.cpp), so the
// client just builds the root, wires it to EventControl, and operates on
// the tree through those two interfaces.

#include "Convention.h"
#include "EventControl.h"
#include "EventNotice.h"
#include <iostream>

int main() {
    Convention gameVerse;

    std::cout << "GameVerse Convention structure (Composite):\n";
    gameVerse.display();

    EventControl control;
    control.attach(&gameVerse);

    std::cout << "\nSimulating notices (Observer cascade):\n";
    control.issueNotice(NoticeType::SAFETY_ALERT, "Unattended item reported near the Esports Hall.");
    control.issueNotice(NoticeType::CAPACITY_ALERT, "Registration Centre queue exceeding limit.");
    control.issueNotice(NoticeType::SERVER_OUTAGE, "Esports Hall network switch failure.");
    control.issueNotice(NoticeType::EVACUATE, "Fire alarm triggered in Main Operations.");
    control.issueNotice(NoticeType::SCHEDULE_CHANGE, "Championship final moved back 30 minutes.");

    return 0;
    // gameVerse is a stack object, so its destructor (and the cascading
    // EventGroup destructor) cleans up every child automatically here.
}
