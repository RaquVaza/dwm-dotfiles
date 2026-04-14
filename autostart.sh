#!/bin/sh
xrandr --output DP-0 --mode 2560x1440 --pos 0x0 --rate 144 --rotate normal --output DP-4 --primary --mode 2560x1440 --pos 2560x0 --rate 165 --rotate normal &
nm-applet &
blueman-applet &
feh --bg-scale /home/zer0day/Pictures/Wallpapers/jesus.jpg &

