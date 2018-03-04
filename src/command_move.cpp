#include "command_move.h"

Command_Move::Command_Move(int x, int y, Actor& player, GameMap& map) : 
	_x(x), _y(y), _player(player), _map(map) {

}

Command_Move::~Command_Move() {

}

void Command_Move::execute() {
	int r = _player.row() + _y;
	int c = _player.col() + _x;
	_map.add(_player, r, c);
}