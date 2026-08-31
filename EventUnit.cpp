#include "EventUnit.h"
#include <iostream>

EventUnit::EventUnit(const std::string& name, int capacity)
    : EventComponent(name), capacity(capacity) {}

void EventUnit::open() {
    EventComponent::open();
}

void EventUnit::close() {
    EventComponent::close();
}

void EventUnit::display(int depth ) const {

    for (int i = 0; i < depth; ++i)
    {
        std::cout << "  ";
    }

    std::cout << name << std::endl;

}

void EventUnit::reportStatus() const {
    std::cout << name << " is " << (openState ? "OPEN" : "CLOSED")
              << ". Capacity: " << capacity << std::endl;
}

int EventUnit::getCapacity() const {
    return capacity;
}

void EventUnit::onSafetyAlert() {}
void EventUnit::onCapacityAlert() {}
void EventUnit::onServerOutage() {}
void EventUnit::onEvacuate() {}
void EventUnit::onScheduleChange() {}
void EventUnit::onOpenArea() {}
void EventUnit::onCloseArea() {}
void EventUnit::onWeatherAlert() {}
void EventUnit::onTemporaryPause() {}
void EventUnit::onResume() {}
