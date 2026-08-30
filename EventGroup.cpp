#include "EventGroup.h"
#include "EventNotice.h"
#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& name) : EventComponent(name) {}

EventGroup::~EventGroup() {
    // Observer references are non-owning. Detach before destroying owned
    // children so no subject retains a pointer to an object being destroyed.
    for (std::vector<Observer*>::iterator it = observers.begin(); it != observers.end(); ++it) {
        // Nothing is deleted here; the references are simply cleared below.
        (void)*it;
    }
    observers.clear();

    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        delete *it;
    }
    children.clear();
}

void EventGroup::add(EventComponent* component) {
    if (component == 0) return;
    children.push_back(component);

    Observer* observer = dynamic_cast<Observer*>(component);
    if (observer != 0) {
        attach(observer);
    }
}

void EventGroup::remove(EventComponent* component) {
    std::vector<EventComponent*>::iterator it =
        std::find(children.begin(), children.end(), component);
    if (it == children.end()) return;

    Observer* observer = dynamic_cast<Observer*>(component);
    if (observer != 0) detach(observer);
    children.erase(it);
}

EventComponent* EventGroup::takeChild(const std::string& childName) {
    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        if ((*it)->getName() == childName) {
            EventComponent* result = *it;
            Observer* observer = dynamic_cast<Observer*>(result);
            if (observer != 0) detach(observer);
            children.erase(it);
            return result;
        }
    }
    return 0;
}

EventGroup* EventGroup::findGroup(const std::string& groupName) {
    if (name == groupName) return this;

    for (std::vector<EventComponent*>::iterator it = children.begin(); it != children.end(); ++it) {
        EventGroup* group = dynamic_cast<EventGroup*>(*it);
        if (group != 0) {
            EventGroup* found = group->findGroup(groupName);
            if (found != 0) return found;
        }
    }
    return 0;
}

void EventGroup::display(int depth) const {
    std::cout << std::string(depth * 2, ' ') << "- " << name << std::endl;
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
    std::cout << name << " is " << (openState ? "OPEN" : "CLOSED")
              << ". Aggregate capacity: " << getCapacity() << std::endl;
}

int EventGroup::getCapacity() const {
    int total = 0;
    for (std::vector<EventComponent*>::const_iterator it = children.begin(); it != children.end(); ++it) {
        total += (*it)->getCapacity();
    }
    return total;
}

void EventGroup::update(const EventNotice& notice) {
    std::cout << "[" << name << "] received " << notice.getTypeName()
              << " -> relaying to " << children.size() << " member(s)." << std::endl;
    notify(notice);
}
