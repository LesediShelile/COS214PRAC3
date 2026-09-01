#include "Subject.h"
#include "Observer.h"
#include "EventNotice.h"
#include <algorithm>

void Subject::attach(Observer* observer) {
    if (observer == 0) return;
    if (std::find(observers.begin(), observers.end(), observer) == observers.end()) {
        observers.push_back(observer);
    }
}

void Subject::detach(Observer* observer) {
    std::vector<Observer*>::iterator it =
        std::find(observers.begin(), observers.end(), observer);
    if (it != observers.end()) observers.erase(it);
}

void Subject::notify(const EventNotice& notice) {
    // Snapshot policy: registration changes during notification affect the
    // next notification, not the current iteration.
    std::vector<Observer*> current = observers;
    for (std::vector<Observer*>::iterator it = current.begin(); it != current.end(); ++it) {
        if (*it != 0) (*it)->update(notice);
    }
}
