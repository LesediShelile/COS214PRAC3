#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

class Observer;
class EventNotice;

/**
 * @brief Subject role of the Observer pattern.
 *
 * Observer pointers are non-owning. The subject only manages registration.
 */
class Subject {
protected:
    std::vector<Observer*> observers;
public:
    /** @brief Registers an observer once. @param observer Non-owning observer pointer. */
    virtual void attach(Observer* observer);
    /** @brief Removes an observer if registered; otherwise does nothing. @param observer Observer pointer. */
    virtual void detach(Observer* observer);
    /** @brief Pushes a notice to all currently registered observers. @param notice Notice to deliver. */
    virtual void notify(const EventNotice& notice);
    /** @brief Virtual destructor for polymorphic use. */
    virtual ~Subject() {}
};

#endif
