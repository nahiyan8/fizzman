#ifndef GAMEENGINE_HPP
#define GAMEENGINE_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include "pool.hpp"

#define GAME_ERR_DEBUG	0
#define GAME_ERR_NOTICE	1
#define GAME_ERR_WARN	2
#define GAME_ERR_FATAL	3

#define GAME_STATE_RUNNING	(1 << 0)
#define GAME_STATE_PHYSICS	(1 << 1)
#define GAME_STATE_RENDERS	(1 << 2)

#define QueryState(_state)		(state & _state)
#define EnableState(_state)		(state |= _state)
#define DisableState(_state)	(state &= ~_state)

class GameEngine
{
	private:
		sf::RenderWindow window;
		
		uint state;
		
		Pool <sf::Sprite> sprites;
		Pool <sf::Texture> textures;
		Pool <sf::Vector2f> velocities;
		
	protected:
		sf::Vector2f rk4(sf::Vector2f position, sf::Vector2f velocity, float time_step);
		sf::Vector2f euler(sf::Vector2f position, sf::Vector2f velocity, float time_step);
		
		void ErrorReport(uint error_level, char error_file[], uint error_line, char message[]);
		
	public:
		GameEngine();
		~GameEngine();
		
		void loop();
		void physics(float time_step);
		void render();
};

#endif
