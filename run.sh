#!/bin/bash
# run the game

GAMEDIR=./bin

if [ -e "$GAMEDIR/client" ] 
then
	xterm -fa 'Monospace' -fs 18 -e $GAMEDIR/client
else
	make
	xterm -fa 'Monospace' -fs 14 -e $GAMEDIR/client
fi