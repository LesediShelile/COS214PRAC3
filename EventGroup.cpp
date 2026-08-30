#include "EventGroup.h"
#include "EventNotice.h"
#include <algorithm>
#include <iostream>

EventGroup::EventGroup(const std::string& name) : EventComponent(name) {}

EventGroup::~EventGroup() {
    for (EventComponent* child : children) {
        delete child;
    }
}

void EventGroup::add(EventComponent* component) {
    if (component == nullptr) return;

    children.push_back(component);

    // Every child in this tree is also an Observer (EventUnit or EventGroup),
    // so registering it here is what lets notify() reach it later.
    Observer* observer = dynamic_cast<Observer*>(component);
    if (observer != nullptr) {
        attach(observer);
    }
}

void EventGroup::remove(EventComponent* component) {
    children.erase(std::remove(children.begin(), children.end(), component), children.end());

    Observer* observer = dynamic_cast<Observer*>(component);
    if (observer != nullptr) {
        detach(observer);
    }
}

void EventGroup::display(int depth) const {
    std::cout << std::string(depth * 2, ' ') << "- " << name << std::endl;
    for (const EventComponent* child : children) {
        child->display(depth + 1);
    }
}

void EventGroup::update(const EventNotice& notice) {
    std::cout << "[" << name << "] received " << notice.getTypeName()
              << " -> relaying to " << children.size() << " member(s)." << std::endl;
    notify(notice);
}
