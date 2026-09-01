#include "EventGroup.h"
#include "EventNotice.h"
#include <iostream>
#include <algorithm>

EventGroup::EventGroup(const std::string& name) : EventComponent(name) {}

EventGroup::~EventGroup() {
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        delete *it;
    }
    children.clear();
}

void EventGroup::add(EventComponent* component) {
    if (component == 0) return;
    if (std::find(children.begin(), children.end(), component) != children.end()) return;

    children.push_back(component);
    // Structural ownership and observation are separate relationships, but
    // every component in this event tree is intentionally registered so a
    // notice can cascade through the same hierarchy.
    attach(component);
}

void EventGroup::remove(EventComponent* component) {
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        if (*it == component) {
            detach(component);
            children.erase(it);
            return;
        }
    }
}

EventComponent* EventGroup::takeChild(const std::string& childName) {
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        if ((*it)->getName() == childName) {
            EventComponent* component = *it;
            detach(component);
            children.erase(it);
            return component;
        }
    }
    return 0;
}

EventGroup* EventGroup::findGroup(const std::string& groupName) {
    if (name == groupName) return this;
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        EventGroup* group = dynamic_cast<EventGroup*>(*it);
        if (group != 0) {
            EventGroup* result = group->findGroup(groupName);
            if (result != 0) return result;
        }
    }
    return 0;
}

void EventGroup::display(int depth) const {
    for (int i = 0; i < depth; ++i) std::cout << "  ";
    std::cout << name << std::endl;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->display(depth + 1);
    }
}

void EventGroup::open() {
    EventComponent::open();
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->open();
    }
}

void EventGroup::close() {
    EventComponent::close();
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->close();
    }
}

void EventGroup::reportStatus() const {
    std::cout << name << ": " << (openState ? "Open" : "Closed") << std::endl;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it) {
        (*it)->reportStatus();
    }
}

int EventGroup::getCapacity() const {
    int totalCapacity = 0;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it) {
        totalCapacity += (*it)->getCapacity();
    }
    return totalCapacity;
}

void EventGroup::update(const EventNotice& notice) {
    std::cout << "[" << name << "] received " << notice.getType()
              << " -> cascading to " << children.size() << " member(s)." << std::endl;
    notify(notice);
}
