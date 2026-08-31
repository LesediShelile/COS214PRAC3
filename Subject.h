#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class EventNotice;

/**
 * @brief Subject role in the Gang of Four Observer pattern.
 *
 * Observer pointers are non-owning. Duplicate registration is ignored and
 * detaching an observer that is not registered has no effect.
 */
class Subject {
protected:
    /**
     * @brief Non-owning pointers to registered observers.
     *
     * Subject does not own these observers and does not delete them.
     * Observers must remain valid while registered.
     */
    std::vector<Observer*> observers;

public:
    /** @brief Virtual destructor. Registered observers are not deleted. */
    virtual ~Subject() {}
    /**
     * @brief Registers an observer for future notifications.
     * @param observer Non-owning observer pointer. Must remain valid while registered.
     */
    virtual void attach(Observer* observer);
    /**
     * @brief Removes an observer registration without deleting the observer.
     * @param observer Observer to unregister.
     */
    virtual void detach(Observer* observer);
    /**
     * @brief Pushes a notice to a snapshot of the current observer list.
     * @param notice Notice to send to observers.
     */
    virtual void notify(const EventNotice& notice);
};

#endif
