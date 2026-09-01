#include "Convention.h"
#include "EventControl.h"
#include "AnnouncementBoard.h"
#include "RefereeTeam.h"
#include <iostream>

int main() {
    Convention gameVerse;
    EventControl control;
    AnnouncementBoard board;

    std::cout << "=== GameVerse Convention ===\n";

    // ============================================================
    // COMPOSITE: Initial structure and traversal
    // ============================================================
    std::cout << "\n=== Initial Convention Structure ===\n";
    gameVerse.display();

    std::cout << "\n=== Composite Query ===\n";
    std::cout << "Total represented capacity: "
              << gameVerse.getCapacity() << std::endl;

    // Test state operations through the Composite.
    std::cout << "\n=== Opening Convention ===\n";
    gameVerse.open();
    gameVerse.reportStatus();

    // ============================================================
    // OBSERVER: Attach observers
    // ============================================================
    std::cout << "\n=== Registering Observers ===\n";
    control.attach(&gameVerse);
    control.attach(&board);

    // ============================================================
    // OBSERVER: Test all major notice types
    // ============================================================
    std::cout << "\n=== Safety Alerts ===\n";

    control.issueNotice(new SafetyAlertNotice(
        "Unattended item reported near the Esports Hall.",
        EventNotice::Severity::HIGH));

    control.issueNotice(new SafetyAlertNotice(
        "Minor spill near vendor row, no threat to matches.",
        EventNotice::Severity::LOW));

    std::cout << "\n=== Capacity Alert ===\n";
    control.issueNotice(new CapacityAlertNotice(
        "Registration Centre queue exceeding limit."));

    std::cout << "\n=== Server Outage ===\n";
    control.issueNotice(new ServerOutageNotice(
        "Esports Hall network switch failure."));

    std::cout << "\n=== Open Area ===\n";
    control.issueNotice(new OpenAreaNotice(
        "Additional seating area is now open to visitors."));

    std::cout << "\n=== Close Area ===\n";
    control.issueNotice(new CloseAreaNotice(
        "Vendor Row B temporarily closed for maintenance."));

    std::cout << "\n=== Schedule Change ===\n";
    control.issueNotice(new ScheduleChangeNotice(
        "Creator demonstrations moved by 30 minutes."));

    std::cout << "\n=== Temporary Pause ===\n";
    control.issueNotice(new TemporaryPauseNotice(
        "Tournament activities temporarily paused."));

    std::cout << "\n=== Evacuation ===\n";
    control.issueNotice(new EvacuateNotice(
        "Please evacuate the building using the nearest marked exit."));

    // ============================================================
    // DECISION BASED ON COMPOSITE QUERY
    // ============================================================
    std::cout << "\n=== Capacity Decision ===\n";

    if (gameVerse.getCapacity() >= 2000) {
        control.issueNotice(new CapacityAlertNotice(
            "Aggregate capacity threshold reached."));
    } else {
        control.issueNotice(new OpenAreaNotice(
            "Capacity is below the warning threshold."));
    }

    // ============================================================
    // COMPOSITE: Runtime reorganisation
    // ============================================================
    std::cout << "\n=== Runtime Reorganisation ===\n";

    EventGroup* demoZone = gameVerse.findGroup("Demo Zone");
    EventGroup* vipArea = gameVerse.findGroup("VIP Services");

    if (demoZone != 0 && vipArea != 0) {
        EventComponent* booth =
            demoZone->takeChild("Game Demo Booth");

        if (booth != 0) {
            vipArea->add(booth);

            std::cout
                << "Game Demo Booth transferred from "
                << "Demo Zone to VIP Services.\n";
        } else {
            std::cout
                << "Game Demo Booth could not be found.\n";
        }
    } else {
        std::cout
            << "Required groups could not be found.\n";
    }

    std::cout << "\n=== Structure After Reorganisation ===\n";
    gameVerse.display();

    // ============================================================
    // DYNAMIC OBSERVER REGISTRATION
    // ============================================================
    std::cout
        << "\n=== Tournament Begins: Referee Team Registers ===\n";

    RefereeTeam tournamentReferees;

    control.attach(&tournamentReferees);

    control.issueNotice(new ScheduleChangeNotice(
        "Grand final start time confirmed for 18:00."));

    std::cout
        << "\n=== Tournament Ends: Referee Team Unregisters ===\n";

    control.detach(&tournamentReferees);

    control.issueNotice(new ScheduleChangeNotice(
        "Venue schedule updated for tomorrow's exhibition matches."));

    // ============================================================
    // DETACH ALL MAIN OBSERVERS
    // ============================================================
    std::cout << "\n=== Detaching Main Observers ===\n";

    control.detach(&gameVerse);
    control.detach(&board);

    std::cout << "\n=== Observers Detached ===\n";

    // This tests that detached observers no longer receive notices.
    control.issueNotice(new TemporaryPauseNotice(
        "Convention temporarily paused."));

    // ============================================================
    // FINAL COMPOSITE STATE
    // ============================================================
    std::cout << "\n=== Closing Convention ===\n";

    gameVerse.close();

    std::cout << "\n=== Final Status ===\n";
    gameVerse.reportStatus();

    std::cout << "\n=== Final Convention Structure ===\n";
    gameVerse.display();

    return 0;
}