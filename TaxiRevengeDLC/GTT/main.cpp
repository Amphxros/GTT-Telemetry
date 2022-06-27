#pragma once

// Visual Leak Detector library:
// uncomment the include to check for memory leaks
//#include <vld.h>

#include "SDL.h"
#include "SDL_image.h"

#include <iostream>

#include "Game.h"

//Telemetry
#include "../Telemetry/include/Tracker.h"
#include "../Telemetry/include/Persistance/FilePersistence.h"
#include "../Telemetry/include/Serialization/json/JsonSerializer.h"

using namespace std;

typedef unsigned int uint;

int main(int argc, char* argv[]) {
	//Inicializacion 
	Tracker* tracker = Tracker::getInstance();
	FilePersistence* persistence = new FilePersistence(0);
	JsonSerializer* serializer = new JsonSerializer();

	//persistence->SetSerializer(serializer);
	tracker->setPersistence(persistence);
	tracker->init("juego");


	Game::getInstance()->initInstance(); //initInstance() only once
	Game::getInstance()->run();
	Game::destroyInstance();

	//cierre del tracker
	tracker->end();

	return 0;
}