#pragma once
#include "TrackingEvent.h"
class PlayerDeadEvent : public TrackingEvent
{
private:
    /* data */
public:
    PlayerDeadEvent(/* args */) : TrackingEvent(EventType::PlayerDead) {}
    ~PlayerDeadEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};
