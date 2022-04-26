#include "../../include/Events/EnemyFirstBloodEvent.h"

void EnemyFirstBloodEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "EnemyFirstBlood " + mID_);
	TrackingEvent::writeInJSON(object);
}
