#include "command_move.h"

Command_Move::Command_Move(int x, int y, Actor* player, GameMap* map) : 
	_x(x), _y(y), _player(player), _map(map) {

}

Command_Move::~Command_Move() {

}

void Command_Move::execute() {
	_map->add(*_player, 
		_player->row() + _y, 
		_player->col() + _x);
}