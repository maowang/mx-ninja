#include "debug.h"
#include <stdarg.h>
#include <time.h>
#include <string.h>
#include <stdio.h>

static int rvr_debug = DEBUG_LEVEL_INFO;

void debug_set_level(int lvl) {
	rvr_debug = lvl > DEBUG_LEVEL_INFO ? DEBUG_LEVEL_INFO : lvl;
}


void debug(int level, const char *function, const char *format, ...){
	const char *_level;
	char line[512];
	time_t now;
	// append actual message
	va_list arg;

	if (rvr_debug < level)
		return;

	// append time
	time(&now);
	strftime(line, sizeof(line), "(%d:%m:%Y -- %T)", localtime(&now));

	// append process data and level

	switch(level){
	case DEBUG_LEVEL_ERROR   : _level = "ERROR";   break;
	case DEBUG_LEVEL_WARNING : _level = "WARNING"; break;
	case DEBUG_LEVEL_NOTIFY  : _level = "NOTIFY";  break;
	case DEBUG_LEVEL_INFO    : _level = "INFO";    break;
	default : _level = "INFO"; break;
	}


	sprintf(line+strlen(line), "[%u,%s] %s: ", getpid(), function, _level);

	va_start(arg, format);
	vsprintf(line+strlen(line), format, arg);
	va_end(arg);

	printf(line);
}

void debug_append(int level, const char *format, ...) {

	va_list arg;
	char line[512] = {0};

	if (rvr_debug < level)
		return;

	va_start(arg, format);
	vsprintf(line+strlen(line), format, arg);
	va_end(arg);

	printf(line);
}
