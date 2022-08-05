#!/bin/bash

# Terminate already running bar instances
killall -q polybar

# Launch Polybar, using default config location ~/.config/polybar/config
for m in $(polybar --list-monitors | cut -d":" -f1); do
    MONITOR=$m polybar bspwm 2>&1 | tee -a /tmp/polybar.log & disown
done
