#include "functions.h"
#include <string.h>


const char * os_logo(const char *os_name) {
	const char *logo;

	if(strncmp(os_name,"arch",4) == 0) {
		logo = "\x1b[1;36m        /\\\n"
		       "       /  \\\n"
		       "      /    \\\n"
		       "     /      \\\n"
		       "    /        \\\n"
		       "   /    __    \\\n"
		       "  /   _/  \\_   \\\n"
		       " /_---      ---_\\\n\x1b[0m";
		return logo;
	}
	if (strncmp(os_name,"fedora",6) == 0) {
		logo = "   ________\n"
		       "  /     ___ \\\n"
		       " /     |   | \\\n"
		       "|  ____|___|  |\n"
		       "| |    |     /\n"
		       "| |____|    /\n"
		       "------------\n";
		return logo;
	}
	return "unknown";
}
