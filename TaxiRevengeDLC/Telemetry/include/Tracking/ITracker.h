#pragma once

class TrackingEvent;

class ITracker
{
private:
    /* data */
public:
    ITracker(/* args */)=default;
    virtual ~ITracker()= default;

    virtual bool receiveEvent(TrackingEvent* mEvent)=0;
};
