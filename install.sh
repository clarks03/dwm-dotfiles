#!/bin/sh

# .config files

# Checking if the .config folder exists
echo "Checking for .config folder..."
if [ -f "$HOME"/.config ]; then
    echo ".config folder located."
else
    echo "No .config folder located."
    while true; do
        read -p "Do you wish to create one? [y/n] " yn
        case $yn in
            [Yy]* ) mkdir -p "$HOME"/.config; break;;
            [Nn]* ) echo "Aborting."; exit;;
            * ) echo "Please answer yes or no.";;
        esac
    done
fi
echo ""


# Adding dunst
# Check if dunst is installed
# (Not sure if this actually works)
echo "Checking if dunst is installed..."
if [ -f "/usr/bin/dunst" ]; then
    echo "dunst found"
else
    echo "dunst not installed."
    exit 1
fi

# Check if user already has a dunst config
echo "Checking for an existing dunst config..."
if [ -f "$HOME"/.config/dunst ]; then
    echo "dunst configuration found."
    while true; do
        read -p "Do you want to backup your config? [y/n] " yn
        case $yn in
            [Yy]* ) mv "$HOME"/.config/dunst "$HOME"/.config/dunst.bak; break;;
            *) break;;
        esac
    done
fi

# Install dunst config
echo "Installing dunst config..."
ln -sf "$HOME"/dwm-dotfiles/.config/dunst "$HOME"/.config/dunst
echo ""

# Adding kitty

# Check if kitty is installed
# (Not sure if this actually works)
echo "Checking if kitty is installed..."
if [ -f "/usr/bin/kitty" ]; then
    echo "kitty found"
else
    echo "kitty not installed"
    exit 1
fi

# Check if user already has a kitty config
echo "Checking for an existing kitty config..."
if [ -f "$HOME"/.config/kitty ]; then
    echo "kitty configuration found."
    while true; do
        read -p "Do you want to backup your config? [y/n] " yn
        case $yn in
            [Yy]* ) mv "$HOME"/.config/kitty "$HOME"/.config/kitty.bak; break;;
            *) break;;
        esac
    done
fi

# Install kitty config
echo "Installing kitty config..."
ln -s "$HOME"/dwm-dotfiles/.config/kitty "$HOME"/.config/kitty
echo ""


# Adding neovim

# Check if neovim is installed
# (Not sure if this actually works)
echo "Checking if neovim is installed..."
if [ -f "/usr/bin/nvim" ]; then
    echo "neovim found"
else
    echo "neovim not installed"
    exit 1
fi

# Check if user already has a neovim config
echo "Checking for an existing neovim config..."
if [ -f "$HOME"/.config/neovim ]; then
    echo "neovim configuration found."
    while true; do
        read -p "Do you want to backup your config? [y/n] " yn
        case $yn in
            [Yy]* ) mv "$HOME"/.config/nvim "$HOME"/.config/nvim.bak; break;;
            *) break;;
        esac
    done
fi

# Install neovim config
echo "Installing neovim..."
ln -s "$HOME"/dwm-dotfiles/.config/nvim "$HOME"/.config/nvim
echo ""

# Adding .zshrc

# Check if zsh is installed
echo "Checking if zsh is installed..."
if [ -f "/usr/bin/zsh" ]; then
    echo "zsh found"
else
    echo "zsh not found"
    exit 1
fi

# Check if zsh is default
echo "Checking if zsh is default..."
if [ $SHELL = "/usr/bin/zsh" ]; then
    echo "zsh is default shell"
else
    echo "zsh is not default."
    while true; do
        read -p "Do you want to change default shell to zsh? [y/n] " yn
        case $yn in
            [Yy]* ) chsh -s /usr/bin/zsh; break;;
            * ) break;;
        esac
    done
fi

# Check if user already has a .zshrc file
# (They probably do)
echo "Checking for existing .zshrc file..."
if [ -f "$HOME/.zshrc" ]; then
    echo ".zshrc found."
    while true; do
        read -p "Do you want to backup your config? [y/n] " yn
        case $yn in
            [Yy]* ) mv "$HOME"/.zshrc "$HOME"/.zshrc.bak; break;;
            * ) break;;
        esac
    done
fi

# Installing the .zshrc config
echo "Installing .zshrc config..."
ln -s "$HOME"/dwm-dotfiles/.zshrc "$HOME"/.zshrc
echo ""

# BONUS: check that they have krabby installed
echo "Checking if krabby is installed..."
if [ -f "$HOME"/.cargo/bin/krabby ]; then
    echo "krabby found. very awesome."
else
    echo "NOTE: krabby is not installed."
    echo "Install it at https://github.com/yannjor/krabby"
fi
echo ""


# Adding starship

# Check if starship is installed
# (Not sure if this actually works)
echo "Checking if starship is installed..."
if [ -f "/usr/local/bin/starship" ]; then
    echo "starship found"
else
    echo "starship not installed"
    exit 1
fi

# Check if user already has a starship config
echo "Checking for an existing starship config..."
if [ -f "$HOME"/.config/starship.toml ]; then
    echo "starship configuration found."
    while true; do
        read -p "Do you want to backup your config? [y/n] " yn
        case $yn in
            [Yy]* ) mv "$HOME"/.config/starship.toml "$HOME"/.config/starship.toml.bak; break;;
            *) break;;
        esac
    done
fi

# Install starship config
echo "Installing starship config..."
ln -s "$HOME"/dwm-dotfiles/.config/starship.toml "$HOME"/.config/starship.toml
echo ""


# .local files

# Adding src
# Checking if .local/src already exists
echo "Checking if user has a .local/src directory..."
if [ -f "$HOME"/.local/src ]; then
    echo "~/.local/src found"
    for f in $(/bin/ls $(pwd)/.local/src); do
        echo "Linking ${f}..."
        ln -s $(pwd)/.local/src/"$f" "$HOME"/.local/src/"$f"
    done
else
    echo "~/.local/src not found. Linking whole directory..."
    ln -s "$HOME"/dwm-dotfiles/.local/src "$HOME"/.local/src
fi

# Ask if they want to remake dwm
while true; do
    read -p "Do you want to remake dwm? [y/n] " yn
    case $yn in
        [Yy]* ) cd .local/src/dwm; sudo make clean install; cd ../../..; break;;
        * ) break;;
    esac
done

# Ask if they want to remake dmenu
while true; do
    read -p "Do you want to remake dmenu? [y/n] " yn
    case $yn in
        [Yy]* ) cd .local/src/dmenu; sudo make clean install; cd ../../..; break;;
        * ) break;;
    esac
done

# Ask if they want to remake slstatus
while true; do
    read -p "Do you want to remake slstatus? [y/n] " yn
    case $yn in
        [Yy]* ) cd .local/src/slstatus; sudo make clean install; cd ../../..; break;;
        * ) break;;
    esac
done


# Adding bin
# Checking if .local/bin already exists
echo "Checking if user has a .local/bin directory..."
if [ -f "$HOME"/.local/bin ]; then
    echo "~/.local/bin found"
    for f in $(/bin/ls $(pwd)/.local/bin); do
        echo "Linking ${f}..."
        ln -s $(pwd)/.local/bin/"$f" "$HOME"/.local/bin/"$f"
    done
else
    echo "~/.local/bin not found. Linking whole directory..."
    ln -s "$HOME"/dwm-dotfiles/.local/bin "$HOME"/.local/bin
fi

# Check if .local/bin is in the path
if [[ $PATH ~= "${HOME}/.local/bin" ]]; then
    echo "WARNING: ~/.local/bin is not included in your path. Here be dragons!"
fi

