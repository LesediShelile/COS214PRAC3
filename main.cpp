#include "Convention.h"
#include "EventControl.h"
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

    control.attach(&gameVerse);

    std::cout << "\n=== Observer notifications ===\n";
    control.issueNotice(new SafetyAlertNotice(
        "Unattended item reported near the Esports Hall."));
    control.issueNotice(new CapacityAlertNotice(
        "Registration Centre queue exceeding limit."));
    control.issueNotice(new ServerOutageNotice(
        "Esports Hall network switch failure."));

    std::cout << "\n=== Capacity decision ===\n";
    if (gameVerse.getCapacity() >= 2000) {
        control.issueNotice(new CapacityAlertNotice(
            "Aggregate capacity threshold reached."));
    } else {
        control.issueNotice(new OpenAreaNotice(
            "Capacity is below the warning threshold."));
    }

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

    control.issueNotice(new ScheduleChangeNotice(
        "Creator demonstrations moved by 30 minutes."));

    control.detach(&gameVerse);
    std::cout << "\n=== Observer detached ===\n";
    control.issueNotice(new TemporaryPauseNotice(
        "Convention temporarily paused."));

    gameVerse.close();
    gameVerse.reportStatus();
    return 0;
}
