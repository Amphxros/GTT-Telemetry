#pragma once 
#include "TrackingEvent.h"
class EnemyHurtedEvent : public TrackingEvent
{
private:
    uint8_t mID_;
public:
    EnemyHurtedEvent(uint8_t id):TrackingEvent(EventType::EnemyHurted), mID_(id){}
    ~EnemyHurtedEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};
