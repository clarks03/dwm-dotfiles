# My Fedora + DWM Rice

### Screenshots
![](./assets/rice1.png)
![](./assets/rice2.png)
---
### Dependencies
- neovim
- zsh
- starship
- oh my zsh
- zsh-autosuggestions
- zsh-syntax-highlighting
- kitty
- dunst
- JetBrainsMono Nerd Font
- Iosevka Nerd Font
- pulseaudio-utils (for `pactl`)
- exa
- rust

#### Post-install
- krabby
(This is because cargo is already added to my path via. the .zshrc, so if you don't want to manually add something to the path before running the script, you can run it after the script.)

### Installation
**NOTE:** This script worked for me on a newly spun Fedora VM. It **should** work for you, but if you want to be safe, you can always install the dots manually.

Execute the following commands:
```sh
git clone https://github.com/clarks03/dwm-dotfiles.git
cd dwm-dotfiles.git
chmod +x install.sh
./install.sh
```

And follow along with the prompts.
