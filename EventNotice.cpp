#include "EventNotice.h"
#include "EventUnit.h"

/**
 * @brief Constructs an event notice.
 *
 * @param message Message describing the notice.
 * @param severity Severity level assigned to the notice.
 */
EventNotice::EventNotice(const std::string& message, Severity severity)
    : message(message), severity(severity) {
}

/**
 * @brief Returns the notice message.
 *
 * @return The human-readable notice message.
 */
std::string EventNotice::getMessage() const {
    return message;
}

/**
 * @brief Returns the severity level assigned to this notice.
 *
 * @return LOW, MEDIUM, or HIGH.
 */
EventNotice::Severity EventNotice::getSeverity() const {
    return severity;
}

/**
 * @brief Returns a human-readable name for a severity level.
 *
 * @param severity Severity level to render.
 * @return "LOW", "MEDIUM", or "HIGH".
 */
std::string severityToString(EventNotice::Severity severity) {
    switch (severity) {
        case EventNotice::Severity::LOW:    return "LOW";
        case EventNotice::Severity::MEDIUM: return "MEDIUM";
        case EventNotice::Severity::HIGH:   return "HIGH";
    }
    return "UNKNOWN";
}

/* ==================== SafetyAlertNotice ==================== */

SafetyAlertNotice::SafetyAlertNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string SafetyAlertNotice::getType() const {
    return "SAFETY_ALERT";
}

void SafetyAlertNotice::dispatch(EventUnit& unit) const {
    unit.onSafetyAlert();
}

/* ==================== CapacityAlertNotice ==================== */

CapacityAlertNotice::CapacityAlertNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string CapacityAlertNotice::getType() const {
    return "CAPACITY_ALERT";
}

void CapacityAlertNotice::dispatch(EventUnit& unit) const {
    unit.onCapacityAlert();
}

/* ==================== ServerOutageNotice ==================== */

ServerOutageNotice::ServerOutageNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string ServerOutageNotice::getType() const {
    return "SERVER_OUTAGE";
}

void ServerOutageNotice::dispatch(EventUnit& unit) const {
    unit.onServerOutage();
}

/* ==================== EvacuateNotice ==================== */

EvacuateNotice::EvacuateNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string EvacuateNotice::getType() const {
    return "EVACUATE";
}

void EvacuateNotice::dispatch(EventUnit& unit) const {
    unit.onEvacuate();
}

/* ==================== ScheduleChangeNotice ==================== */

ScheduleChangeNotice::ScheduleChangeNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string ScheduleChangeNotice::getType() const {
    return "SCHEDULE_CHANGE";
}

void ScheduleChangeNotice::dispatch(EventUnit& unit) const {
    unit.onScheduleChange();
}

/* ==================== OpenAreaNotice ==================== */

OpenAreaNotice::OpenAreaNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string OpenAreaNotice::getType() const {
    return "OPEN_AREA";
}

void OpenAreaNotice::dispatch(EventUnit& unit) const {
    unit.onOpenArea();
}

/* ==================== CloseAreaNotice ==================== */

CloseAreaNotice::CloseAreaNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string CloseAreaNotice::getType() const {
    return "CLOSE_AREA";
}

void CloseAreaNotice::dispatch(EventUnit& unit) const {
    unit.onCloseArea();
}

/* ==================== WeatherAlertNotice ==================== */

WeatherAlertNotice::WeatherAlertNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string WeatherAlertNotice::getType() const {
    return "WEATHER_ALERT";
}

void WeatherAlertNotice::dispatch(EventUnit& unit) const {
    unit.onWeatherAlert();
}

/* ==================== TemporaryPauseNotice ==================== */

TemporaryPauseNotice::TemporaryPauseNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string TemporaryPauseNotice::getType() const {
    return "TEMPORARY_PAUSE";
}

void TemporaryPauseNotice::dispatch(EventUnit& unit) const {
    unit.onTemporaryPause();
}

/* ==================== ResumeNotice ==================== */

ResumeNotice::ResumeNotice(const std::string& message, Severity severity)
    : EventNotice(message, severity) {
}

std::string ResumeNotice::getType() const {
    return "RESUME";
}

void ResumeNotice::dispatch(EventUnit& unit) const {
    unit.onResume();
}