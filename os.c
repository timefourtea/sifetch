#include "functions.h"
#include <stdio.h>
#include <string.h>

const char *get_os_id() {
	FILE *f = fopen("/etc/os-release", "r");	
	char line[50];
	char *key;
	char *value;
	while(fgets(line,sizeof(line),f)) {
		char *s = strchr(line, '=');
		if(s != NULL) {
			*s = '\0';
			key = line;
			value = s+1;
		}
		if(strcmp(key,"ID") == 0) {
			break;
		}
	}
	fclose(f);
	return value;
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
