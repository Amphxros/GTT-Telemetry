#pragma once
#include "IPersistence.h"
#include <string>

class FilePersistence final: public IPersistence {
public:
	FilePersistence(uint64_t time);
	~FilePersistence();

	void send(TrackingEvent* nEvent)override;
	void flush() override;

	void run();


private:
	uint64_t mTimer_{ 60 };
	std::string mFileName_;
};