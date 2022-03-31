#pragma once
#include <stdint.h>
#include <chrono>
enum TypeEvent{
	Start, 
	Log, 
	EnemyShow,
	EnemyFirstBlood,
	PlayerDead,
	EnemyDead,
	EnemyHurted
};

//send message <..,>(blablabla)
class Evento
{
public:
	Evento(TypeEvent ev);
protected:
	TypeEvent mEvent_;
};


class EventStart : public Evento {
public:
	EventStart(TypeEvent t, uint32_t id, uint32_t time);
	~EventStart() {}


protected:
	uint32_t mUserID_;
	uint32_t time_;

};

class EventLog : public Evento {
public:
	EventLog();
	~EventLog() {}

	int generateID();
	int getUserID();

protected:
	uint32_t mUserID_;

};

class EventEnemyShow : public Evento {
public:
	EventEnemyShow(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time);
	~EventEnemyShow() {}


protected:
	uint32_t mUserID_;
	uint8_t mEnemyID_;
	uint32_t time_;

};


class EventEnemyFirstBlood : public Evento {
public:
	EventEnemyFirstBlood(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time);
	~EventEnemyFirstBlood() {}


protected:
	uint32_t mUserID_;
	uint8_t mEnemyID_;
	uint32_t time_;

};


class EventPlayerDead : public Evento {
public:
	EventPlayerDead(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time);
	~EventPlayerDead() {}


protected:
	uint32_t mUserID_;
	uint8_t mEnemyID_;
	uint32_t time_;

};


class EventEnemyDead : public Evento {
public:
	EventEnemyDead(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time);
	~EventEnemyDead() {}


protected:
	uint32_t mUserID_;
	uint8_t mEnemyID_;
	uint32_t time_;

};

class EventEnemyHurt : public Evento {
public:
	EventEnemyHurt(TypeEvent t, uint32_t id, uint8_t enemyID, uint32_t time, uint8_t gunId);
	~EventEnemyHurt() {}


protected:
	uint32_t mUserID_;
	uint32_t time_;
	uint8_t mEnemyID_;
	uint8_t mGunID_;

};