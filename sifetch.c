#include "functions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define VERSION "sifetch v0.1.0"

int main(int argc, char *argv[]) {
	if(argc > 1) {
		if(strcmp(argv[1],"version") == 0) {
			printf(VERSION"\n");
			return 0;
		}
	}
	printf("\n%s\n",os_logo(get_os_id()));
	printf("Operating system:%s",get_os_pretty_name());
	printf("Total RAM: %.2f GB\n",get_mem_total());
	printf("RAM free: %.2f GB\n", get_mem_free());
	printf("Total RAM used: %.2f GB\n", get_mem_used_total());
	printf("Uptime: ");
	print_formatted_uptime(get_uptime("system"));
	if(getenv("XDG_CURRENT_DESKTOP") != NULL)
		printf("Desktop: %s\n", getenv("XDG_CURRENT_DESKTOP"));	
	if(getenv("XDG_SESSION_TYPE") != NULL)
	printf("Display protocol: %s\n", getenv("XDG_SESSION_TYPE"));
}
