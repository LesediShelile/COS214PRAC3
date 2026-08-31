#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>
#include "Observer.h"

class EventComponent : public Observer {
protected:
    std::string name;
    bool openState;

public:
    explicit EventComponent(const std::string& name);
    virtual ~EventComponent() {}

    virtual void open();
    virtual void close();
    virtual void reportStatus() const;
    virtual int getCapacity() const;
    virtual void display(int depth = 0) const;
    std::string getName() const;
};

#endif
