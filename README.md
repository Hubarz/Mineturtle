Mineturtle
==========
Overview
--------
Mineturtle is a HTTP DoS tool using the slow-header technique. It's in beta phase, so there may be bugs and many planned features are outstanding.
Anyway I think it's a bit more effective than Slowloris.

Usage
-----
The minimal command is 'mineturtle -h host'. It will build 1000 connections every 30 seconds.
Parameter cheat sheet:
-help: Shows this message.
-test: Switch to test mode to find out the optimal value for -t
-h: Hostname or IP address.
-p: Port. DEFAULT: 80
-c: Count of connections. DEFAULT: 1000
-t: Time to hold each connection. (Find out with -test). DEFAULT: 30
-u: User-Agent string to use. DEFAULT: A randomly chosen string out of a list

_*A complete documentation will follow*_
========================================
