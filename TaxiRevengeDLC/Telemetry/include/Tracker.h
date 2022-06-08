#pragma once 
#include "Utils/Singleton.h"
#include <string>
#include <ctime>
#include <list>
#include "Utils/uuid.h"

class ITracker;
class TrackingEvent;
class IPersistence;

class Tracker: public Singleton<Tracker>
{
private:
    static bool running;
    std::string idGame_;
    std::string idSession_;
    std::time_t mTimeStamp_;

    IPersistence* mPersistence_;
    std::list<ITracker*> mActiveTrackers_;

public:
    Tracker(/* args */) = default;
    ~Tracker() = default;

    std::string generateIDSession();

    void init(std::string IDGame);
    void end();

    void activateTracker();
    void setPersistence(IPersistence* nPersistance);

    const std::string& getIDSession() const { return idSession_; }
    const std::string& getIDGame() const { return idGame_; }
    void trackEvent(TrackingEvent* nEvent);

   inline static bool isRunning() { return running; }
};

inline Tracker* TrackerManager() {
    return Tracker::getInstance();
}