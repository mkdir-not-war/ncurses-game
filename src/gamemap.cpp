#include "gamemap.h"

GameMap::GameMap(Frame* mapframe, Frame* viewport, Actor* player) :
	_mapframe(mapframe), _viewport(viewport), _player(player) {

}

GameMap::~GameMap() {

}

void GameMap::refresh() {
	_viewport->center(_player->row(), _player->col());
	_viewport->refresh();
}

void GameMap::loadMap() {
	_mapframe->genPerlin(257);
	add(*_player);
}

void GameMap::add(Actor& a) {
	_mapframe->add(a.symbol(), a.row(), a.col());
}

void GameMap::erase(Actor& a) {
	_mapframe->erase(a.row(), a.col());
}

void GameMap::add(Actor& a, int row, int col) {
	if ((row>=0 && row<_mapframe->height()) && 
		(col>=0 && col<_mapframe->width())) {
		// get actor at <row, col>

		// check if permeable
		if (false) {
			return;
		}
		else {
			erase(a);
			_mapframe->add(a.symbol(), a.row(), a.col());
			a.moveto(row, col);
		}
	}
}