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
    case EnemyShow:   return "Enemy Show";
    case EnemyFirstBlood: return "Enemy First Blood";
    case PlayerDead:   return "Player Dead";
    case EnemyDead:   return "Enemy Dead";
    case EnemyHurted: return "Enemy Hurted";
    default:      return "[Unknown event type]";
    }
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
