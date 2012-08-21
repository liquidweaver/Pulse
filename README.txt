# Pulse

By default, the network view refreshes very slowly. You can manually refresh the view in the menu.

## How the Network View Works
A zone transfer is requested for the given zone. 
After the zone transfer completes, all A records are traversed.
A tree structure is created from the TLD down to the hosts; domains and their
subdomains become expandable groups.
If a host record has a corresponding, space delimited TXT record, the values
in the record are expanded into approprate URL links to the left of the host.

## How the 'Hot Tickets' view works
Tickets are read every few minutes from the OpenERP database specified in
the settings. Each ticket has a weight, and the tickets that have a greater
weight than the value specified in the global ticket weight threshold will be
displated in descending order by weight. For every refresh, a notification
popup is requested by the operating system with a count of open tickets.