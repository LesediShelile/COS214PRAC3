#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

// The set of notifications EventControl can broadcast through the convention.
enum class NoticeType {
    OPEN_AREA,
    CLOSE_AREA,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    SERVER_OUTAGE,
    SAFETY_ALERT,
    TEMPORARY_PAUSE,
    EVACUATE
};

// EventNotice is the payload passed from Subject -> Observer::update().
// It carries what happened and an optional human-readable detail message.
class EventNotice {
    private:
        NoticeType type;
        std::string message;

    public:
        EventNotice(NoticeType type, const std::string& message = "");

        NoticeType getType() const;
        std::string getMessage() const;
        std::string getTypeName() const;
};

#endif
