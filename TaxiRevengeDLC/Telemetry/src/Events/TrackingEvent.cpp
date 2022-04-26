
#include "../../include/Events/TrackingEvent.h"

TrackingEvent::TrackingEvent(EventType type) :
	mType_(type),
	mIDGame_(TrackerManager()->getIDGame()),
	mIDSession_(TrackerManager()->getIDSession()) 
	{
	std::time(&mTimestamp_);
	}

void TrackingEvent::writeInJSON(JsonObject& object)
{
	object.add("IDGame", mIDGame_);
	object.add("IDSession", mIDSession_);
	char time[30];
	std::strftime(time,30, "%c", std::localtime(&mTimestamp_));
	object.add("Time", time);
}
