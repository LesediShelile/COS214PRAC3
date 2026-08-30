#include "EventComponent.h"
#include <iostream>

EventComponent::EventComponent(const std::string& name)
    : name(name), openState(false) {}

void EventComponent::open() {
    openState = true;
}

void EventComponent::close() {
    openState = false;
}

void EventComponent::reportStatus() const {
    std::cout << name << " is " << (openState ? "OPEN" : "CLOSED")
              << ". Capacity: " << getCapacity() << std::endl;
}

int EventComponent::getCapacity() const {
    return 0;
}

void EventComponent::add(EventComponent* /*component*/) {}
void EventComponent::remove(EventComponent* /*component*/) {}

void EventComponent::display(int depth) const {
    std::cout << std::string(depth * 2, ' ') << "- " << name << std::endl;
}

std::string EventComponent::getName() const {
    return name;
}
