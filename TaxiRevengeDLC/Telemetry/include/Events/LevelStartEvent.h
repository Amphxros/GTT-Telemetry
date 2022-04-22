#pragma once 
#include "TrackingEvent.h"
class LevelStartEvent : public TrackingEvent
{
private:
    /* data */
public:
    LevelStartEvent(/* args */);
    ~LevelStartEvent();
};

LevelStartEvent::LevelStartEvent(/* args */)
{
}

LevelStartEvent::~LevelStartEvent()
{
}
