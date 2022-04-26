#include "../IStream.h"
#include "JsonObject.h"
class JsonStream: 
    public IStream, private JsonObject
{
private:
    /* data */
public:
    JsonStream(/* args */)=default;
    ~JsonStream()=default;

    void open() override;
    void close() override;

    void clear() override;

    std::string toString() const override;

};


