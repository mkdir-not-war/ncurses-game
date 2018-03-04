#ifndef INPUTHANDLER_H_70d6fg7098
#define INPUTHANDLER_H_70d6fg7098

#include <ncurses.h>

#include "command.h"
#include "command_move.h"
#include "actor.h"
#include "gamemap.h"

class InputHandler {
public:
	// get player actor and frame
	InputHandler(Actor&, GameMap&);
	~InputHandler();
	void handleInput(int);

private:
	Command* _key_up;
	Command* _key_down;
	Command* _key_left;
	Command* _key_right;
	//Command* _enter;
};

#endif