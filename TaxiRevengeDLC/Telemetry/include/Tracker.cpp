#include "../include/Tracker.h"
#include <combaseapi.h>
#include"Events/TrackingEvent.h"
#include "Events/SessionEndEvent.h"
#include "Events/SessionStartEvent.h"

#include "Persistance/FilePersistence.h"
#include "GTTTracker.h"

std::string Tracker::generateIDSession()
{

	return std::string();
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
	delete mPersistence_;

	while (!mActiveTrackers_.empty()) {
		mActiveTrackers_.pop_back();
	}
}

void Tracker::activateTracker()
{
	mActiveTrackers_.push_back(new GTTTracker());
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
