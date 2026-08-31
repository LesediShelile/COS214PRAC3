#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

/**
 * @brief Common Component interface for the GameVerse Composite tree.
 *
 * Every event area and operational unit can be opened, closed, queried for
 * status and queried for capacity through this interface.
 */
class EventComponent {
    protected:
        std::string name;
        bool openState;

    public:
        /** @param name Display name of this event component. */
        EventComponent(const std::string& name);
        virtual ~EventComponent() {}

        /** @brief Opens this component. */
        virtual void open();
        /** @brief Closes this component. */
        virtual void close();
        /** @brief Reports the current state of this component. */
        virtual void reportStatus() const;
        /** @return Capacity represented by this component. */
        virtual int getCapacity() const;
        /** @brief Displays this component and, for composites, its subtree. */
        virtual void display(int depth = 0) const;
        /** @return Component name. */
        std::string getName() const;
};

#endif
