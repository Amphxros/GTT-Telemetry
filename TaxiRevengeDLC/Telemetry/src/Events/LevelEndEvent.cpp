#include "../../include/Events/LevelEndEvent.h"

void LevelEndEvent::writeInJSON(JsonObject& object)
{
	object.add("EvType", "Session End");

	//Falta enviar por aqui el objeto
	//TrackingEvent::writeInJSON();
}
