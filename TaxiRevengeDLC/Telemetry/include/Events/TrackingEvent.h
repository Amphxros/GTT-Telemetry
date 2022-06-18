
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
