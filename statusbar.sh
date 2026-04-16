#!/bin/sh
while true; do
	DATETIME=$(LC_ALL=C date "+%b %d %H:%M")

	xsetroot -name $DATETIME
	sleep 30
done
