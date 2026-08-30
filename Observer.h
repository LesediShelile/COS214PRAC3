#ifndef OBSERVER_H
#define OBSERVER_H

class EventNotice;

// Observer role: anything that can be told about a change in the convention.
// Both EventUnit (leaf) and EventGroup (composite) implement this.
class Observer {
    public:
        virtual void update(const EventNotice& notice) = 0;
        virtual ~Observer() {}
};

#endif
