#pragma once

#include <string>
#include <iostream>

using namespace std;
class PersistanceSystem
{
    protected:
    string fileName;
    //aqui el seralizador
    //Aqui una cola de eventos
        
    public:
    PersistanceSystem(string fileName_);
    void setSerializer(/*serializador*/); //Elegimos el serializador
    void flush();//Volcamos la cola de eventos
    void writeEvent(/*evento*/);//Serializamos y escribimos en disco un evento
};
