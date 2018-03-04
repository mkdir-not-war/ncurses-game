#ifndef COMMAND_MOVE_H_789d0fg78
#define COMMAND_MOVE_H_789d0fg78

#include "command.h"
#include "actor.h"
#include "gamemap.h"

struct Vector2i {
	int x;
	int y;
};

class Command_Move : public Command {
public:
	// instantiate with move vector <x, y>
	Command_Move(int, int, Actor&, GameMap&);
	~Command_Move();

	void execute();

private:
	Vector2i _dir;
	Actor& _player;
	GameMap& _map;
};

#endif