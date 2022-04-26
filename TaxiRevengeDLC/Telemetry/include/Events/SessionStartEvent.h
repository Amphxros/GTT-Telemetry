#pragma once
#include "TrackingEvent.h"
class SessionStartEvent: public TrackingEvent
{
private:
    /* data */
public:
    SessionStartEvent(/* args */):TrackingEvent(EventType::Session_Begin){}
    ~SessionStartEvent();
};

SessionStartEvent::SessionStartEvent(/* args */)
{
}

SessionStartEvent::~SessionStartEvent()
{
}
