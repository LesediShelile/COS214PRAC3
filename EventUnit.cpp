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

void EventUnit::reportStatus() const {
    std::cout << name << " is " << (openState ? "OPEN" : "CLOSED")
              << ". Capacity: " << capacity << std::endl;
}

int EventUnit::getCapacity() const {
    return capacity;
}
