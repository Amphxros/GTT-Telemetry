#pragma once

#include <string>
// base class to write the file itself
class IStream{ 
    public: 
        IStream() = default;
        virtual ~IStream()=default;

        virtual void add(const std::string& msg)=0;
        virtual void clear()=0;

        virtual void open(){}
        virtual void close(){}
};