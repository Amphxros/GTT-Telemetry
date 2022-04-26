#pragma once 
#include "TrackingEvent.h"
class SessionEndEvent : public TrackingEvent
{
private:
    /* data */
public:
    SessionEndEvent(): TrackingEvent(EventType::Session_end){}
    ~SessionEndEvent() = default;

    virtual void writeInJSON(JsonObject& object);
};
