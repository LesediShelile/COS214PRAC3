#ifndef EVENTUNIT_H
#define EVENTUNIT_H

#include "EventComponent.h"
#include "Observer.h"

/**
 * @brief Leaf role of the Composite and Observer patterns.
 *
 * EventUnit represents an individual operational unit and reacts to notices
 * through its polymorphic update() implementation.
 */
class EventUnit : public EventComponent, public Observer {
    protected:
        int capacity;

    public:
        /**
         * @brief Constructs an operational unit.
         * @param name Unit name.
         * @param capacity Maximum number represented by the unit.
         */
        EventUnit(const std::string& name, int capacity);
        virtual ~EventUnit() {}

        void open() override;
        void close() override;
        void reportStatus() const override;
        int getCapacity() const override;

        /** @brief Reacts to a notice using the concrete unit's policy. */
        void update(const EventNotice& notice) override = 0;
};

#endif
