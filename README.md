# GameVerse EventFlow

## COS 214 Practical 3

GameVerse EventFlow is a C++11 live gaming convention coordination system that uses the Gang of Four **Composite** and **Observer** design patterns.

## Event Concept

GameVerse is a gaming and esports convention containing nested operational areas such as esports halls, championship arenas, VR zones, registration areas, VIP spaces and support services. Individual units react differently to operational, capacity and safety notices through polymorphism.

## Team Members

- Member 1: [Name and Student Number]
- Member 2: [Name and Student Number]
- Member 3: [Name and Student Number]

## Build and Run

```bash
make
./eventflow
```

Or:

```bash
make run
```

Clean build files with:

```bash
make clean
```

## Architecture Overview

### Composite

`EventComponent` is the common Component interface. `EventUnit` represents a Leaf and `EventGroup` represents a Composite. Groups may contain both leaves and other groups, allowing the event to form a genuine part-whole tree.

`EventGroup` **owns** every pointer in its `children` collection. Adding a component transfers ownership to the group. Deleting the root recursively destroys the complete owned subtree exactly once because every group deletes only its direct children.

`takeChild()` removes a child without deleting it and transfers ownership to the caller. The caller must either add the component to another `EventGroup` or delete it. This prevents double deletion during runtime reorganisation.

### Observer

`Subject` stores **non-owning** `Observer*` registrations. A Subject never deletes its observers. Duplicate registrations are ignored and detaching an observer that is not registered has no effect. Notifications use the push approach: `update(const EventNotice&)`.

`EventGroup` participates in both patterns: it is a Composite for ownership and structure, while also acting as an Observer and Subject to support cascading notifications through multiple runtime levels.

## Notices

The system supports operational, capacity and safety-related notices including safety alerts, capacity alerts, server outages, evacuation instructions, schedule changes, area opening and closing, weather alerts, temporary pauses and resume notices.

## Doxygen

Generate documentation with:

```bash
doxygen Doxyfile
```

Generated HTML documentation is written to:

```text
docs/doxygen/html/
```

Open `docs/doxygen/html/index.html` in a browser.

The code documents public classes and public operations, including parameters, return values and ownership/lifetime expectations for raw pointers.
