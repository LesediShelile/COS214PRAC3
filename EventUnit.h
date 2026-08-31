#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

/**
 * @brief Leaf role of the Composite and Observer patterns.
 *
 * Each concrete EventUnit implements update() and may override event-action
 * hooks to provide responsibility-specific behaviour without type checks.
 */
class EventUnit : public EventComponent {
protected:
    int capacity;

public:
    EventUnit(const std::string& name, int capacity);
    virtual ~EventUnit() {}

    void open() override;
    void close() override;
    void reportStatus() const override;
    int getCapacity() const override;
    void display(int depth = 0) const override;

    void update(const EventNotice& notice) override = 0;

    virtual void onSafetyAlert();
    virtual void onCapacityAlert();
    virtual void onServerOutage();
    virtual void onEvacuate();
    virtual void onScheduleChange();
    virtual void onOpenArea();
    virtual void onCloseArea();
    virtual void onWeatherAlert();
    virtual void onTemporaryPause();
    virtual void onResume();
};

#endif
