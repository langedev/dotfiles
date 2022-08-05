#!/bin/fish

bspc wm --add-monitor virtual 500x500+5120+0
bspc monitor virtual -d $BSPWM_VIRTUAL

bspc monitor DP-2 -d $BSPWM_DEFAULT
bspc monitor DP-0 -d $BSPWM_DEFAULT

# Reorder monitors
bspc wm --reorder-monitors DP-2 DP-0 virtual

set monitor_ids (bspc query -M)
set virtual_monitor_id $monitor_ids[3]

set virtual_desktop_ids (bspc query -m virtual -D)
set virtual_desktop_names (bspc query -m virtual -D --names)
set DP_2_desktop_names (bspc query -m DP-2 -D --names)
set DP_0_desktop_names (bspc query -m DP-0 -D --names)

bspc subscribe node_add node_remove | while read -l line
  set event $line[1]
  set monitor_id $line[2]
  set desktop_id $line[3]

  switch $event
    case node_add
      if test $virtual_monitor_id = $monitor_id
        # Node was added to a virtual monitor, need to unvirtualize it
        set desktop_name ""

        #Identify what desktop it was
        for i in (seq (count $virtual_desktop_ids))
          if test $virtual_desktop_ids[i] = $desktop_id
            set desktop_name $virtual_desktop_names[i]
          end
        end

        bspc desktop $desktop_name --to-monitor DP-2
        bspc monitor DP-2 --reorder-desktops home web chat note read med zoom etc
      end
    case node_remove

  end
end
