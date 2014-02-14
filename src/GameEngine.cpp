#include "GameEngine.hpp"

////////////////////////////////////////////////////////////////////////////////
///////////////////// --- CONSTRUCTOR/S & DESTRUCTOR/S --- /////////////////////
////////////////////////////////////////////////////////////////////////////////

GameEngine::GameEngine() : state()
{
	window.create(sf::VideoMode(1280, 800), "Fizzman: The Barebones");
	
	// Set defaults!
	state.running = true;
	
	ReportLog(GAME_LOG_INFO, "GameEngine class initialised");
}

////////////////////////////////////////////////////////////////////////////////

GameEngine::~GameEngine()
{
	state.running = false;
}

////////////////////////////////////////////////////////////////////////////////
