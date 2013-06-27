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
	strftime(line, sizeof(line), "(%Y/%m/%d %X)", localtime(&now));

	// append process data and level

	switch(level){
	case DEBUG_LEVEL_ERROR   : _level = "ERROR";   break;
	case DEBUG_LEVEL_WARNING : _level = "WARNING"; break;
	case DEBUG_LEVEL_NOTIFY  : _level = "NOTIFY";  break;
	case DEBUG_LEVEL_INFO    : _level = "INFO";    break;
	default : _level = "INFO"; break;
	}


	sprintf(line+strlen(line), "[%s] %s: ", function, _level);

	va_start(arg, format);
	vsprintf(line+strlen(line), format, arg);
	va_end(arg);

	fprintf(stdout,"%s\n",line);
}
