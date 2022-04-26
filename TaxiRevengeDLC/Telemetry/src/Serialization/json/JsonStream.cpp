#include "../../../include/Serialization/json/JsonStream.h"

void JsonStream::open()
{
	if (!addedFirstElem) {
		addedFirstElem = true;
	}
	else {

	}
}

void JsonStream::close()
{
}

void JsonStream::clear()
{
}

std::string JsonStream::toString() const
{
	return std::string();
}
