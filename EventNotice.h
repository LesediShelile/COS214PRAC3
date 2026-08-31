#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>



/** * @brief Payload passed from a Subject to its Observers. * * EventNotice encapsulates information about an event without exposing * its internal representation. */
class EventNotice {
    private:
        std::string type;
        std::string message;

    public:
    /** * @param type Type of notification. * @param message Optional human-readable description. */
        EventNotice(const std::string& type, const std::string& message = "");
    /** * @return Type of notification. */
        std::string getType() const;
        /** * @return Human-readable notification message. */
        std::string getMessage() const;

};

#endif
