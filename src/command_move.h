#ifndef COMMAND_MOVE_H_789d0fg78
#define COMMAND_MOVE_H_789d0fg78

#include "command.h"
#include "actor.h"
#include "frame.h"

class Command_Move : public Command {
public:
	// instantiate with move vector <x, y>
	Command_Move(int, int, Actor*, Frame*);
	~Command_Move();

	void execute();

private:
	int _x;
	int _y;
	Actor* _player;
	Frame* _map;
};

#endif