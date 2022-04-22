#pragma once 
#include "TrackingEvent.h"
class EnemyDeadEvent : public TrackingEvent
{
private:
    uint8_t mID_;

public:
    EnemyDeadEvent(uint8_t id): TrackingEvent(EventType::EnemyDead), mID_(id){}
    ~EnemyDeadEvent()=default;
};


