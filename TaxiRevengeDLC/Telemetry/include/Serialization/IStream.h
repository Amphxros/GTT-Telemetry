#pragma once

#include <string>

class IStream{
    public: 
        IStream() = default;
        virtual ~IStream()=default;

        virtual void add(const std::string& msg)=0;
        virtual void clear()=0;

        virtual void open()=0;
        virtual void close()=0;
};