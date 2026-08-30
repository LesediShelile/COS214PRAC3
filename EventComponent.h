#ifndef EVENTCOMPONENT_H
#define EVENTCOMPONENT_H

#include <string>

// Component role of the Composite pattern. Every piece of the convention
// (a whole hall, an area, or a single operational unit) is an EventComponent
// so the tree can be built and traversed uniformly.
class EventComponent {
    protected:
        std::string name;

    public:
        EventComponent(const std::string& name);
        virtual ~EventComponent() {}

        // Default (no-op) child-management so leaves don't need to override
        // these; EventGroup overrides them with real behaviour.
        virtual void add(EventComponent* component);
        virtual void remove(EventComponent* component);

        virtual void display(int depth = 0) const;
        std::string getName() const;
};

#endif
