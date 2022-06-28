#include "../../../include/Serialization/json/JsonSerializer.h"
#include "../../../include/Serialization/json/JsonObject.h"
#include "../../../include/Events/TrackingEvent.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
JsonSerializer::JsonSerializer()
{
}
JsonSerializer::~JsonSerializer()
{
}
std::string JsonSerializer::serialize(TrackingEvent* mEvent)
{
    /*JsonObject obj;
    obj.open();
    mEvent->writeInJSON(obj);
    obj.close();

    return std::string();*/

    std::string jsonString;

    jsonString = "{ \n";
    jsonString += "\t \"Event type\": ";
    jsonString += "\"" + EventToString(mEvent->getEventType()) + "\" ,\n";
    jsonString += "\t \"Time\": ";
    std::stringstream ss;
    ss << mEvent->getTimeStamp();
    std::string ts = ss.str();
    jsonString += "\"" + ts + "\"\n";
    jsonString += "} \n";

    return jsonString;

}

std::string JsonSerializer::getExtension()
{
    return ".json";
}
