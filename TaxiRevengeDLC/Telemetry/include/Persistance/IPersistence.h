#pragma once 
#include <ctime>
#include <queue>

class TrackingEvent;
class ISerializer;
class IStream;

class IPersistence {
public:
    virtual ~IPersistence();

    void setStream(IStream* nStream);
    void SetSerializer(ISerializer* nSerializer);

    virtual void send(TrackingEvent* tEvent)=0;
    virtual void flush() = 0;
protected:
    IPersistence() = default;
	std::queue<TrackingEvent*> mEvents_;
    ISerializer* mSerializer_ = nullptr;
    IStream* mStream_ = nullptr;
    
};