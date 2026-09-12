#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *get_os_id() {
	FILE *f = fopen("/etc/os-release", "r");	
	char os_id[50];
	char *name_malloc = malloc(sizeof(os_id));
	
	for(;(strncmp(name_malloc, "ID=",3) != 0);) {
		fgets(name_malloc, sizeof(os_id), f);
	}

	fclose(f);
	char name[50];
	strcpy(name, name_malloc);
	const char *name_return = name;
	free(name_malloc);
	return name_return;
}

const char *get_os_pretty_name() {	
	FILE *f = fopen("/etc/os-release", "r");	
	char line[50];
	char *key;
	char *value;
	while(fgets(line,sizeof(line),f)) {
		char *s = strchr(line,'=');
		if(s != NULL) {
			*s = '\0';
			key = line;
			value = s+1;
		}
		if(strcmp(key,"PRETTY_NAME") == 0) {
			char *q = strchr(value,'"');
			if(q != NULL) {
				char *q = strchr(value,'"'); // repeat 2 times to remove the double quotes
				*q = ' ';
				q = strchr(value,'"');
				*q = ' ';
			}
		break;
		}
	}
	fclose(f);
	return value;
}
