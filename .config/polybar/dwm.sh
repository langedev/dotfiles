#!/bin/sh

# Terminate already running bar instances
killall -q polybar

for m in $(polybar --list-monitors | cut -d":" -f1); do
    MONITOR=$m polybar dwm 2>&1 | tee -a /tmp/polybar.log & disown
done
