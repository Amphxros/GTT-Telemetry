
#pragma once

#include <string>

class TrackingEvent;

class ISerializer{
    public:
        ISerializer()=default;
        virtual ~ISerializer()=0;

        virtual std::string serialize(TrackingEvent* mEvent) =0;
        virtual std::string getExtension()=0;

};