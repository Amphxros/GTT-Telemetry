#include "../../include/Events/LevelStartEvent.h"

void LevelStartEvent::writeInJSON(JsonObject& object)
{
	object.add("EventType", "Session Start Event");
	TrackingEvent::writeInJSON(object);
}
