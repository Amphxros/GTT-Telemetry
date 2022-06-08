
#pragma once
#include <string>
#include "../IObject.h"
struct Padding{

};


class JsonObject: public IObject
{
protected:

    inline std::string formatString(const std::string& mString){
        return QUOTE + mString + QUOTE;
    }

    bool addedFirstElem=false;
    
    
public:
    JsonObject(/* args */)=default;
    ~JsonObject() = default;

    void open();
    void close();

    void add(const std::string& key, const std::string& val);

    //useful chars of json files
    static constexpr char START_OBJ='{';
    static constexpr char END_OBJ='}';
    static constexpr char START_ARRAY='[';
    static constexpr char END_ARRAY=']';
    static constexpr char SPACE=' ';
    static constexpr char COLON=':';
    static constexpr char NEW_LINE='\n';
    static constexpr char COMMA=',';
    static constexpr char DOT='.';
    static constexpr char QUOTE='"';
    
    
};


