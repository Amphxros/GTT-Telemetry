#pragma once 

#include <string>
#include "../ISerializer.h"
class TrackingEvent;

class JsonSerializer: public ISerializer
{
private:
    /* data */
public:
    JsonSerializer(/* args */)= default;
    ~JsonSerializer()= default;

    std::string serialize(TrackingEvent* mEvent) override;
    std::string getExtension() override {return ".json";}


};


