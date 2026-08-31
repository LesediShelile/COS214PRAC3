#ifndef OBSERVER_H
#define OBSERVER_H

class EventNotice;

/**
 * @brief Observer role in the Gang of Four Observer pattern.
 *
 * Subjects store non-owning Observer pointers and do not manage observer
 * lifetime.
 */
class Observer {
public:
    /** @brief Receives a pushed event notice. @param notice Notice supplied by a Subject. */
    virtual void update(const EventNotice& notice) = 0;
    /** @brief Virtual destructor for safe polymorphic destruction. */
    virtual ~Observer() {}
};

#endif
