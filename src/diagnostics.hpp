#ifndef DIAGNOSTICS_HPP_INCLUDED
#define DIAGNOSTICS_HPP_INCLUDED

#include <stdbool.h>
#include <error.h>

enum error_level_t {
	GAME_LOG_DEBUG   = 0,
	GAME_LOG_INFO    = 1,
	GAME_LOG_NOTICE  = 2,
	GAME_LOG_WARNING = 3,
	GAME_LOG_FATAL   = 4
};

static const char error_level_str[][8] = {
	"debug",
	"info",
	"notice",
	"warning",
	"fatal",
};

// Exit on error if (quit == true); And output if (level >= output_threshold).
extern bool quit_on_error;
extern int  output_threshold;

////////////////////////////////////////////////////////////////////////////////
/// @brief: Wrapper for error_at_line(), to check thresholds before calling it.
////////////////////////////////////////////////////////////////////////////////
#define ReportLog(level, file, line, message)                                  \
    do {                                                                       \
      if (level >= output_threshold)                                           \
      {                                                                        \
        error_at_line(                                                         \
                       (level >= GAME_LOG_FATAL && quit_on_error ? level : 0), \
                       0, file, line,                                          \
                       "%s: %s", error_level_str[level], message               \
                     );                                                        \
      }                                                                        \
    } while (0)

#endif
