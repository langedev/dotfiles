function wwuvpn --wraps='sudo openvpn ~/.config/fish/CSCI-VPN.ovpn' --description 'alias wwuvpn sudo openvpn ~/.config/fish/CSCI-VPN.ovpn'
  sudo openvpn ~/.config/fish/CSCI-VPN.ovpn $argv; 
end
