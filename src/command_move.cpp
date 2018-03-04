#include "command_move.h"

Command_Move::Command_Move(int x, int y, Actor& player, GameMap& map) : 
	_player(player), _map(map) {
	_dir.x = x;
	_dir.y = y;
}

Command_Move::~Command_Move() {

}

void Command_Move::execute() {
	int c = _player.col() + _dir.x;
	int r = _player.row() + _dir.y;
	_map.add(_player, r, c);
}