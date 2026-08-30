#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"
#include "Observer.h"

// Leaf role of the Composite pattern, and Observer role of the Observer
// pattern. A single operational unit (e.g. Check-In Desk, Security Team)
// cannot contain other components, but it does react to EventNotices by
// implementing its own update().
class EventUnit : public EventComponent, public Observer {
    public:
        EventUnit(const std::string& name);
        virtual ~EventUnit() {}

        // Still abstract here: every concrete unit defines its own reaction.
        void update(const EventNotice& notice) override = 0;
};

#endif
