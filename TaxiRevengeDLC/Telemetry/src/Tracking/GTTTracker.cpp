
#include "../../include/Tracking/GTTTracker.h"
#include "../../include/Events/TrackingEvent.h"

bool GTTTracker::receiveEvent(TrackingEvent* mEvent)
{

	switch (mEvent->getEventType())
	{
	case EventType::Session_Begin:

		break;

	case EventType::Session_end:
		break;

	case EventType::Level_Start:
		break;
	case EventType::Level_end:
		break;

	case EventType::EnemyShow:
		break;
	case EventType::EnemyFirstBlood:
		break;
	case EventType::EnemyDead:
		break;
	case EventType::EnemyHurted:
		break;
	default:
		break;
	}

	return false;
}