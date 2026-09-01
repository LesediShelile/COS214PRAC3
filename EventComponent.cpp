#include "EventComponent.h"
#include <iostream>

EventComponent::EventComponent(const std::string& name) : name(name), openState(false) {}

void EventComponent::open() {
    openState = true;
}

void EventComponent::close() {
    openState = false;
}

void EventComponent::reportStatus() const {
    std::cout << name << ": " << (openState ? "Open" : "Closed") << std::endl;
}

int EventComponent::getCapacity() const {
    return 0;
}

void EventComponent::display(int depth) const {
    for (int i = 0; i < depth; ++i) {
        std::cout << "  ";
    }
    std::cout << name << std::endl;
}

std::string EventComponent::getName() const {
    return name;
}