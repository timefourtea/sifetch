#include "functions.h"
#include <stdio.h>
#include <string.h>

int get_uptime(const char *type) {
	FILE *f = fopen("/proc/uptime", "r");

	float system_uptime;
	float *su = &system_uptime;
	float idle_uptime;
	float *iu = &idle_uptime;

	fscanf(f,"%f %f", su, iu);
	fclose(f);

	if(strcmp(type,"system") == 0)
		return system_uptime;

	if(strcmp(type,"idle") == 0)
		return idle_uptime;

	return 1;
}

int format_uptime_h(int unformatted_time) {
	int formatted_time = unformatted_time / 3600;
	formatted_time = (formatted_time < 1) ? 0: formatted_time;
	return formatted_time;
}

void print_formatted_uptime(int unformatted_time) {
	int day = 0;
	int hour = 0;
	int minute = 0;
	int second = unformatted_time;

	while(second >= 60) {
		second -= 60;
		++minute;
	}
	while(minute >= 60) {
		minute -= 60;
		++hour;
	}

	while(hour >= 24) {
		hour -= 24;
		++day;
	}

	if(day == 1)
		printf("%d day ", day);
	if(day > 1)
		printf("%d days ", day);

	if(hour <= 1)
		printf("%d hour",hour);
	else
		printf("%d hours", hour);

	if(minute <= 1)
		printf(" %d minute", minute);
	else
		printf(" %d minutes", minute);

	if(second <= 1)
		printf(" %d second\n", second);
	else
		printf(" %d seconds\n", second);
}
