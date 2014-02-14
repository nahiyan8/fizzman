#include "GameEngine.hpp"

////////////////////////////////////////////////////////////////////////////////

void GameEngine::loop()
{
	/* -- VARIABLES -- */
	sf::Event event;
	
	float time_accumulator = 0;
	sf::Clock delta_clock;
	
	/* -- INITIALISATION -- */
	ReportLog(GAME_LOG_NOTICE, "starting main game loop");
	
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
		while (time_accumulator >= settings.physics_step)
			physics(settings.physics_step);
		
		
		render();
		
		time_accumulator += delta_clock.getElapsedTime().asSeconds();
		                    delta_clock.restart();
		
		sf::sleep(sf::seconds(settings.render_step));
	}
}

////////////////////////////////////////////////////////////////////////////////
