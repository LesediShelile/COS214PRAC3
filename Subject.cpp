#include "Subject.h"
#include "Observer.h"
#include "EventNotice.h"
#include <algorithm>

void Subject::attach(Observer* observer) {
    if (observer != 0 && std::find(observers.begin(), observers.end(), observer) == observers.end())
        observers.push_back(observer);
}

void Subject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const EventNotice& notice) {
    std::vector<Observer*> current = observers;
    for (std::vector<Observer*>::iterator it = current.begin(); it != current.end(); ++it)
        (*it)->update(notice);
}
