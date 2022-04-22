#pragma once 
#include "TrackingEvent.h"
class EnemyHurtedEvent : public TrackingEvent
{
private:
    /* data */
public:
    EnemyHurtedEvent(/* args */);
    ~EnemyHurtedEvent();
};

EnemyHurtedEvent::EnemyHurtedEvent(/* args */)
{
}

EnemyHurtedEvent::~EnemyHurtedEvent()
{
}
