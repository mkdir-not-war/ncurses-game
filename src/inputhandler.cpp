#include "inputhandler.h"

InputHandler::InputHandler(Actor* player, GameMap* map) {
	_key_up = new Command_Move(0, -1, player, map);
	_key_down = new Command_Move(0, 1, player, map);
	_key_left = new Command_Move(-1, 0, player, map);
	_key_right = new Command_Move(1, 0, player, map);
}

InputHandler::~InputHandler() {
	delete _key_up;
	delete _key_down;
	delete _key_left;
	delete _key_right;
}

#include <iostream>
#include <fstream>
void InputHandler::handleInput(int ch) {
	if (ch == KEY_LEFT) {
		_key_left->execute();
	}
	else if (ch == KEY_RIGHT) {
		_key_right->execute();
	}
	else if (ch == KEY_UP) {
		_key_up->execute();
	}
	else if (ch == KEY_DOWN) {
		_key_down->execute();
	}
	else if (ch == 'q' || ch == 'Q') {
		
	} 
}

