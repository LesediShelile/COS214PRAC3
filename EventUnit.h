#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"

/**
 * @brief Leaf role of the Composite pattern and Observer participant.
 *
 * Each concrete EventUnit implements update() and may override action hooks to
 * provide responsibility-specific behaviour without type checks.
 */
class EventUnit : public EventComponent {
protected:
    /**
     * @brief Maximum capacity of this event unit.
     */
    int capacity;

public:
    /** @brief Constructs an event unit. @param name Unit name. @param capacity Unit capacity. */
    EventUnit(const std::string& name, int capacity);
    /** @brief Virtual destructor for safe polymorphic destruction. */
    virtual ~EventUnit() {}
    /** @brief Opens this unit. */
    void open() override;
    /** @brief Closes this unit. */
    void close() override;
    /** @brief Reports this unit's status. */
    void reportStatus() const override;
    /** @brief Returns this unit's capacity. @return Unit capacity. */
    int getCapacity() const override;
    /** @brief Displays this unit. @param depth Indentation depth. */
    void display(int depth = 0) const override;
    /** @brief Receives a pushed notice. @param notice Notice received from a Subject. */
    void update(const EventNotice& notice) override = 0;
    /** @brief Handles a safety alert. */ virtual void onSafetyAlert();
    /** @brief Handles a capacity alert. */ virtual void onCapacityAlert();
    /** @brief Handles a server outage. */ virtual void onServerOutage();
    /** @brief Handles an evacuation instruction. */ virtual void onEvacuate();
    /** @brief Handles a schedule change. */ virtual void onScheduleChange();
    /** @brief Handles an area opening. */ virtual void onOpenArea();
    /** @brief Handles an area closing. */ virtual void onCloseArea();
    /** @brief Handles a weather alert. */ virtual void onWeatherAlert();
    /** @brief Handles a temporary pause. */ virtual void onTemporaryPause();
    /** @brief Handles a resume instruction. */ virtual void onResume();
};

#endif
