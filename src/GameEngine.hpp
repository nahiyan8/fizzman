#ifndef GAMEENGINE_HPP_INCLUDED
#define GAMEENGINE_HPP_INCLUDED

#include <SFML/Graphics.hpp>
#include <stdint.h>

#include "pool.hpp"
#include "diagnostics.hpp"

#define GAME_STATE_RUNNING	(1 << 0)
#define GAME_STATE_LOADING	(1 << 1)
#define GAME_STATE_PHYSICS	(1 << 2)
#define GAME_STATE_RENDER	(1 << 3)

#define QueryState(_state)   (state & _state)
#define EnableState(_state)  state |= _state;
#define DisableState(_state) state &= ~_state;

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
		
	public:
		GameEngine();
		~GameEngine();
		
		void loop();
		void physics(float time_step);
		void render();
};

#endif
