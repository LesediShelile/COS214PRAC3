#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"
#include "EventNotice.h"
#include <memory>
#include <string>

// ConcreteSubject. EventControl is the central controller for the
// convention: it holds the current event notice/state and notifies its
// observers whenever a new one is issued. It knows nothing about the
// composite tree it broadcasts into - that's attached from outside by
// the Client (main.cpp).
class EventControl : public Subject {
    private:
        std::unique_ptr<EventNotice> currentNotice;

    public:
        EventControl();

        void issueNotice(NoticeType type, const std::string& message = "");
        const EventNotice& getCurrentNotice() const;
};

#endif
