#ifndef GLOBAL_DEFINES_H
#define GLOBAL_DEFINES_H

//Pulse version
#define PULSE_VERSION ".11A"
//Compatible settings?
#define PULSE_SETTINGS_SERIAL 1


//* NOTE ALL TIME VALUES IN MILLISECONDS

//Period to reload zone/tickets on error
#define ERROR_REFRESH_INTERVAL 20*1000

//Period length for zone refresh
#define ZONE_REFRESH_INTERVAL 6*60*60*1000

//Period length for ticket refresh
#define TICKET_REFRESH_INTERVAL 3*60*1000

//Period length for whos working refresh
#define TECH_REFRESH_INTERVAL 1*60*1000

#define SETTING_SERIAL "main/pulse_settings_serial"
#define SETTING_ZONE "network/zone"
#define SETTING_MERP_HOST "tickets/merp_host"
#define SETTING_DB_NAME "tickets/db_name"
#define SETTING_DB_USER "tickets/db_user"
#define SETTING_DB_PASS "tickets/db_pass"

#define DEFAULT_SERVICES_WINDOWS \
{   "ping", "#", "C:/Windows/System32/PING.EXE", \
    "rdp", "/v #", "C:/Windows/System32/mstsc.exe", \
    "smb", "\\#", "C:/Windows/System32/explorer.exe", NULL }

#endif // GLOBAL_DEFINES_H
