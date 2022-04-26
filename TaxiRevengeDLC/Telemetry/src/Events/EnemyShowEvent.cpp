#include "../../include/Events/EnemyShowEvent.h"

void EnemyShowEvent::writeInJSON(JsonObject& object)
{

	object.add("EvType", "EnemyShow " + mID_);
	TrackingEvent::writeInJSON(object);
}
