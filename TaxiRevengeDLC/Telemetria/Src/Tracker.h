#pragma once
#include "Singleton.h"
#include "Evento.h"
#include <string>
#include <list>
class Tracker: Singleton<Tracker>
{
public:
	Tracker() :Singleton<Tracker>(){}
	// tracker. sendEvent(new EventoStart(...))
	//tracker->sendEvent<StartEvent>(...)
	void sendEvent(Evento* eve);

	//serializacion a JSON
	void guardarJSON(std::string fileName);


protected:
	std::list<Evento*> listaEventos;
};

