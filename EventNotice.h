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
  public:
  /**
   * @brief Severity level assigned to an event notice.
   *
   * Severity lets different observers scale their reaction to how serious
   * a situation is, instead of responding identically to every notice of
   * the same type.
   */
  enum class Severity {
      LOW,
      MEDIUM,
      HIGH
  };

  protected:
  /**

  * @brief Message describing the event notice.
    */
    std::string message;

  /**
   * @brief Severity level assigned to this notice.
   */
    Severity severity;

public:
/**
* @brief Constructs an event notice.
*
* @param message Message describing the notice.
* @param severity Severity level assigned to the notice.
*/
explicit EventNotice(const std::string& message = "", Severity severity = Severity::MEDIUM);


/**
 * @brief Virtual destructor for safe polymorphic destruction.
 */
virtual ~EventNotice() {}

/**
 * @brief Returns the name of this notice type.
 *
 * @return Name of the notice type.
 */
virtual std::string getType() const = 0;

/**
 * @brief Returns the human-readable notice message.
 *
 * @return The notice message.
 */
std::string getMessage() const;

/**
 * @brief Returns the severity level assigned to this notice.
 *
 * @return LOW, MEDIUM, or HIGH.
 */
Severity getSeverity() const;

/**
 * @brief Dispatches this notice to the appropriate EventUnit behaviour.
 *
 * @param unit Event unit receiving the notice.
 */
virtual void dispatch(EventUnit& unit) const = 0;


};

/**
 * @brief Returns a human-readable name for a severity level.
 *
 * @param severity Severity level to render.
 * @return "LOW", "MEDIUM", or "HIGH".
 */
std::string severityToString(EventNotice::Severity severity);

/**

* @brief Concrete event notice representing a safety alert.
*
* Defaults to HIGH severity, since an unspecified safety alert is treated
* as serious until stated otherwise.
  */
  class SafetyAlertNotice : public EventNotice {
  public:
  /**

  * @brief Constructs a safety alert notice.
  *
  * @param message Message describing the safety alert.
  * @param severity Severity level; defaults to HIGH.
    */
    explicit SafetyAlertNotice(const std::string& message = "", Severity severity = Severity::HIGH);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the safety alert to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing a capacity alert.
  */
  class CapacityAlertNotice : public EventNotice {
  public:
  /**

  * @brief Constructs a capacity alert notice.
  *
  * @param message Message describing the capacity alert.
    */
    explicit CapacityAlertNotice(const std::string& message = "", Severity severity = Severity::MEDIUM);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the capacity alert to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing a server outage.
  */
  class ServerOutageNotice : public EventNotice {
  public:
  /**

  * @brief Constructs a server outage notice.
  *
  * @param message Message describing the server outage.
    */
    explicit ServerOutageNotice(const std::string& message = "", Severity severity = Severity::HIGH);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the server outage notice to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing an evacuation.
  */
  class EvacuateNotice : public EventNotice {
  public:
  /**

  * @brief Constructs an evacuation notice.
  *
  * @param message Message describing the evacuation instruction.
    */
    explicit EvacuateNotice(const std::string& message = "", Severity severity = Severity::HIGH);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the evacuation notice to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing a schedule change.
  */
  class ScheduleChangeNotice : public EventNotice {
  public:
  /**

  * @brief Constructs a schedule change notice.
  *
  * @param message Message describing the schedule change.
    */
    explicit ScheduleChangeNotice(const std::string& message = "", Severity severity = Severity::LOW);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the schedule change notice to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing an area opening.
  */
  class OpenAreaNotice : public EventNotice {
  public:
  /**

  * @brief Constructs an area opening notice.
  *
  * @param message Message describing the area opening.
    */
    explicit OpenAreaNotice(const std::string& message = "", Severity severity = Severity::LOW);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the area opening notice to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing an area closing.
  */
  class CloseAreaNotice : public EventNotice {
  public:
  /**

  * @brief Constructs an area closing notice.
  *
  * @param message Message describing the area closing.
    */
    explicit CloseAreaNotice(const std::string& message = "", Severity severity = Severity::LOW);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the area closing notice to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing a weather alert.
  */
  class WeatherAlertNotice : public EventNotice {
  public:
  /**

  * @brief Constructs a weather alert notice.
  *
  * @param message Message describing the weather alert.
    */
    explicit WeatherAlertNotice(const std::string& message = "", Severity severity = Severity::MEDIUM);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the weather alert to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing a temporary pause.
  */
  class TemporaryPauseNotice : public EventNotice {
  public:
  /**

  * @brief Constructs a temporary pause notice.
  *
  * @param message Message describing the temporary pause.
    */
    explicit TemporaryPauseNotice(const std::string& message = "", Severity severity = Severity::MEDIUM);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the temporary pause notice to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

/**

* @brief Concrete event notice representing the resumption of operations.
  */
  class ResumeNotice : public EventNotice {
  public:
  /**

  * @brief Constructs a resume notice.
  *
  * @param message Message describing the resumption of operations.
    */
    explicit ResumeNotice(const std::string& message = "", Severity severity = Severity::LOW);

  /**

  * @brief Returns the name of this notice type.
  *
  * @return The notice type name.
    */
    std::string getType() const override;

  /**

  * @brief Dispatches the resume notice to an event unit.
  *
  * @param unit Event unit receiving the notice.
    */
    void dispatch(EventUnit& unit) const override;
    };

#endif
