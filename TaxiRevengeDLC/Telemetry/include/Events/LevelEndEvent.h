#pragma once 
#include "TrackingEvent.h"
class LevelEndEvent : public TrackingEvent
{
private:
    /* data */
public:
    LevelEndEvent(/* args */);
    ~LevelEndEvent();
};

LevelEndEvent::LevelEndEvent(/* args */)
{
}

LevelEndEvent::~LevelEndEvent()
{
}
