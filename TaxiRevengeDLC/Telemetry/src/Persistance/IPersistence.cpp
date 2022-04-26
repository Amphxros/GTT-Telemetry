#include "..\..\include\Persistance\IPersistence.h"
#include "..\..\include\Serialization\ISerializer.h"
#include "..\..\include\Serialization\IStream.h"

IPersistence::~IPersistence()
{
    delete mSerializer_;
    delete mStream_;

    while(!mEvents_.empty()){
        delete mEvents_.front();
        mEvents_.pop();
    }
}

void IPersistence::setStream(IStream* nStream)
{
	mStream_ = nStream;
	mStream_->open();
    
}

void IPersistence::SetSerializer(ISerializer* nSerializer)
{
    mSerializer_ = nSerializer;
}
