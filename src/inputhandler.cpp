#include "inputhandler.h"

InputHandler::InputHandler(Actor& player, GameMap& map) :
	_try_again(false), _help(false), _confirm_input(false) {
	_key_up = new Command_Move(0, -1, player, map);
	_key_down = new Command_Move(0, 1, player, map);
	_key_left = new Command_Move(-1, 0, player, map);
	_key_right = new Command_Move(1, 0, player, map);
	//_key_home = new Command_
	//_key_end = new Command_
	//_key_inc = new Command_
	_key_mouse_right = new Command_DescribeTile(map);
}

InputHandler::~InputHandler() {
	delete _key_up;
	delete _key_down;
	delete _key_left;
	delete _key_right;
	//delete _key_home;
	//delete _key_end;
	//delete _key_inc;
	delete _key_mouse_right;
}

void InputHandler::printHelp() {
	TextConsole::clear();

	TextConsole::print(_key_up->toString("UP"));
	TextConsole::print(_key_down->toString("DOWN"));
	TextConsole::print(_key_left->toString("LEFT"));
	TextConsole::print(_key_right->toString("RIGHT"));

	TextConsole::print(_key_mouse_right->toString("MOUSE R CLICK"));

	TextConsole::print("");
	TextConsole::print("Press h to exit help.");
}

void InputHandler::handleInput(int ch) {
	MEVENT event;
	do {
		// if invalid input, get new input
		if (_try_again) {
			ch = getch();
		}

		// assume this input will be valid
		_try_again = false;

		// check to leave the game no matter the state
		if (ch == 'q' || ch == 'Q') {
			exit(0);
		}

		// check states to determine input response
		if (_help) {
			if (ch == 'h' || ch == 'H') {
				TextConsole::clear();
				_help = false;
			}
			else {
				_try_again = true;
			}
		}
		else {
			if (_confirm_input) {
				if (ch == 'y' || ch == 'Y') {
					_confirm_input = false;
					// _key_mouse_left->execute();
				}
				else if (ch == 'n' || ch == 'N') {
					_confirm_input = false;
				}
				else {
					_try_again = true;
				}
			}
			else {
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
				else if (ch == KEY_MOUSE) {
					if (getmouse(&event) == OK) {
						if (event.bstate & BUTTON1_PRESSED) {
							TextConsole::print("Left mouse click");
						}
						else if (event.bstate & BUTTON3_PRESSED) {
							// this command requires x and y coordinates
							_key_mouse_right->execute(event.x, event.y);
						}
						else 
						{

						}
					}
				}
				else if (ch == KEY_HOME) {
					//_key_home->execute();
					TextConsole::print("poop");
				}
				else if (ch == KEY_END) {
					//_key_end->execute();
					TextConsole::pop();
				}
				else if (ch == KEY_IC) {
					TextConsole::clear();
				}
				else if (ch == 'h' || ch == 'H') {
					printHelp();
					_help = true;
				}
				else {
					TextConsole::print(std::to_string(ch));
					_try_again = true;
				}
			}
		}
	} while (_try_again);
}

