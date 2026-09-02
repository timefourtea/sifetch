#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *get_os_id() {
	FILE *f = fopen("/etc/os-release", "r");	
	char os_id[50];
	char *name = malloc(sizeof(os_id));
	
	for(;(strncmp(name, "ID=",3) != 0);) {
		fgets(name, sizeof(os_id), f);
	}

	fclose(f);
	const char *name_return = name;
	return name_return;
}

const char *get_os_pretty_name() {	
	FILE *f = fopen("/etc/os-release", "r");	
	char os_name[50];
	char *name = malloc(sizeof(os_name));
	
	for(;(strncmp(name, "PRETTY_NAME=",5) != 0);) {
		fgets(name, sizeof(os_name), f);
	}

	fclose(f);
	const char *name_return = name;
	return name_return;
}
