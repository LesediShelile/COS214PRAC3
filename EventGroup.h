#ifndef EVENTGROUP_H
#define EVENTGROUP_H

#include "EventComponent.h"
#include "Subject.h"
#include <vector>

/**
 * @brief Concrete Composite that owns nested event components.
 *
 * EventGroup is also an Observer and Subject: it receives a notice from
 * above and re-broadcasts it to registered children.
 *
 * Ownership: add() transfers ownership to the group. remove() transfers
 * ownership out without deleting the component. Observer references are
 * non-owning and are automatically detached when a child is removed.
 */
class EventGroup : public EventComponent, public Subject {
private:
    std::vector<EventComponent*> children;
public:
    /** @brief Constructs a group. @param name Group name. */
    EventGroup(const std::string& name);
    /** @brief Destroys the group and its owned subtree exactly once. */
    virtual ~EventGroup();
    /** @brief Takes ownership of a child and registers it as an Observer. @param component Child to own. */
    void add(EventComponent* component);
    /** @brief Removes a child and transfers ownership to the caller. @param component Child to remove. */
    void remove(EventComponent* component);
    /** @brief Opens this group and all descendants. */
    void open() override;
    /** @brief Closes this group and all descendants. */
    void close() override;
    /** @brief Reports this group's status and recursively reports children. */
    void reportStatus() const override;
    /** @brief Returns aggregate capacity of all descendants. @return Total capacity. */
    int getCapacity() const override;
    /** @brief Receives and cascades a notice to registered children. @param notice Notice to relay. */
    void update(const EventNotice& notice) override;
};

#endif
