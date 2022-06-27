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

using namespace std;

typedef unsigned int uint;

int main(int argc, char* argv[]) {
	//Inicializacion 
	TrackerManager()->init("juego");


	Game::getInstance()->initInstance(); //initInstance() only once
	Game::getInstance()->run();
	Game::destroyInstance();

	//cierre del tracker
	TrackerManager()->end();

	return 0;
}