#include <stdio.h>
#include <stdbool.h>
#include <argp.h>

#include "GameEngine.hpp"
#include "diagnostics.hpp"

// Function prototypes: warranty void if used.
error_t parser(int key, char *argument, struct argp_state *state);

// argp related structs:
static const struct argp_option argp_options[] =
{
	// NAME,    KEY, ARGNAME, FLAGS, DOC,                                       GROUP;
	{NULL,        0, NULL,    0,     "Debugging options:",                         0},
	{"no-exit", 'n', NULL,    0,     "do not exit if a fatal error occurs",        0},
	{"quiet",   'q', NULL,    0,     "decrease verbosity, -qq to disable output.", 0},
	{"verbose", 'v', NULL,    0,     "increase verbosity, effective upto -vvv",    0},
	{0, 0, 0, 0, 0, 0}
};

static const struct argp argp_config =
{
	argp_options, &parser, NULL, "A game about the wonderful life of Fizzman.", NULL, NULL, NULL
};


// Implementations:
int main(int argc, char *argv[])
{
	// Defaults:
	log_exit      = true;
	log_threshold = GAME_LOG_WARNING;
	
	argp_parse(&argp_config, argc, argv, 0, NULL, NULL);
	
	// Declare, initialise and run the engine!
	GameEngine engine;
	engine.loop();
	
	return 0;
}

// Argument handler, processes arguments using argp.
error_t parser(int key, char *argument, struct argp_state *state)
{
	switch (key)
	{
		// --no-exit
		case 'n':
			log_exit = false;
			break;
		
		// --quiet
		case 'q':
			log_threshold--;
			break;
		
		// --verbose
		case 'v':
			log_threshold++;
			break;
		
		// When we get an unknown option.
		default:
			return ARGP_ERR_UNKNOWN;
	}
	
	// These statements "use" the variables, so we don't get "unused var" warnings.
	(void) argument;
	(void) state;
	
	return 0;
}
