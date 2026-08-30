#ifndef EVENTCONTROL_H
#define EVENTCONTROL_H

#include "Subject.h"
#include "EventNotice.h"
#include <memory>
#include <string>

/**
 * @brief Concrete Subject representing GameVerse's central control centre.
 */
class EventControl : public Subject {
private:
    std::unique_ptr<EventNotice> currentNotice;
public:
    /** @brief Creates the control centre. */
    EventControl();
    /** @brief Creates and pushes a notice to registered observers. @param type Notice type. @param message Detail. */
    void issueNotice(NoticeType type, const std::string& message = "");
    /** @brief Returns the latest notice. @return Current notice. */
    const EventNotice& getCurrentNotice() const;
};

#endif
