#pragma once 
#include <string>
#include <ctime>
#include <list>
//#include "Utils/uuid.h"

class ITracker;
class TrackingEvent;
class IPersistence;

class Tracker
{
private:
    static bool running;
    std::string idGame_;
    std::string idSession_;
    std::time_t mTimeStamp_;
    long long initialTime;

    IPersistence* mPersistence_;
    std::list<ITracker*> mActiveTrackers_;
    static Tracker* instance;
    Tracker();

public:
    ~Tracker() = default;

    static Tracker* getInstance();

    std::string generateIDSession();

    void init(std::string IDGame);
    void end();

    void setPersistence(IPersistence* nPersistance);

    const std::string& getIDSession() const { return idSession_; }
    const std::string& getIDGame() const { return idGame_; }
    void trackEvent(TrackingEvent* nEvent);
    long long getInitialTime();

   inline static bool isRunning() { return running; }
};

inline Tracker* TrackerManager() {
    return Tracker::getInstance();
}