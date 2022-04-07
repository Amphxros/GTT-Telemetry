#include "PersistanceSystem.h"




PersistanceSystem::PersistanceSystem(string fileName_)
{
    fileName = fileName_;
}

void PersistanceSystem::setSerializer(/*serializador*/) //Elegimos el serializador
{
    //Ponemos el serializador correspondiente
}

void PersistanceSystem::flush()//Volcamos la cola de eventos
{
    //Para cada evento de la cola hacemos el
}

void PersistanceSystem::writeEvent(/*evento*/)//Serializamos y escribimos en disco un evento
{
    //Escribimos en disco casa evento
}