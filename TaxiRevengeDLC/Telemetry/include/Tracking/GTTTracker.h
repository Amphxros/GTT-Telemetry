#pragma once
#include "ITracker.h"
#include <ctime>

class GTTTracker:
    public ITracker
{
private:
    uint32_t mLevelCount_;
    std::time_t mStartLevelTime_;
    std::time_t mEndLevelTime_;

public:
    GTTTracker(/* args */);
    ~GTTTracker();
    bool receiveEvent(TrackingEvent* mEvent) override;
};
