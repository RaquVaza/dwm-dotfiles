#!/bin/sh
while true; do
	DATE=$(date "+%b %d %H:%M")
	WEATHER=$(curl -s "wttr.in/Chelyabinsk?format=%c%t" 2>/dev/null || echo "N/A")
	xsetroot -name " $DATE $WEATHER "
	sleep 30
done
