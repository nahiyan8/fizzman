#include <iostream>
#include <SFML/Graphics.hpp>
#include "pool.hpp"

int main()
{
	/* ---- Variable declarations & initialisation ---- */
	sf::RenderWindow window(sf::VideoMode(1280, 800), "FizzMan");
	sf::Event event;
	
	bool running = true, menu;
	sf::Clock delta_clock; float delta_time;
	
	Pool <sf::Texture> texturePool(4096);
	Pool <sf::Sprite> spritePool(4096);
	
	Pool <sf::Vector2f> velPool(4096);
	
	/* - Player initialisation - */
	int playerSlot = spritePool.allocate(); texturePool.allocate(); velPool.allocate();
	
	if (playerSlot == -1)
	{
		std::cout << __FILE__ << ':' << __LINE__ << ": fatal: unable to allocate for player, please contact this universes' administrator, exiting..\n";
		return 1;
	}
	
	if (!texturePool[playerSlot]->loadFromFile("data/player.png"))
	{
		std::cout << __FILE__ << ':' << __LINE__ << ": fatal: unable to load player's texture, exiting..\n";
		return 1;
	}
	
	spritePool[playerSlot]->setTexture( *texturePool[playerSlot] );
	//spritePool[playerSlot]->setTextureRect(sf::IntRect(0, 0, 64, 64));
	
	/* ---- Main loop ---- */
	while (running && window.isOpen())
	{
		/* - Event handling - */
		while (window.pollEvent(event))
			switch (event.type)
			{
				// Close if we get a closing request/event
				case sf::Event::Closed:
					window.close();
					running = false;
					break;
			}
			
		// Handle player movement
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) velPool[playerSlot]->x -= 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) velPool[playerSlot]->x += 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) velPool[playerSlot]->y -= 1.0f;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) velPool[playerSlot]->y += 1.0f;
		
		/* - Physics - */
		delta_time = delta_clock.getElapsedTime().asSeconds();
		sf::Vector2f tempPos;
		
		for ( uint slot; slot < spritePool.getSize(); ++slot )
			if (spritePool.isAvailable(slot) == false)
			{
				// GRAVITY!!
				velPool[slot]->y += 10.0f;
				
				// Atmospheric drag!
				velPool[slot]->x *= 0.90f;
				velPool[slot]->y *= 0.90f;
				
				// Yes it's euler integration, go away! D:
				tempPos = spritePool[slot]->getPosition() + ((*velPool[slot]) * delta_time);
				
				// Bounce shit off from the bounds!
				if (tempPos.x < 0 || tempPos.x >= window.getSize().x) velPool[slot]->x *= -0.80f;
				if (tempPos.y < 0 || tempPos.y >= window.getSize().y) velPool[slot]->y *= -0.80f;
				
				// Recalculate incase anything was changed from the check above!
				tempPos = spritePool[slot]->getPosition() + ((*velPool[slot]) * delta_time);
				
				// Set the position!
				spritePool[slot]->setPosition( tempPos );
			}
					
		
		/* - Rendering - */
		window.clear(sf::Color::White);
		
		for (uint slot = 0; slot < spritePool.getSize(); ++slot)
			if (spritePool.isAvailable(slot) == false)
				window.draw(*spritePool[slot]);
		
		window.display();
	}
	
	std::cout << __FILE__ << ':' << __LINE__ << ": notice: exiting normally...";	
	return 0;
}
