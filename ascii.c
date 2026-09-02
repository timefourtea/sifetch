#include "functions.h"
#include <string.h>


const char * os_logo(const char *os_name) {
	static const char *logo;

	if(strncmp(os_name,"ID=arch",7) == 0) {
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
	if (strncmp(os_name,"ID=fedora",9) == 0) {
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
