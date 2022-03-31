#include "Evento.h"

Evento::Evento(TypeEvent ev)
{
	mEvent_ = ev;
}

EventStart::EventStart(TypeEvent t, uint32_t id, uint32_t time):Evento(t)
{
	mUserID_ = id;
	time_ = time;
}

EventEnemyShow::EventEnemyShow(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time):Evento(t)
{
	mUserID_ = id;
	mEnemyID_ = enemyID;
	time_ = time;

}

EventEnemyFirstBlood::EventEnemyFirstBlood(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time) :Evento(t)
{
	mUserID_ = id;
	mEnemyID_ = enemyID;
	time_ = time;

}

EventPlayerDead::EventPlayerDead(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time) :Evento(t)
{
	mUserID_ = id;
	mEnemyID_ = enemyID;
	time_ = time;

}

EventEnemyDead::EventEnemyDead(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time) :Evento(t)
{
	mUserID_ = id;
	mEnemyID_ = enemyID;
	time_ = time;

}
EventEnemyHurted::EventEnemyHurted(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time, uint8_t gunId) :Evento(t)
{
	mUserID_ = id;
	mEnemyID_ = enemyID;
	time_ = time;
	mGunID_ = gunId;

}

EventLog::EventLog():Evento(TypeEvent::Log)
{
	mUserID_ = generateID();
}

int EventLog::generateID()
{
	
	return 1;
}

int EventLog::getUserID()
{
	return mUserID_;
}
