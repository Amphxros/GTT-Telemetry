#pragma once
#include "TrackingEvent.h"
class PlayerHurtedEvent : public TrackingEvent
{
private:
    /* data */
public:
    PlayerHurtedEvent(/* args */) : TrackingEvent(EventType::PlayerHurted) {}
    ~PlayerHurtedEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};
