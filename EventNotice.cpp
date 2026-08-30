#include "EventNotice.h"

EventNotice::EventNotice(NoticeType type, const std::string& message) : type(type), message(message) {}
NoticeType EventNotice::getType() const { return type; }
std::string EventNotice::getMessage() const { return message; }
std::string EventNotice::getTypeName() const {
    switch (type) {
        case NoticeType::OPEN_AREA: return "OPEN_AREA";
        case NoticeType::CLOSE_AREA: return "CLOSE_AREA";
        case NoticeType::SCHEDULE_CHANGE: return "SCHEDULE_CHANGE";
        case NoticeType::CAPACITY_ALERT: return "CAPACITY_ALERT";
        case NoticeType::SERVER_OUTAGE: return "SERVER_OUTAGE";
        case NoticeType::WEATHER_ALERT: return "WEATHER_ALERT";
        case NoticeType::EVACUATE: return "EVACUATE";
        case NoticeType::RESUME: return "RESUME";
    }
    return "UNKNOWN";
}
