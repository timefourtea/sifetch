#ifndef FUNCTIONS_H
#define FUNCTIONS_H

const char *get_os_id();
const char *get_os_pretty_name();
float get_mem_total();
float get_mem_free();
float get_mem_used_total();
const char * os_logo(const char *os_name);
int get_uptime(const char *type);
int format_uptime_h(int unformatted_time);
void print_formatted_uptime(int unformatted_time);

#endif
