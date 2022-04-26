#include "../../include/Events/SessionStartEvent.h"

void SessionStartEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "Session Start");
	TrackingEvent::writeInJSON(object);
}
