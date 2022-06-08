#include "../../../include/Serialization/json/JsonSerializer.h"
#include "../../../include/Serialization/json/JsonObject.h"
#include "../../../include/Events/TrackingEvent.h"
std::string JsonSerializer::serialize(TrackingEvent* mEvent)
{
    JsonObject obj;
    obj.open();
    mEvent->writeInJSON(obj);
    obj.close();

    return std::string();
}
