#include "GameEngine.hpp"

////////////////////////////////////////////////////////////////////////////////
///////////////////// --- CONSTRUCTOR/S & DESTRUCTOR/S --- /////////////////////
////////////////////////////////////////////////////////////////////////////////

GameEngine::GameEngine()
{
	window.create(sf::VideoMode(1280, 800), "FizzMan: The Barebones");
	
	sprites.create(4096);
	textures.create(4096);
	velocities.create(4096);
	
	state = 0;
	StateOn( GAME_STATE_RUNNING );
}

////////////////////////////////////////////////////////////////////////////////

GameEngine::~GameEngine()
{
	StateOff( GAME_STATE_RUNNING );
}

////////////////////////////////////////////////////////////////////////////////

void GameEngine::ErrorReport(uint error_level, char error_file[], uint error_line, char message[])
{
	std::cerr << error_file << ':' << error_line << ": ";
	
	switch (error_level)
	{
		case GAME_ERR_DEBUG:	std::cerr << "debug: ";
		case GAME_ERR_NOTICE:	std::cerr << "notice: ";
		case GAME_ERR_WARN:		std::cerr << "warning: ";
		case GAME_ERR_FATAL:	std::cerr << "fatal: ";
	}
	
	std::cerr << message << '\n';
	
	if (error_level >= GAME_ERR_FATAL)
		throw error_level;
}

////////////////////////////////////////////////////////////////////////////////