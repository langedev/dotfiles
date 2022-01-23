#!/bin/sh

# Terminate already running bar instances
killall -q polybar

# Launch Polybar, using default config location ~/.config/polybar/config
polybar dwm 2>&1 | tee -a /tmp/polybar.log & disown
