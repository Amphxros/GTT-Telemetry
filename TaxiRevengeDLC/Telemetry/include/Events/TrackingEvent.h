#pragma once

#include <ctime>
#include <string>
#include "../Tracker.h"
#include "../Serialization/json/JsonObject.h"

enum EventType{
    
    Session_Begin,
    Session_end,
    Level_Start,
    Level_end,

    EnemyShow,
	EnemyFirstBlood,
	PlayerDead,
	EnemyDead,
	EnemyHurted
};

std::string EventToString(EventType ev)
{
    switch (ev)
    {
    case Session_Begin:   return "Session Begin";
    case Session_end:   return "Session end";
    case Level_Start: return "Level Start";
    case Level_end:   return "Level end";
    case EnemyShow:   return "Enemy Show";
    case EnemyFirstBlood: return "Enemy First Blood";
    case PlayerDead:   return "Player Dead";
    case EnemyDead:   return "Enemy Dead";
    case EnemyHurted: return "Enemy Hurted";
    default:      return "[Unknown event type]";
    }
}

class TrackingEvent
{
protected:
    time_t mTimestamp_;
    EventType mType_;
    std::string mIDGame_;
    std::string mIDSession_;


public:
    TrackingEvent(EventType type);
    TrackingEvent(EventType type, std::string idSession, std::string idGame);
    virtual ~TrackingEvent() = default;

    inline EventType getEventType() const { return mType_; }
    inline time_t getTimeStamp() const { return mTimestamp_; }

    virtual void writeInJSON(JsonObject& object);
};
