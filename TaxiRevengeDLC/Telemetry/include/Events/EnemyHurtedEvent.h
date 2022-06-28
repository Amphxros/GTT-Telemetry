#pragma once 
#include "TrackingEvent.h"
class EnemyHurtedEvent : public TrackingEvent
{
private:
    uint8_t mID_;
public:
    EnemyHurtedEvent():TrackingEvent(EventType::EnemyHurted){}
    ~EnemyHurtedEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};
