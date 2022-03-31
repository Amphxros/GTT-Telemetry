#include "Tracker.h"

void Tracker::sendEvent(Evento* eve)
{
	listaEventos.push_back(eve);
}

void Tracker::guardarJSON(std::string fileName)
{

}
