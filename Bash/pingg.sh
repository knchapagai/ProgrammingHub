#!/bin/bash
wget -q --spider http://google.com
[ "$?" -eq 0 ] && echo -e "\e[36m   Net is on"|| echo " Net is off"
