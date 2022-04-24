#pragma once 
#include "Utils/Singleton.h"
#include <string>
#include <ctime>
#include <list>

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

    std::string getIDGame();
    std::string getIDSession();

    void init(std::string IDGame);
    void end();

    void activateTracker();
    void setPersistence(IPersistence* nPersistance);

    const std::string& getIDSession() const { return idSession_; }
    void trackEvent(TrackingEvent* nEvent);
};