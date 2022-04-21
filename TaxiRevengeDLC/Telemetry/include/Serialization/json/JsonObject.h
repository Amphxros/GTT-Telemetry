
#pragma once
#include <string>

class JsonObject
{
protected:

    //useful char of json files
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
    
    inline std::string formatString(const std::string& mString){
        return QUOTE+ mString+ QUOTE;
    }

    
    
    
public:
    JsonObject(/* args */)=default;
    ~JsonObject();
};


