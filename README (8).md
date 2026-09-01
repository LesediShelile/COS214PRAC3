# GameVerse Convention — EventFlow

A live-event coordination engine built for COS214 Practical 3, modelling a
multi-day gaming/esports convention using the **Composite** and **Observer**
design patterns.

## Event Concept

GameVerse Convention is a gaming and esports convention spread across four
top-level areas:

- **Operations Area** — Registration Centre, Security Operations, Medical
- **Esports Hall** — Championship Arena, Practice Area
- **Experience Hall** — VR Zone, Demo Zone
- **VIP Creator Lounge** — VIP Services, Creator Lounge

Each area recursively contains further sub-areas or individual operational
units (staff desks, teams, stations, stages), all treated uniformly through
a shared `EventComponent` interface (Composite pattern). A central
`EventControl` coordinator broadcasts notices — `OPEN_AREA`, `CLOSE_AREA`,
`SCHEDULE_CHANGE`, `CAPACITY_ALERT`, `SERVER_OUTAGE`, `SAFETY_ALERT`,
`TEMPORARY_PAUSE`, `EVACUATE` — which cascade down through the tree via the
Observer pattern, with each concrete unit reacting differently and
polymorphically to the same notice.

## Team

| Name | Student Number | Role |

| Lesedi Shelile |u25110455 | Composite structure — Tasks 1.1, 1.2, 2, 4.1, 4.2 |
| Kiara Jodhaparsadh |u25395344 | Observer system — Tasks 1.3, 1.4, 3, 4.3, 4.4 |
| Ajba | u25316584 | Sequence diagrams, integration — Tasks 5, 7, 8 |

## Building and Running

Requires a C++11-compatible compiler (g++) and GNU Make.

```bash
make
./gameverse
```

`make clean` removes build artefacts.

## Documentation

Class-level and public-operation documentation is written with Doxygen.
To generate browsable HTML docs from the repository root:

```bash
doxygen Doxyfile
```

This produces an `html/` directory — open `html/index.html` in a browser.

## Architecture Overview

- **`EventComponent`** — abstract Composite component interface.
- **`EventGroup`** — Composite: an area containing children (other
  `EventGroup`s or `EventUnit`s). Also acts as both `Observer` (registers
  with its parent) and `Subject` (notifies its own children), which is how
  a single notice cascades through multiple tree levels.
- **`EventUnit`** — Leaf: a concrete operational unit (desk, team, stage,
  gate, station). Reacts to notices via its own polymorphic `update()`
  override — no type-checking or switch-on-class anywhere in the client
  code.
- **`Subject` / `Observer`** — the Observer abstraction: `attach()`,
  `detach()`, `notify()`, `update()`.
- **`EventControl`** — the root `Subject`/coordinator that issues notices
  into the tree.
- **`EventNotice`** — the notice payload, carrying a `NoticeType` and a
  message string.

`EventGroup::add()` and `EventGroup::remove()` maintain both the Composite
ownership tree and the Observer registration list in a single call,
keeping the two collaborations consistent by construction.
