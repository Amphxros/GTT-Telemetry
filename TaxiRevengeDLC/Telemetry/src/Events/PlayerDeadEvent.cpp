#include "../../include/Events/PlayerDeadEvent.h"

void PlayerDeadEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "PlayerDead ");
	TrackingEvent::writeInJSON(object);
}
