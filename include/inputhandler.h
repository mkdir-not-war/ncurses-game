#ifndef INPUTHANDLER_H_70d6fg7098
#define INPUTHANDLER_H_70d6fg7098

#include <config.h>
#include "textconsole.h" // use for debugging

#include "command.h"
#include "command_move.h"
#include "command_describetile.h"
#include "actor.h"
#include "gamemap.h"

#define KEY_NUMPAD_ZERO		48
#define KEY_NUMPAD_ONE		49

class InputHandler {
public:
	// get player actor and frame
	InputHandler(Actor&, GameMap&);
	~InputHandler();
	void handleInput(int);
	void printHelp();

private:
	Command* _key_up;
	Command* _key_down;
	Command* _key_left;
	Command* _key_right;
	//Command* _key_home;
	//Command* _key_end;
	//Command* _key_inc;
	Command* _key_mouse_right;
	//Command* _key_mouse_left;

	// get rid of this var once gamestates are made 
	// with subclasses of inputhandler (strategy pattern)
	bool _help;
	bool _confirm_input;
	bool _try_again;
};

#endif