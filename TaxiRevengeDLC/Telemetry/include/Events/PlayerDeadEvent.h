#pragma once
#include "TrackingEvent.h"
class PlayerDeadEvent : public TrackingEvent
{
private:
    /* data */
public:
    PlayerDeadEvent(/* args */);
    ~PlayerDeadEvent();
};

PlayerDeadEvent::PlayerDeadEvent(/* args */)
{
}

PlayerDeadEvent::~PlayerDeadEvent()
{
}
