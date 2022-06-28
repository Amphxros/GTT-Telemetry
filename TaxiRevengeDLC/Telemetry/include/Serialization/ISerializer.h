#pragma once

#include <string>

class TrackingEvent;
// class useful for making different types of serialization files(json, csv, xml...)
class ISerializer{
    public:
        ISerializer() = default;
        ~ISerializer() = default;

        virtual std::string serialize(TrackingEvent* mEvent) =0;
        virtual std::string getExtension()=0;

};