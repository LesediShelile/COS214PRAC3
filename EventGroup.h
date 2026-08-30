#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"
#include <vector>

// EventGroup plays three roles at once:
//   - Composite (EventComponent): it contains other EventComponents
//     (both sub-groups and leaf EventUnits).
//   - Observer: it can be notified by a parent EventGroup or by EventControl.
//   - Subject: once notified, it re-broadcasts the same notice to whichever
//     of its own children are Observers, letting the notification cascade
//     down the tree without EventControl needing to know the tree's shape.
class EventGroup : public EventComponent, public Observer, public Subject {
    protected:
        std::vector<EventComponent*> children;

    public:
        EventGroup(const std::string& name);
        // A composite owns whatever was add()'ed to it, so it is responsible
        // for cleaning those components up.
        virtual ~EventGroup();

        void add(EventComponent* component) override;
        void remove(EventComponent* component) override;
        void display(int depth = 0) const override;

        // Receives a notice from above, then cascades it to children.
        void update(const EventNotice& notice) override;
};

#endif
