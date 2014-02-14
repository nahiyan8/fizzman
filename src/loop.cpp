#include "GameEngine.hpp"
#include <string>

////////////////////////////////////////////////////////////////////////////////

void GameEngine::loop()
{
	sf::Event event;
	sf::Clock delta_clock;
	
	while (state.running)
	{
		/* -- EVENT HANDLING -- */
		while (window.pollEvent(event))
			switch (event.type)
			{
				case sf::Event::Closed:
					window.close();
					state.running = false;
					return;
				
				default:
					break;
			}
		
		/* -- TIME MANAGEMENT -- */
		//std::cerr << '\r' << delta_clock.getElapsedTime().asSeconds();
		
		physics( 1.0f ); //delta_clock.getElapsedTime().asSeconds() );
		render();

		//delta_clock.restart();
		//sf::sleep(sf::milliseconds(1000));
	}
}

////////////////////////////////////////////////////////////////////////////////
