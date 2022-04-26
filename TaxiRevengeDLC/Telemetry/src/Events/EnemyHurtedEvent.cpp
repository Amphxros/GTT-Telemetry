#include "../../include/Events/EnemyHurtedEvent.h"

void EnemyHurtedEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "EnemyHurted " + mID_);
	TrackingEvent::writeInJSON(object);
}
