#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class EventNotice;

/**
 * @brief Observer Subject abstraction.
 *
 * Observer pointers are non-owning. Attaching the same observer twice is
 * ignored, and detaching an unregistered observer has no effect.
 */
class Subject {
    protected:
        std::vector<Observer*> observers;

    public:
        virtual ~Subject() {}
        /** @param observer Non-owning observer reference to register. */
        virtual void attach(Observer* observer);
        /** @param observer Observer reference to unregister. */
        virtual void detach(Observer* observer);
        /** @param notice Notice to push to a snapshot of current observers. */
        virtual void notify(const EventNotice& notice);
};

#endif
