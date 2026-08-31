#include "EventGroup.h"
#include "EventNotice.h"

#include <iostream>
#include <vector>

EventGroup::EventGroup(const std::string& name) : EventComponent(name) {}

EventGroup::~EventGroup() {
    

}

void EventGroup::add(EventComponent* component) {
    if (component == 0) return;
    children.push_back(component);

    if (component != nullptr) {
        children.push_back(component);
    }
}

void EventGroup::remove(EventComponent* component) {
    for (auto it = children.begin(); it != children.end(); ++it)
    {
        if (*it == component)
        {
            children.erase(it);
            return;
        }
    }
}

void EventGroup::display(int depth)const {
   for (int i = 0; i < depth; ++i)
    {
        std::cout << "  ";
    }

    std::cout << name << std::endl;

    for (EventComponent* child : children)
    {
        child->display(depth + 1);
    }
}

void EventGroup::open() {
    EventComponent::open();
    for (std::vector<EventComponent*>::iterator child = children.begin(); child != children.end(); ++child) {
        (*child)->open();
    }
}

void EventGroup::close() {
       openState = false;

    for (EventComponent* child : children) {
        child->close();
    }
}

void EventGroup::reportStatus() const {
    std::cout << name << ": "
              << (openState ? "Open" : "Closed")
              << std::endl;

    for (EventComponent* component : children) {
        component->reportStatus();
    }
}

int EventGroup::getCapacity() const {
     int totalCapacity = 0;

    for (EventComponent* component : children) {
        totalCapacity += component->getCapacity();
    }

    return totalCapacity;
}

void EventGroup::update(const EventNotice& notice) {
    std::cout << "[" << name << "] received " << notice.getTypeName()
              << " -> relaying to " << children.size() << " member(s)." << std::endl;
    notify(notice);
}
