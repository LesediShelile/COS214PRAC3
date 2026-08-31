#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"
#include "EventNotice.h"
#include <memory>

/**
 * @brief Concrete Subject responsible for issuing event notices.
 *
 * EventControl owns the current notice. Observers are non-owning references
 * managed by Subject.
 */
class EventControl : public Subject {
private:
    std::unique_ptr<EventNotice> currentNotice;

public:
    EventControl();

    /**
     * @brief Issues a notice and transfers ownership to EventControl.
     * @param notice Dynamically allocated notice. Ownership transfers here.
     */
    void issueNotice(EventNotice* notice);

    /** @return The most recently issued notice. */
    const EventNotice& getCurrentNotice() const;
};

#endif
