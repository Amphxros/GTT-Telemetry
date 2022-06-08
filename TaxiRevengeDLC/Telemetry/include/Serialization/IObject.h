#pragma once

#include <string>
#include<iostream>
class IObject
{
public:
    IObject(/* args */)=default;
    ~IObject()= default;

    virtual std::string toString()const { return ""; }
protected:

   
    virtual std::string formatString(const std::string& val){
        return val;
    }
    inline std::string serialize(const char* val){
        return formatString(val);
    }
    
    inline std::string serialize(const int8_t val){
        return serialize(static_cast<int32_t>(val));
    }
    
    inline std::string serialize(const uint8_t  val){
        return  serialize(static_cast<uint32_t>(val));
    }
    

    inline std::string serialize(const int16_t  val){
        return serialize(static_cast<int32_t>(val));
    }
    
    inline std::string serialize(const uint16_t val){
        return  serialize(static_cast<uint32_t>(val));
    }
    

    inline std::string serialize(const int32_t val){
        return std::to_string(val);
    }
    
    inline std::string serialize(const uint32_t val){
        return std::to_string(val);
    }
    
    inline std::string serialize(const int64_t val){
        return std::to_string(val);
    }
     inline std::string serialize(const uint64_t val){
        return std::to_string(val);
    }
    
    inline std::string serialize(const float val){
        return std::to_string(val);
    }

     inline std::string serialize(const double val){
        return std::to_string(val);
    }

     inline std::string serialize(const bool val){
       return val? "true" : "false" || val? "1": "0";
    }

     inline std::string serialize(const IObject& val){
        return val.toString();
    }

    

};


