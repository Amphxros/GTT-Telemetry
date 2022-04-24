#pragma once
#include "IPersistence.h"

class FilePersistence final: public IPersistence {
public:
	FilePersistence(uint64_t time);
	~FilePersistence();

	void send(TrackingEvent* nEvent)override;
	void flush() override;

	void run();
	void startThread();


private:
	std::mutex mEventMutex_;
	uint64_t mTimer_{ 60 };
	std::thread* mFlushThread_;
	std::string mFileName_;
};