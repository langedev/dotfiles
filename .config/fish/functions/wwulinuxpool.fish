# Defined via `source`
function wwulinuxpool --wraps='ssh -p 922 -Y langed@linux-07.cs.wwu.edu' --description 'alias wwulinuxpool ssh -p 922 -Y langed@linux-07.cs.wwu.edu'
  ssh -p 922 -Y langed@linux-07.cs.wwu.edu $argv; 
end
