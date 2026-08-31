#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Observer.h"
#include "Subject.h"
#include <vector>

/**
 * @brief Composite node representing an operational area of GameVerse.
 *
 * An EventGroup owns its child EventComponents. It is also an Observer of its
 * parent and a Subject for interested descendants, allowing notifications to
 * cascade through the Composite tree.
 */
class EventGroup : public EventComponent, public Subject {
    protected:
        std::vector<EventComponent*> children;

    public:
        /** @param name Name of the area represented by this group. */
        EventGroup(const std::string& name);


        virtual ~EventGroup();

        /**
         * @brief Adds and owns a component.
         * @param component Non-null component whose ownership transfers here.
         */
        void add(EventComponent* component) ;

        /**
         * @brief Removes a direct child without deleting it.
         * @param component Child to remove; ownership transfers to the caller.
         */
        void remove(EventComponent* component);

        /** @brief Removes and returns a child without deleting it. @param childName Name of the child. @return Detached child, or null if not found. */
        EventComponent* takeChild(const std::string& childName);

        /** @brief Finds a nested group by name. @param groupName Group name. @return Matching group, or null. */
        EventGroup* findGroup(const std::string& groupName);

    
        /** @brief Displays this group and its complete subtree. */
        void display(int depth = 0)const override;
        /** @brief Opens this group and all owned descendants. */
        void open() override;
        /** @brief Closes this group and all owned descendants. */
        void close() override;
        /** @brief Reports aggregate state and capacity. */
        void reportStatus() const override;
        /** @return Sum of capacities of all descendants. */
        int getCapacity() const override;

        /** @brief Receives a notice from above and cascades it below. */
        void update(const EventNotice& notice) override;
};

#endif
