#ifndef MODULES_H
#define MODULES_H

const char *get_os_id();
const char *get_os_pretty_name();
float get_mem_total();
float get_mem_free();
float get_mem_used_total();
float get_mem_available();
const char * os_logo(const char *os_name);
int get_uptime(const char *type);
void print_formatted_uptime(int unformatted_time);

#endif
