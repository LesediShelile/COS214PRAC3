#include "EventNotice.h"
#include "EventUnit.h"

/**
 * @brief Constructs an event notice.
 *
 * @param message Message describing the notice.
 */
EventNotice::EventNotice(const std::string& message)
    : message(message) {
}

/**
 * @brief Returns the notice message.
 *
 * @return The human-readable notice message.
 */
std::string EventNotice::getMessage() const {
    return message;
}

/* ==================== SafetyAlertNotice ==================== */

SafetyAlertNotice::SafetyAlertNotice(const std::string& message)
    : EventNotice(message) {
}

std::string SafetyAlertNotice::getType() const {
    return "SAFETY_ALERT";
}

void SafetyAlertNotice::dispatch(EventUnit& unit) const {
    unit.onSafetyAlert();
}

/* ==================== CapacityAlertNotice ==================== */

CapacityAlertNotice::CapacityAlertNotice(const std::string& message)
    : EventNotice(message) {
}

std::string CapacityAlertNotice::getType() const {
    return "CAPACITY_ALERT";
}

void CapacityAlertNotice::dispatch(EventUnit& unit) const {
    unit.onCapacityAlert();
}

/* ==================== ServerOutageNotice ==================== */

ServerOutageNotice::ServerOutageNotice(const std::string& message)
    : EventNotice(message) {
}

std::string ServerOutageNotice::getType() const {
    return "SERVER_OUTAGE";
}

void ServerOutageNotice::dispatch(EventUnit& unit) const {
    unit.onServerOutage();
}

/* ==================== EvacuateNotice ==================== */

EvacuateNotice::EvacuateNotice(const std::string& message)
    : EventNotice(message) {
}

std::string EvacuateNotice::getType() const {
    return "EVACUATE";
}

void EvacuateNotice::dispatch(EventUnit& unit) const {
    unit.onEvacuate();
}

/* ==================== ScheduleChangeNotice ==================== */

ScheduleChangeNotice::ScheduleChangeNotice(const std::string& message)
    : EventNotice(message) {
}

std::string ScheduleChangeNotice::getType() const {
    return "SCHEDULE_CHANGE";
}

void ScheduleChangeNotice::dispatch(EventUnit& unit) const {
    unit.onScheduleChange();
}

/* ==================== OpenAreaNotice ==================== */

OpenAreaNotice::OpenAreaNotice(const std::string& message)
    : EventNotice(message) {
}

std::string OpenAreaNotice::getType() const {
    return "OPEN_AREA";
}

void OpenAreaNotice::dispatch(EventUnit& unit) const {
    unit.onOpenArea();
}

/* ==================== CloseAreaNotice ==================== */

CloseAreaNotice::CloseAreaNotice(const std::string& message)
    : EventNotice(message) {
}

std::string CloseAreaNotice::getType() const {
    return "CLOSE_AREA";
}

void CloseAreaNotice::dispatch(EventUnit& unit) const {
    unit.onCloseArea();
}

/* ==================== WeatherAlertNotice ==================== */

WeatherAlertNotice::WeatherAlertNotice(const std::string& message)
    : EventNotice(message) {
}

std::string WeatherAlertNotice::getType() const {
    return "WEATHER_ALERT";
}

void WeatherAlertNotice::dispatch(EventUnit& unit) const {
    unit.onWeatherAlert();
}

/* ==================== TemporaryPauseNotice ==================== */

TemporaryPauseNotice::TemporaryPauseNotice(const std::string& message)
    : EventNotice(message) {
}

std::string TemporaryPauseNotice::getType() const {
    return "TEMPORARY_PAUSE";
}

void TemporaryPauseNotice::dispatch(EventUnit& unit) const {
    unit.onTemporaryPause();
}

/* ==================== ResumeNotice ==================== */

ResumeNotice::ResumeNotice(const std::string& message)
    : EventNotice(message) {
}

std::string ResumeNotice::getType() const {
    return "RESUME";
}

void ResumeNotice::dispatch(EventUnit& unit) const {
    unit.onResume();
}