#include "EventComponent.h"
#include <iostream>

EventComponent::EventComponent(const std::string& name) : name(name) {}

void EventComponent::add(EventComponent* /*component*/) {
    // Leaves have no children; default implementation intentionally does nothing.
}

void EventComponent::remove(EventComponent* /*component*/) {
    // Leaves have no children; default implementation intentionally does nothing.
}

void EventComponent::display(int depth) const {
    std::cout << std::string(depth * 2, ' ') << "- " << name << std::endl;
}

std::string EventComponent::getName() const {
    return name;
}
