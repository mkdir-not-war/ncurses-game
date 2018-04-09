#!/bin/bash
# run the game

USRDIR=/home/${USER}/
GAMEDIR=./bin
FONTPATH=./res/fonts/PressStart2P-Regular.ttf

# check for fonts
if [ -e "$USRDIR/.fonts" ];
then
	if ! [ -e "$USRDIR/.fonts/PressStart2P-Regular.ttf" ];
	then
		sudo cp "$FONTPATH" "~/.fonts";
	fi
else
	sudo mkdir -p "~/.fonts";
	sudo cp "$FONTPATH" "~/.fonts";
fi

# check for game binary
if [ -e "$GAMEDIR/client" ];
then
	xterm -geometry 64x36 -fa 'PressStart2P-Regular' -fs 12 -e $GAMEDIR/client;
else
	make;
	xterm -geometry 64x36 -fa 'PressStart2P-Regular' -fs 12 -e $GAMEDIR/client;
fi