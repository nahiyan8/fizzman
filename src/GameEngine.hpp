#ifndef GAMEENGINE_HPP_INCLUDED
#define GAMEENGINE_HPP_INCLUDED

#include <stdint.h>
#include <SFML/Graphics.hpp>

#include "diagnostics.hpp"

#define DEFAULT_TIMESTEP     0.010f // 10ms
#define DEFAULT_METRERATIO 100.000f // 50px/metre

#define DEFAULT_GRAVITATION   (DEFAULT_METRERATIO * 9.8f) // 9.8m/s^2
#define DEFAULT_MOVEMENTSPEED sf::Vector2f((DEFAULT_METRERATIO * 5.0f), (DEFAULT_METRERATIO * 5.0f)) // 3.0m/s

struct state_t
{
	// Basic states that affect whole parts of the game.
	bool running; // The engine is loaded and running.
	bool loading; // Should we show a loading screen?
	bool physics; // Enable physics?   E.g. disable physics in menus.
	bool  render; // Enable rendering? E.g. the shaders aren't loaded.
	bool   audio; // Enable audio?     E.g. no speakers were found.
};

struct settings_t
{
	// Game settings.
	
	// Physics settings.
	float physics_step; // Physics timestep.
	bool  gravity;      // Apply planetary gravity.
	bool  gravitation;  // Apply gravitation *BETWEEN* objects!
	bool  atmosphere;   // Apply aerodynamics: e.g. drag, lift, etc.
	
	// Graphics settings.
	uint render_step;   // Rendering timestep. (0 for as fast as possible.)
	bool raytracing;    // Partially enable raytracing for shadows.
	
	// Audio settings.
	float volume;       // The audio volume, normalised within [0.0, 1.0].
};

class GameEngine
{
	private:
		// Common
		state_t    state;
		settings_t settings;
		
		// Rendering
		sf::RenderWindow window;
		
	public:
		 GameEngine();
		~GameEngine();
		
		void loop();
		void physics(float timestep);
		void render();
};

#endif
