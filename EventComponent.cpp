#include "EventComponent.h"
#include <iostream>

EventComponent::EventComponent(const std::string& name, int capacity)
    : name(name), openState(true), capacity(capacity) {}

void EventComponent::open() { openState = true; }
void EventComponent::close() { openState = false; }
void EventComponent::reportStatus() const {
    std::cout << name << ": " << (openState ? "OPEN" : "CLOSED")
              << ", capacity=" << capacity << std::endl;
}
int EventComponent::getCapacity() const { return capacity; }
std::string EventComponent::getName() const { return name; }
