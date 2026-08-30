#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

/**
 * @brief Leaf base class in the Composite pattern.
 *
 * A leaf cannot contain other EventComponents and provides its own
 * polymorphic reaction to notices.
 */
class EventUnit : public EventComponent {
public:
    /** @brief Constructs a leaf event unit. @param name Unit name. @param capacity Unit capacity. */
    EventUnit(const std::string& name, int capacity);
    /** @brief Virtual destructor for polymorphic destruction. */
    virtual ~EventUnit() {}
};

#endif
