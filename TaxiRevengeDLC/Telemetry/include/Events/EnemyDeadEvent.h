#pragma once 
#include "TrackingEvent.h"
class EnemyDeadEvent : public TrackingEvent
{
private:
    uint8_t mID_;

public:
    EnemyDeadEvent(): TrackingEvent(EventType::EnemyDead){}
    ~EnemyDeadEvent()=default;

    virtual void writeInJSON(JsonObject& object);
};


