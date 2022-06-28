#pragma once
#include "TrackingEvent.h"
class PlayerShootEvent : public TrackingEvent
{
private:
    /* data */
public:
    PlayerShootEvent(/* args */) : TrackingEvent(EventType::PlayerShoot) {}
    ~PlayerShootEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};
