#include "../../include/Events/PlayerHurtedEvent.h"

void PlayerHurtedEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "PlayerDead ");
	TrackingEvent::writeInJSON(object);
}
