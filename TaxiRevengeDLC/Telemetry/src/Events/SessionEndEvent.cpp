#include "../../include/Events/SessionEndEvent.h"

/*SessionEndEvent::SessionEndEvent() :
    TrackingEvent(EventType::Session_end)
{
}*/

void SessionEndEvent::writeInJSON(JsonObject& object)
{
    object.add("EvType", "SessionEnd");
    TrackingEvent::writeInJSON(object);
}
