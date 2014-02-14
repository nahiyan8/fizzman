#include "GameEngine.hpp"

////////////////////////////////////////////////////////////////////////////////

void GameEngine::physics(float timestep)
{
	/* The commented out stuff is test code.
	 * I'm still keeping it here as a guideline until I make something solid. */
	
	/*
	sf::Vector2f pos_f = p.s.getPosition();
	sf::Vector2f accel_f;
	
	sf::Vector2i pos_i(pos_f.x, pos_f.y);
	sf::Vector2i window_s(window.getSize().x, window.getSize().y);
	
	window_s.x -= p.s.getTextureRect().width;
	window_s.y -= p.s.getTextureRect().height;
	
	// Boundary checking
	if (pos_i.x < 0)           { pos_f.x = 0;        p.v.x *= -0.50f; } else // Left-wide wall
	if (pos_i.x > window_s.x)  { pos_f.x = window_s.x; p.v.x *= -0.50f; }      // Right-side wall
	
	if (pos_i.y < 0) { pos_f.y = 0;        p.v.y *= -1.00f; } // Ceiling
	else 
		if (pos_i.y >= window_s.y)                                      // Ground
		{
			pos_f.y = window_s.y;
			
			p.v.x *=  0.90f;
			p.v.y *= -0.25f;
		};
	
	p.v   += accel_f * timestep;
	pos_f += p.v     * timestep;
	
	p.s.setPosition(pos_f);
	*/
}

////////////////////////////////////////////////////////////////////////////////

/*
inline sf::Vector2f GameEngine::rk4(sf::Vector2f position, sf::Vector2f velocity, float timestep)
{
	sf::Vector2f k1, k2(position), k3(position), k4(position);
	
	k1  = velocity;
	k2 += (velocity * timestep) / 2.0f;
	k3 += (k2       * timestep) / 2.0f;
	k4 += (k3       * timestep);
	
	return ((k1 + k4 + 2.0f*(k2 + k3)) * timestep) / 6.0f;
}
*/

////////////////////////////////////////////////////////////////////////////////
