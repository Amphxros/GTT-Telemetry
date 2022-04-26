#pragma once 
#include "TrackingEvent.h"
class LevelStartEvent : public TrackingEvent
{
private:
    /* data */
public:
    LevelStartEvent(/* args */) : TrackingEvent(EventType::Level_Start) {}
    ~LevelStartEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};