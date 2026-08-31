#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>
#include "Observer.h"

/**
 * @brief Common Component abstraction in the Composite pattern.
 *
 * Clients can use this interface to operate uniformly on individual event
 * units and nested event groups. It also participates as an Observer.
 */
class EventComponent : public Observer {
protected:
    /**
     * @brief Name of this event component.
     */
    std::string name;

    /**
     * @brief Indicates whether this component is currently open.
     */
    bool openState;

public:
    /** @brief Constructs a component. @param name Human-readable component name. */
    explicit EventComponent(const std::string& name);
    /** @brief Virtual destructor for safe polymorphic destruction. */
    virtual ~EventComponent() {}
    /** @brief Opens this component. */
    virtual void open();
    /** @brief Closes this component. */
    virtual void close();
    /** @brief Reports the current component status. */
    virtual void reportStatus() const;
    /** @brief Returns the represented capacity. @return Component capacity. */
    virtual int getCapacity() const;
    /** @brief Displays this component. @param depth Indentation depth. */
    virtual void display(int depth = 0) const;
    /** @brief Returns the component name. @return Human-readable name. */
    std::string getName() const;
};

#endif
