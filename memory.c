#include "modules.h"
#include <stdio.h>
#include <string.h>

float get_mem_total() {
	long unsigned mem_kb; 
	long unsigned *m = &mem_kb;
	FILE *f = fopen("/proc/meminfo", "r"); 

	for(;;) {
		char key[50];
		fscanf(f, "%s %lu",key,m);
		if(strncmp(key,"MemTotal",8) == 0) {
			break;
		}
	}
	fclose(f);
	float mem_gb = (float)mem_kb / 1048576;
	return mem_gb;
}

float get_mem_free() {
	long unsigned mem_kb; 
	long unsigned *m = &mem_kb;
	FILE *f = fopen("/proc/meminfo", "r"); 

	for(;;) {
		char key[50];
		fscanf(f, "%s %lu",key,m);
		if(strncmp(key,"MemFree",7) == 0) {
			break;
		}
	}
	fclose(f);
	float mem_gb = (float)mem_kb / 1048576;
	return mem_gb;
}

float get_mem_used_total() {
	return get_mem_total() - get_mem_free();
}

float get_mem_available() {
	long unsigned mem_kb;
	long unsigned *m = &mem_kb;
	FILE *f = fopen("/proc/meminfo", "r");

	for(;;) {
		char key[50];
		fscanf(f, "%s %lu",key,m);
		if(strncmp(key,"MemAvailable",12) == 0) {
			break;
		}
	}
	fclose(f);
	float mem_gb = (float)mem_kb / 1048576;
	return mem_gb;
}
