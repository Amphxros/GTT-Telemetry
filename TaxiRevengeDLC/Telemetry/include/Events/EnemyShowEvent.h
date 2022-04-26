#pragma once 
#include "TrackingEvent.h"
class EnemyShowEvent : public TrackingEvent
{
private:
    uint8_t mID_;
public:
    EnemyShowEvent(uint8_t id) : TrackingEvent(EventType::EnemyShow), mID_(id) {}
    ~EnemyShowEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};

