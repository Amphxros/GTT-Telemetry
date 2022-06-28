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

std::string EventToString(EventType ev)
{
    switch (ev)
    {
    case Session_Begin:   return "Session Begin";
    case Session_end:   return "Session end";
    case Level_Start: return "Level Start";
    case Level_end:   return "Level end";
    case PlayerDead:   return "Player Dead";
    case PlayerHurted:   return "Player Hurted";
    case PlayerShoot:   return "Player Shoot";
    case EnemyDead:   return "Enemy Dead";
    case EnemyHurted: return "Enemy Hurted";
    default:      return "[Unknown event type]";
    }
}

std::string JsonSerializer::serialize(TrackingEvent* mEvent)
{
    std::string jsonString = "";

    if (mEvent->getEventType() == EventType::Session_Begin) { 
        jsonString += "{\n"; 
        jsonString += "\"events\": [ \n";
    }

    jsonString += "{ \n";
    jsonString += "\t \"Event type\": ";
    jsonString += "\"" + EventToString(mEvent->getEventType()) + "\" ,\n";
    jsonString += "\t \"Time\": ";
    std::stringstream ss;
    ss << mEvent->getTimeStamp();
    std::string ts = ss.str();
    jsonString += "\"" + ts + "\"\n";
    jsonString += "}";

    if (mEvent->getEventType() == EventType::Session_end) { 
        jsonString += "\n"; 
        jsonString += "]";
        jsonString += "\n}"; 
    }
    else jsonString += ",\n";

    return jsonString;

}

std::string JsonSerializer::getExtension()
{
    return ".json";
}
