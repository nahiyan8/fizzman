#include "GameEngine.hpp"

////////////////////////////////////////////////////////////////////////////////

void GameEngine::render()
{
	window.clear(sf::Color::White);
	
	for (uint slot = 0; slot < sprites.getSize(); ++slot)
	{
		if ( sprites.isUsed(slot) == true )
			window.draw(sprites[slot]);
	}
		
	window.display();
}

////////////////////////////////////////////////////////////////////////////////