#include <stdio.h>
#include <stdbool.h>
#include <argp.h>

#include "GameEngine.hpp"
#include "diagnostics.hpp"

// Function prototypes: warranty void if used.
error_t parser(int key, char *argument, struct argp_state *state);

// argp related structs:
static const struct argp_option options[] =
{
	// NAME,    KEY, ARGNAME,   FLAGS, DOC
	{NULL,        0, NULL,          0, "Debugging options:",                                       0},
	{"debug",   'd', NULL,          0, "enable debug mode, and '--no-exit --output=d'",            0},
	{"no-exit", 'n', NULL,          0, "do not exit if a fatal error occurs",                      0},
	{"output",  'o', "<THRESHOLD>", 0, "set the threshold for outputting logs, threshold=[dinwf]", 0},
	{0, 0, 0, 0, 0, 0}
};

static const struct argp argp_config =
{
	options, &parser, NULL,
	"A SFML game about the wonderful life of Fizzman.",
	NULL, NULL, NULL
};


// Implementations:
int main(int argc, char *argv[])
{
	// Defaults:
	quit_on_error    = true;
	output_threshold = GAME_LOG_WARNING;
	
	// Using Argp to parse options, parameters:
	// ------- struct *argp, argc, *argv[], FLAGS, *NEXT_ARG_INDEX, *INPUT
	argp_parse(&argp_config, argc,    argv,     0,            NULL,   NULL);
	
	// Declare, initialise and run the engine!
	GameEngine engine;
	engine.loop();
	
	return 0;
}

// Argument handler, processes arguments using getopt_long.
error_t parser(int key, char *argument, struct argp_state *state)
{
	int temp;
	
	state = state;
	
	switch (key)
	{
		// --debug
		case 'd':
			quit_on_error    = false;
			output_threshold = GAME_LOG_DEBUG;
			break;
		
		// --no-exit
		case 'n':
			quit_on_error = false;
			break;
		
		// --output=<THRESHOLD>
		case 'o':
			while (temp < GAME_LOG_FATAL && argument[0] != error_level_str[temp][0])
				temp++;
			
			output_threshold = temp;
			break;
		
		// When we get an unknown option.
		default:
			return ARGP_ERR_UNKNOWN;
	}
	
	return 0;
}
