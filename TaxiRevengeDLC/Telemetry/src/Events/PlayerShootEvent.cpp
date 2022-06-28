#include "../../include/Events/PlayerShootEvent.h"

void PlayerShootEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "PlayerDead ");
	TrackingEvent::writeInJSON(object);
}
