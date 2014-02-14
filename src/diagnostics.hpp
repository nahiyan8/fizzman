#ifndef DIAGNOSTICS_HPP_INCLUDED
#define DIAGNOSTICS_HPP_INCLUDED

#include <stdbool.h>
#include <error.h>

enum log_level_t {
	GAME_LOG_QUIET   = 0, // Pseudo-level, there will be no output.
	GAME_LOG_FATAL   = 1, // Unrecoverable error. e.g. segfaults.
	GAME_LOG_WARNING = 2, // Recoverable error or inconsistency.
	GAME_LOG_NOTICE  = 3, // Information about major normal events.
	GAME_LOG_INFO    = 4, // Information about minor unimportant things.
	GAME_LOG_DEBUG   = 5  // Too Much Information. (tm)
};

static const char log_level_str[][8] = {
	"quiet", "debug", "info", "notice", "warning", "fatal",
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
        if (level <= log_threshold)                                            \
        {                                                                      \
            error_at_line(                                                     \
                          0, 0, __FILE__, __LINE__,                            \
                          "%s: %s", log_level_str[level], message              \
                         );                                                    \
        }                                                                      \
                                                                               \
        if (level == GAME_LOG_FATAL && log_exit)                               \
            exit()                                                             \
    } while (0)

#endif
