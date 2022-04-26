#pragma once 
#include "TrackingEvent.h"
class EnemyFirstBloodEvent : public TrackingEvent
{
private:
    uint8_t mID_;
public:
    EnemyFirstBloodEvent(uint8_t id) : TrackingEvent(EventType::EnemyFirstBlood), mID_(id) {};
    ~EnemyFirstBloodEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};


