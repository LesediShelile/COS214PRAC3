#include "EventControl.h"
#include "EventGroup.h"
#include "EsportsStage.h"
#include "SpectatorGate.h"
#include "GameDemoBooth.h"
#include "VRStation.h"
#include "MedicalTeam.h"
#include "InformationDesk.h"
#include "SecurityTeam.h"
#include "BadgeStation.h"
#include <iostream>

int main() {
    // Client builds the Composite and establishes Observer registration through add().
    EventGroup* gameVerse = new EventGroup("GameVerse Convention");
    EventGroup* operations = new EventGroup("Main Operations");
    EventGroup* registration = new EventGroup("Registration Centre");
    EventGroup* security = new EventGroup("Security Operations");
    EventGroup* esports = new EventGroup("Esports Hall");
    EventGroup* tournament = new EventGroup("Championship Arena");
    EventGroup* experience = new EventGroup("Experience Hall");
    EventGroup* demos = new EventGroup("Demo Zone");
    EventGroup* vip = new EventGroup("VIP Services");

    BadgeStation* badge = new BadgeStation();
    SecurityTeam* securityTeam = new SecurityTeam();
    EsportsStage* stage = new EsportsStage();
    SpectatorGate* gate = new SpectatorGate();
    VRStation* vr = new VRStation();
    GameDemoBooth* demo = new GameDemoBooth();
    MedicalTeam* medical = new MedicalTeam();
    InformationDesk* info = new InformationDesk();

    gameVerse->add(operations);
    gameVerse->add(esports);
    gameVerse->add(experience);
    gameVerse->add(vip);

    operations->add(registration);
    operations->add(security);
    registration->add(badge);
    security->add(securityTeam);
    operations->add(medical);
    esports->add(tournament);
    tournament->add(stage);
    tournament->add(gate);
    experience->add(demos);
    demos->add(vr);
    demos->add(demo);
    vip->add(info);

    std::cout << "\n=== Composite structure / aggregate capacity ===\n";
    gameVerse->reportStatus();

    EventControl control;
    control.attach(gameVerse);

    std::cout << "\n=== Observer cascade ===\n";
    control.issueNotice(NoticeType::WEATHER_ALERT, "Severe weather near the outdoor convention entrance.");
    if (gameVerse->getCapacity() >= 700) {
        control.issueNotice(NoticeType::CAPACITY_ALERT, "The convention is approaching its safe attendee limit.");
    } else {
        control.issueNotice(NoticeType::OPEN_AREA, "Capacity is currently safe; registration remains open.");
    }
    control.issueNotice(NoticeType::EVACUATE, "Fire alarm: begin controlled evacuation.");

    std::cout << "\n=== Runtime reorganisation ===\n";
    std::cout << "Moving Game Demo Booth from Demo Zone to VIP Services.\n";
    demos->remove(demo);   // detaches observer and releases ownership
    vip->add(demo);        // new owner; automatically re-attaches observer
    control.issueNotice(NoticeType::SCHEDULE_CHANGE, "VIP demo programme updated after the move.");

    std::cout << "\n=== Registration change ===\n";
    control.detach(gameVerse);
    std::cout << "GameVerse detached from EventControl; no further control notices are delivered.\n";

    delete gameVerse;      // destroys the complete owned subtree exactly once
    return 0;
}
