#include "../include/Tracker.h"
#include <combaseapi.h>
#include"Events/TrackingEvent.h"
#include "Events/SessionEndEvent.h"
#include "Events/SessionStartEvent.h"

#include "Persistance/FilePersistence.h"
#include "GTTTracker.h"

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
	return std::string("");
}

void Tracker::init(std::string IDGame)
{
	idGame_ = IDGame;
	std::time(&mTimeStamp_);
	idSession_ = generateIDSession();
	running = true;

	trackEvent(new SessionStartEvent());
	
}

void Tracker::end()
{
	trackEvent(new SessionEndEvent());
	mPersistence_->flush();
	delete mPersistence_;

	while (!mActiveTrackers_.empty()) {
		mActiveTrackers_.pop_back();
	}
}

void Tracker::activateTracker()
{
	mActiveTrackers_.emplace_back(new GTTTracker());
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
