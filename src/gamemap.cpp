#include "gamemap.h"

GameMap::GameMap(Frame& mapframe, Frame& viewport, Actor& player) :
	_mapframe(mapframe), _viewport(viewport), _player(player) {

}

GameMap::~GameMap() {

}

void GameMap::refresh() {
	_viewport.center(_player.row(), _player.col());
	_viewport.refresh();
}

void GameMap::loadMap() {
	_mapframe.genPerlin(257);
	//_mapframe.fillwindow();
	add(_player);
}

void GameMap::add(Actor& a) {
	add(a, a.row(), a.col());
}

void GameMap::erase(Actor& a) {
	_mapframe.erase(a.row(), a.col());
}

void GameMap::add(Actor& a, int row, int col) {
	// if in the bounds of the map
	if ((row>=0 && row<_mapframe.height()) && 
		(col>=0 && col<_mapframe.width())) {
		// get actor/prop at <row, col>

		// check if permeable
		if (true) {
			erase(a);
			_mapframe.add(a.symbol(), a.row(), a.col());
			a.moveto(row, col);
		}
		else {
			// not permeable, do nothing? Pokemon plays a noise.
		}
	}
}