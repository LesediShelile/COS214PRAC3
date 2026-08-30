#include "Convention.h"
#include "EventControl.h"
#include "EventNotice.h"
#include <iostream>

int main() {
    Convention gameVerse;
    EventControl control;

    std::cout << "=== GameVerse Convention ===\n";
    gameVerse.display();

    std::cout << "\n=== Composite query ===\n";
    std::cout << "Total represented capacity: " << gameVerse.getCapacity() << std::endl;
    gameVerse.open();
    gameVerse.reportStatus();

    // Observer registration: EventControl knows only the root Composite.
    control.attach(&gameVerse);

    std::cout << "\n=== Observer notifications ===\n";
    control.issueNotice(NoticeType::SAFETY_ALERT,
                        "Unattended item reported near the Esports Hall.");
    control.issueNotice(NoticeType::CAPACITY_ALERT,
                        "Registration Centre queue exceeding limit.");
    control.issueNotice(NoticeType::SERVER_OUTAGE,
                        "Esports Hall network switch failure.");

    // Condition-based decision suitable for SD3's alt fragment.
    std::cout << "\n=== Capacity decision ===\n";
    if (gameVerse.getCapacity() >= 2000) {
        control.issueNotice(NoticeType::CAPACITY_ALERT,
                            "Aggregate capacity threshold reached.");
    } else {
        control.issueNotice(NoticeType::OPEN_AREA,
                            "Capacity is below the warning threshold.");
    }

    // Runtime reorganisation: transfer a leaf from Demo Zone to VIP Services.
    // remove/take detaches the observer and add re-attaches it to its new Subject.
    EventGroup* demoZone = gameVerse.findGroup("Demo Zone");
    EventGroup* vipArea = gameVerse.findGroup("VIP Services");
    if (demoZone != 0 && vipArea != 0) {
        EventComponent* booth = demoZone->takeChild("Game Demo Booth");
        if (booth != 0) {
            vipArea->add(booth);
            std::cout << "\n=== Runtime reorganisation ===\n";
            std::cout << "Game Demo Booth transferred from Demo Zone to VIP Services.\n";
        }
    }

    control.issueNotice(NoticeType::SCHEDULE_CHANGE,
                        "Creator demonstrations moved by 30 minutes.");

    // Registration change: the root is detached, so it receives no further notices.
    control.detach(&gameVerse);
    std::cout << "\n=== Observer detached ===\n";
    control.issueNotice(NoticeType::TEMPORARY_PAUSE,
                        "Convention temporarily paused.");

    gameVerse.close();
    gameVerse.reportStatus();

    // gameVerse owns its complete Composite subtree. Its destructor releases
    // every remaining child exactly once when main exits.
    return 0;
}
