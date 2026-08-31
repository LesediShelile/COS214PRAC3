#ifndef ANNOUNCEMENTBOARD_H
#define ANNOUNCEMENTBOARD_H

#include "Observer.h"

/**
 * @brief Concrete Observer that turns event notices into attendee-facing announcements.
 *
 * AnnouncementBoard reacts to the same notices as any other Observer (for
 * example SecurityTeam), but produces a different kind of response: instead
 * of performing an operational action, it converts the notice into a
 * message attendees can read. This demonstrates how different observers can
 * react differently to the same notification.
 */
class AnnouncementBoard : public Observer {
public:
    /** @brief Constructs an announcement board. */
    AnnouncementBoard();

    /**
     * @brief Converts a pushed notice into an attendee-facing announcement.
     * @param notice Notice received from a Subject.
     */
    void update(const EventNotice& notice) override;
};

#endif
