#pragma once
#pragma once
#include "ITracker.h"

class GTTTracker: public ITracker
{
private:
    /* data */
public:
    GTTTracker(/* args */);
    ~GTTTracker();
    bool receiveEvent(TrackingEvent* mEvent) override;
};

GTTTracker::GTTTracker(/* args */)
{
}

GTTTracker::~GTTTracker()
{
}

