#pragma once
#include "TrackingEvent.h"
class SessionStartEvent: public TrackingEvent
{
private:
    /* data */
public:
    SessionStartEvent(/* args */);
    ~SessionStartEvent();
};

SessionStartEvent::SessionStartEvent(/* args */)
{
}

SessionStartEvent::~SessionStartEvent()
{
}
