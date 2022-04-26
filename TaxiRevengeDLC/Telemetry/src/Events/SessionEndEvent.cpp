#include "../../include/Events/SessionEndEvent.h"

SessionEndEvent::SessionEndEvent(/* args */) :
    TrackingEvent(EventType::Session_end)
{
}

void SessionEndEvent::writeInJSON(JsonObject& object)
{
}
