#ifndef GLOBAL_DEFINES_H
#define GLOBAL_DEFINES_H

//Pulse version
#define PULSE_VERSION ".15TZ"
//Compatible settings?
#define PULSE_SETTINGS_SERIAL 2


//* NOTE ALL TIME VALUES IN MILLISECONDS

//Period to reload zone/tickets on error
#define ERROR_REFRESH_INTERVAL 20*1000

#define STATUSBAR_ERROR_LINGER 15*1000

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
#define DEFAULT_ZONES \
{ "customer.mp", "baur.mp", "tucker.mp", NULL }
#define DEFAULT_SERVICES_WINDOWS \
{  "ping", "#", "C:/Windows/System32/PING.EXE", \
   "rdp", "/v #", "C:/Windows/System32/mstsc.exe", \
   "netbios-ssn", "\\\\#", "C:/Windows/System32/explorer.exe", \
   "telnet", "-telnet #", "C:/Program Files (x86)/PuTTY/putty.exe", \
   "ssh", "-ssh #", "C:/Program Files (x86)/PuTTY/putty.exe", \
   "shell", "-rlogin #", "C:/Program Files (x86)/PuTTY/putty.exe", \
   "http", "#", "C:/Program Files/Internet Explorer/iexplore.exe", \
   "https", "#", "C:/Program Files/Internet Explorer/iexplore.exe", \
   NULL }
#define DEFAULT_SERVICES_LINUX \
{  "ping", "-x /bin/ping -c5 #", "/usr/bin/gnome-terminal", \
   "rdp", "#", "/usr/bin/rdesktop", \
   "netbios-ssn", "smb://#", "/usr/bin/nautilus", \
   "vnc", "#", "/usr/bin/vncviewer", \
   "ssh", "-x /usr/bin/ssh -l administrator #", "/usr/bin/gnome-terminal", \
   NULL }

#endif // GLOBAL_DEFINES_H
