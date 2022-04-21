
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
    /* data */
public:
    TrackingEvent(/* args */);
    ~TrackingEvent();
};

TrackingEvent::TrackingEvent(/* args */)
{
}

TrackingEvent::~TrackingEvent()
{
}
