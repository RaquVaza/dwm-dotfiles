#!/bin/sh
xrandr --output DP-0 --mode 2560x1440 --pos 0x0 --rate 144 --rotate normal --output DP-4 --primary --mode 2560x1440 --pos 2560x0 --rate 165 --rotate normal &

sleep 2 &
nm-applet &
blueman-applet &

unclutter --hide-on-key-press &

while ! xdpyinfo >/dev/null 2>&1; do sleep 0.3; done

export DISPLAY="${DISPLAY:-:0}"
/nix/store/15sbm9ngybg5k2avixb7gdxf0avyi3w3-feh-3.11.2/bin/feh --bg-scale /home/zer0day/Pictures/Wallpapers/jesus.jpg &
