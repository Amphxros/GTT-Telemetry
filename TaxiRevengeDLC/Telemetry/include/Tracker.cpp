#include "../include/Tracker.h"
#include <combaseapi.h>
#include"Events/TrackingEvent.h"
#include "Events/SessionEndEvent.h"
#include "Events/SessionStartEvent.h"

#include "Persistance/FilePersistence.h"

bool Tracker::running = false;
Tracker* Tracker::instance = nullptr;

Tracker::Tracker() {}

Tracker* Tracker::getInstance()
{
	if (instance == nullptr) {
		instance = new Tracker();
	}

	return instance;
}

std::string Tracker::generateIDSession()
{
	std::time(&mTimeStamp_);
	long long id = ((((long long)mTimeStamp_ % 100000) / 10) * 1000000) + (((long long)mTimeStamp_ / 100000) * 10) + ((long long)mTimeStamp_ % 10);
	return std::to_string(id);
}

void Tracker::init(std::string IDGame)
{
	idGame_ = IDGame;
	std::time(&mTimeStamp_);
	idSession_ = generateIDSession();
	initialTime = (long long)mTimeStamp_;
	running = true;

	trackEvent(new SessionStartEvent());
	
}

void Tracker::end()
{
	trackEvent(new SessionEndEvent());
	mPersistence_->flush();
	delete mPersistence_;
}

void Tracker::setPersistence(IPersistence* nPersistance)
{
	mPersistence_ = nPersistance;
}

void Tracker::trackEvent(TrackingEvent* nEvent)
{
	bool accept = false;
	mPersistence_->send(nEvent);
}

long long Tracker::getInitialTime()
{
	return initialTime;
}
