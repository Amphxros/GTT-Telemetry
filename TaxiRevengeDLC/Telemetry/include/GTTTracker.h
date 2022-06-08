#pragma once
#include "Tracking/ITracker.h"

class GTTTracker: public ITracker
{
private:
    /* data */
public:
    GTTTracker(/* args */)=default;
    ~GTTTracker()=default;
    bool receiveEvent(TrackingEvent* mEvent) override;
};

