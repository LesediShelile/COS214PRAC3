#include "EventNotice.h"
#include "EventUnit.h"

EventNotice::EventNotice(const std::string& message) : message(message) {}
std::string EventNotice::getMessage() const { return message; }

#define NOTICE_IMPL(ClassName, DisplayName, Handler) \
ClassName::ClassName(const std::string& message) : EventNotice(message) {} \
std::string ClassName::getType() const { return DisplayName; } \
void ClassName::dispatch(EventUnit& unit) const { unit.Handler(); }

NOTICE_IMPL(SafetyAlertNotice, "SAFETY_ALERT", onSafetyAlert)
NOTICE_IMPL(CapacityAlertNotice, "CAPACITY_ALERT", onCapacityAlert)
NOTICE_IMPL(ServerOutageNotice, "SERVER_OUTAGE", onServerOutage)
NOTICE_IMPL(EvacuateNotice, "EVACUATE", onEvacuate)
NOTICE_IMPL(ScheduleChangeNotice, "SCHEDULE_CHANGE", onScheduleChange)
NOTICE_IMPL(OpenAreaNotice, "OPEN_AREA", onOpenArea)
NOTICE_IMPL(CloseAreaNotice, "CLOSE_AREA", onCloseArea)
NOTICE_IMPL(WeatherAlertNotice, "WEATHER_ALERT", onWeatherAlert)
NOTICE_IMPL(TemporaryPauseNotice, "TEMPORARY_PAUSE", onTemporaryPause)
NOTICE_IMPL(ResumeNotice, "RESUME", onResume)

#undef NOTICE_IMPL
