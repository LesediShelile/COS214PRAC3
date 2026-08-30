#include "Subject.h"
#include "Observer.h"
#include <algorithm>

void Subject::attach(Observer* observer) {
    if (observer != nullptr) {
        observers.push_back(observer);
    }
}

void Subject::detach(Observer* observer) {
    observers.erase(std::remove(observers.begin(), observers.end(), observer), observers.end());
}

void Subject::notify(const EventNotice& notice) {
    for (Observer* observer : observers) {
        observer->update(notice);
    }
}
