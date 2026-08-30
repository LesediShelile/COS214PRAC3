#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class EventNotice;

// Subject role: keeps a list of Observers and pushes notices out to them.
// EventControl uses this to broadcast into the convention, and EventGroup
// reuses it to relay a notice it received on down to its own children.
class Subject {
    protected:
        std::vector<Observer*> observers;

    public:
        virtual void attach(Observer* observer);
        virtual void detach(Observer* observer);
        virtual void notify(const EventNotice& notice);
        virtual ~Subject() {}
};

#endif
