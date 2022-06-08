#pragma once
#include "TrackingEvent.h"
class SessionStartEvent: 
    public TrackingEvent
{
private:
    /* data */
public:
    SessionStartEvent():TrackingEvent(EventType::Session_Begin){}
    ~SessionStartEvent() = default;
    
    virtual void writeInJSON(JsonObject& object);
};
