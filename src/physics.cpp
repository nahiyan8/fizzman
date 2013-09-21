#include "GameEngine.hpp"

////////////////////////////////////////////////////////////////////////////////

void GameEngine::physics(float time_step)
{
	sf::Rect <float> intersection;
	
	for (uint i = 0; i < sprites.getSize(); ++i)
	{
		if ( sprites.isUsed(i) == false )
			continue;
		
		sprites[i].setPosition( rk4(sprites[i].getPosition(), velocities[i], time_step) * 0.80f );
		
		for (uint j = i+1; j < sprites.getSize(); ++j)
		{
			if ( sprites.isUsed(j) == false )
				continue;
			
			if ( sprites[i].getGlobalBounds().intersects(sprites[j].getGlobalBounds(), intersection) )
			{
				velocities[i].x += intersection.width;
				velocities[i].y += intersection.height;
			}
		}
	}
}

////////////////////////////////////////////////////////////////////////////////

sf::Vector2f GameEngine::rk4(sf::Vector2f position, sf::Vector2f velocity, float time_step)
{
	sf::Vector2f k1, k2, k3, k4;
	
	k1 = velocity;
	k2 = euler(position, k1, time_step/2.0f);
	k3 = euler(position, k2, time_step/2.0f);
	k4 = euler(position, k3, time_step);
	
	return ((k1 + k4 + 2.0f*(k2 + k3)) * time_step) / 6.0f;
}

////////////////////////////////////////////////////////////////////////////////

sf::Vector2f GameEngine::euler(sf::Vector2f position, sf::Vector2f velocity, float time_step)
{
	return (position + (time_step * velocity));
}

////////////////////////////////////////////////////////////////////////////////