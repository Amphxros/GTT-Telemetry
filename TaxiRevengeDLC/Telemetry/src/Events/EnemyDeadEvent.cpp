#include "../../include/Events/EnemyDeadEvent.h"

void EnemyDeadEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "EnemyDead " + mID_);
	TrackingEvent::writeInJSON(object);
}
