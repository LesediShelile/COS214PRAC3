#ifndef EVENTNOTICE_H
#define EVENTNOTICE_H

#include <string>

class EventUnit;

/**
 * @brief Abstract push-notification payload used by EventFlow.
 *
 * Concrete notices use polymorphism to deliver the appropriate event action
 * without requiring controllers or observers to inspect a notice type.
 */
class EventNotice {
protected:
    std::string message;

public:
    explicit EventNotice(const std::string& message = "");
    virtual ~EventNotice() {}

    /** @return Name of this notice type. */
    virtual std::string getType() const = 0;

    /** @return Human-readable notice message. */
    std::string getMessage() const;

    /** @brief Dispatches this notice to the appropriate EventUnit behaviour. */
    virtual void dispatch(EventUnit& unit) const = 0;
};

class SafetyAlertNotice : public EventNotice {
public:
    explicit SafetyAlertNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class CapacityAlertNotice : public EventNotice {
public:
    explicit CapacityAlertNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class ServerOutageNotice : public EventNotice {
public:
    explicit ServerOutageNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class EvacuateNotice : public EventNotice {
public:
    explicit EvacuateNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class ScheduleChangeNotice : public EventNotice {
public:
    explicit ScheduleChangeNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class OpenAreaNotice : public EventNotice {
public:
    explicit OpenAreaNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class CloseAreaNotice : public EventNotice {
public:
    explicit CloseAreaNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class WeatherAlertNotice : public EventNotice {
public:
    explicit WeatherAlertNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class TemporaryPauseNotice : public EventNotice {
public:
    explicit TemporaryPauseNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

class ResumeNotice : public EventNotice {
public:
    explicit ResumeNotice(const std::string& message = "");
    std::string getType() const override;
    void dispatch(EventUnit& unit) const override;
};

#endif
