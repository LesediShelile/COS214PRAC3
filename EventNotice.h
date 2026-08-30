#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

enum class NoticeType {
    OPEN_AREA,
    CLOSE_AREA,
    SCHEDULE_CHANGE,
    CAPACITY_ALERT,
    SERVER_OUTAGE,
    WEATHER_ALERT,
    EVACUATE,
    RESUME
};

/**
 * @brief Immutable information pushed from a Subject to its Observers.
 */
class EventNotice {
private:
    NoticeType type;
    std::string message;
public:
    /** @brief Creates a notice. @param type Notice category. @param message Additional detail. */
    EventNotice(NoticeType type, const std::string& message = "");
    /** @brief Returns the notice category. @return Notice category. */
    NoticeType getType() const;
    /** @brief Returns the notice detail. @return Notice message. */
    std::string getMessage() const;
    /** @brief Returns a printable name for the category. @return Notice name. */
    std::string getTypeName() const;
};

#endif
