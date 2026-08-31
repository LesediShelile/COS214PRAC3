#include "EventNotice.h"

EventNotice::EventNotice(const std::string& type,
                         const std::string& message)
    : type(type), message(message)
{
}

std::string EventNotice::getType() const
{
    return type;
}

std::string EventNotice::getMessage() const
{
    return message;
}