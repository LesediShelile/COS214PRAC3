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
    /** @brief Constructs the event controller. */
    EventControl();

    /**
     * @brief Issues a notice and transfers ownership to EventControl.
     * @param notice Dynamically allocated notice. Ownership transfers here; the caller must not delete it afterwards.
     */
    void issueNotice(EventNotice* notice);

    /**
     * @brief Returns the most recently issued notice.
     * @return Reference valid until the stored notice is replaced or EventControl is destroyed.
     */
    const EventNotice& getCurrentNotice() const;
};

#endif
