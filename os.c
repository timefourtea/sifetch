#include "functions.h"
#include <stdio.h>
#include <string.h>

const char *get_os_id() {
	FILE *f = fopen("/etc/os-release", "r");	
	char line[50];
	char *value;
	while(fgets(line,sizeof(line),f)) {
		if(strncmp(line,"ID",2) == 0) {
			char *s = strchr(line, '=');
			value = s+1;
			break;
		}
	}
	fclose(f);
	return value;
}

const char *get_os_pretty_name() {	
	FILE *f = fopen("/etc/os-release", "r");	
	char line[50];
	char *value;
	while(fgets(line,sizeof(line),f)) {
		char *s = strchr(line,'=');
		if(s != NULL) {
			value = s+1;
		}
		if(strncmp(line,"PRETTY_NAME",11) == 0) {
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
