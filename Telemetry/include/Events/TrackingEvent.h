
#pragma once

#include <ctime>
#include <string>

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
    EventType mType_;
public:
    TrackingEvent(EventType type): mType_(type){}
    ~TrackingEvent();
};

TrackingEvent::TrackingEvent(/* args */)
{
}

TrackingEvent::~TrackingEvent()
{
}
