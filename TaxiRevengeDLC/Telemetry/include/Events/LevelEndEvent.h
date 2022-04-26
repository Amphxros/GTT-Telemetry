#pragma once 
#include "TrackingEvent.h"
class LevelEndEvent : public TrackingEvent
{
private:
    /* data */
public:
    LevelEndEvent(): TrackingEvent(EventType::Level_end){}
    ~LevelEndEvent() = default;
    virtual void writeInJSON(JsonObject& object);
};

