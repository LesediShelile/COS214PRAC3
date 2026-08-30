#ifndef OBSERVER_H
#define OBSERVER_H

class EventNotice;

/**
 * @brief Observer role of the Observer pattern.
 *
 * Objects that need event notices implement update().
 */
class Observer {
public:
    /** @brief Receives a pushed event notice. @param notice Notice being delivered. */
    virtual void update(const EventNotice& notice) = 0;
    /** @brief Virtual destructor for polymorphic destruction. */
    virtual ~Observer() {}
};

#endif
