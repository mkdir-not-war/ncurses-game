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
	_mapframe->add(*_player);
}