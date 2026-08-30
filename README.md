# GameVerse EventFlow - COS 214 Practical 3

GameVerse is a gaming convention coordinated using the Gang of Four Composite and Observer patterns.

## Build

The project is required to compile with C++11:

```bash
make
```

This produces the executable:

```bash
./eventflow
```

To clean build files:

```bash
make clean
```

## Doxygen

Run:

```bash
doxygen Doxyfile
```

The generated HTML documentation is placed in `docs/html/`.

## Architecture

- `EventComponent` is the common Composite Component abstraction.
- `EventGroup` is the Composite. It can contain both groups and leaves and owns its children.
- `EventUnit` is the Leaf abstraction and also an Observer.
- Concrete event-unit classes provide different polymorphic reactions to notices.
- `Subject` stores non-owning Observer references.
- `EventControl` is the concrete Subject that starts event-wide notifications.
- `EventGroup` is both an Observer and Subject so notices can cascade through nested groups.
- Observer registration is non-owning. Duplicate registration is ignored and detaching an unregistered observer has no effect.
- Runtime movement of a unit detaches it from the old group's Subject and attaches it to the new group.

## Event structure

GameVerse contains Main Operations, Esports Hall, VR & Experience Hall, and VIP & Creator Lounge. These groups contain further nested areas and operational units, providing more than three Composite levels below the root.

## Notice types

The simulation includes operational, capacity, safety, scheduling, service and evacuation notices, including `OPEN_AREA`, `CLOSE_AREA`, `SCHEDULE_CHANGE`, `CAPACITY_ALERT`, `SERVER_OUTAGE`, `SAFETY_ALERT`, `TEMPORARY_PAUSE`, and `EVACUATE`.
