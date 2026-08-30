#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include "Observer.h"
#include <string>

/**
 * @brief Common Component abstraction for the Composite pattern.
 *
 * Every event component is also an Observer so that a composite can relay
 * notices to its contained components without type checks.
 */
class EventComponent : public Observer {
protected:
    std::string name;
    bool openState;
    int capacity;
public:
    /** @brief Constructs a component. @param name Display name. @param capacity Component capacity. */
    EventComponent(const std::string& name, int capacity);
    /** @brief Opens this component. */
    virtual void open();
    /** @brief Closes this component. */
    virtual void close();
    /** @brief Reports this component's current status. */
    virtual void reportStatus() const;
    /** @brief Returns this component's capacity. @return Capacity value. */
    virtual int getCapacity() const;
    /** @brief Returns the component name. @return Name. */
    std::string getName() const;
    /** @brief Virtual destructor for the Composite hierarchy. */
    virtual ~EventComponent() {}
};

#endif
