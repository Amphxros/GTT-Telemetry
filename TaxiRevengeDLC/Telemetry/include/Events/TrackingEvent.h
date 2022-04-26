
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
    const std::string mIDGame_;
    const std::string mIDSession_;


public:
    TrackingEvent(EventType type);
    virtual ~TrackingEvent() = default;

    inline EventType getEventType() const { return mType_; }
    inline time_t getTimeStamp() const { return mTimestamp_; }

    virtual void writeInJSON(JsonObject& object);
};
