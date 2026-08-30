#include "EventGroup.h"
#include "EventNotice.h"
#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& name) : EventComponent(name, 0) {}

EventGroup::~EventGroup() {
    observers.clear();
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it)
        delete *it;
    children.clear();
}

void EventGroup::add(EventComponent* component) {
    if (component == 0 || std::find(children.begin(), children.end(), component) != children.end()) return;
    children.push_back(component);
    attach(component);
}

void EventGroup::remove(EventComponent* component) {
    std::vector<EventComponent*>::iterator it = std::find(children.begin(), children.end(), component);
    if (it == children.end()) return;
    detach(component);
    children.erase(it);
}

void EventGroup::open() {
    openState = true;
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) (*it)->open();
}

void EventGroup::close() {
    openState = false;
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) (*it)->close();
}

void EventGroup::reportStatus() const {
    std::cout << name << ": " << (openState ? "OPEN" : "CLOSED")
              << ", aggregate capacity=" << getCapacity() << std::endl;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it)
        (*it)->reportStatus();
}

int EventGroup::getCapacity() const {
    int total = 0;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it)
        total += (*it)->getCapacity();
    return total;
}

void EventGroup::update(const EventNotice& notice) {
    std::cout << "[" << name << "] relays " << notice.getTypeName() << std::endl;
    notify(notice);
}
