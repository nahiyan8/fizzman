#ifndef DIAGNOSTICS_HPP_INCLUDED
#define DIAGNOSTICS_HPP_INCLUDED

#include <stdbool.h>
#include <error.h>

enum log_level_t {
	GAME_LOG_DEBUG   = 0,
	GAME_LOG_INFO    = 1,
	GAME_LOG_NOTICE  = 2,
	GAME_LOG_WARNING = 3,
	GAME_LOG_FATAL   = 4
};

static const char log_level_str[][8] = {
	"debug",
	"info",
	"notice",
	"warning",
	"fatal",
};

// log_threshold: Sets the minimum message level required for output.
// log_exit:      Determines whether the game exits on a fatal error.
extern bool log_exit;
extern int  log_threshold;

////////////////////////////////////////////////////////////////////////////////
/// @brief: Wrapper for error_at_line(), for convenience.
////////////////////////////////////////////////////////////////////////////////
#define ReportLog(level, message)                                              \
    do {                                                                       \
        if (level >= log_threshold)                                            \
        {                                                                      \
            error_at_line(                                                     \
                          (level >= GAME_LOG_FATAL && log_exit ? level : 0),   \
                                                                               \
                          0, __FILE__, __LINE__,                               \
                                                                               \
                          "%s: %s", log_level_str[level], message              \
                         );                                                    \
       }                                                                       \
    } while (0)

#endif
