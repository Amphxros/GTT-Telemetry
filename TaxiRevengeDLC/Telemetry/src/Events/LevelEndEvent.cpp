#include "../../include/Events/LevelEndEvent.h"

void LevelEndEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "Session End");
	TrackingEvent::writeInJSON();
}
