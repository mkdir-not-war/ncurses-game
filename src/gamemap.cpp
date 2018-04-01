#include "gamemap.h"

GameMap::GameMap(Frame& mapframe, Frame& viewport, Actor& player) :
	_mapframe(mapframe), _viewport(viewport), _player(player) {

	_prop_ground = new Prop('.', true,
		std::string("ground"));
	_prop_wall = new Prop('#', false,
		std::string("wall"));
	_prop_ice = new Prop('S', false,
		std::string("ice"));
	_prop_water = new Prop('~', false,
		std::string("water"));

	_prop_null = new Prop();

	_mapactors.len = 1;
	_mapactors.actors[0] = &player;
}

GameMap::~GameMap() {
	delete _prop_ground;
	delete _prop_wall;
	delete _prop_ice;
	delete _prop_water;

	delete _prop_null;
}

void GameMap::refresh() {
	// clear the mapframe of everything
	_mapframe.fclear();

	// for each prop in gamemap,
	// add the prop to the mapframe
	for (int i=0; i<_mapframe.width(); i++) {
		for (int j=0; j<_mapframe.height(); j++) {
			Prop* p = getProp(i, j);
			_mapframe.add(p->symbol(), i, j);
		}
	}

	// next, for each actor in gamemap,
	// add the actor to the mapframe
	/*
	for (int i=0; i<MAXACTORS; i++) {
		_mapframe.add(
			_mapactors[i].symbol(), 
			_mapactors[i].row(), 
			_mapactors[i].col());
	}
	*/

	// add the player
	_mapframe.add(_player.symbol(), _player.row(), _player.col());

	// center and refresh the viewport
	_viewport.center(_player.row(), _player.col());
	_viewport.refresh();
}

void GameMap::loadMap() {
	genPerlin(257);
	//_mapframe.fillwindow();
	addActor(_player);
}

void GameMap::addActor(Actor& a) {
	addActor(a, a.row(), a.col());
}

void GameMap::addActor(Actor& a, int row, int col) {
	// if in the bounds of the map
	if ((row>=0 && row<_mapframe.height()) && 
		(col>=0 && col<_mapframe.width())) {

		if (getProp(row, col)->permeable()) {
			// confirm to the actor that they have moved
			a.moveto(row, col); 
		}
		else {
			// not permeable, do nothing? wasted turn?
			// (Pokemon plays a noise.)
		}
	}
}

void GameMap::genPerlin(const unsigned int& seed) {

	PerlinNoise pn(seed);

	for(int row = 0; row < MAPHEIGHT; ++row) {     // y
		for(int col = 0; col < MAPWIDTH; ++col) {  // x
			double x = (double)col/((double) MAPWIDTH);
			double y = (double)row/((double) MAPHEIGHT);

			double n = pn.noise(10 * x, 10 * y, 0.8);


			// Water (or a Lakes)
			if(n < 0.28) {
				_mapprops.props[row*MAPWIDTH + col] = _prop_water;
			}
			// Floors (or Planes)
			else if (n >= 0.25 && n < 0.6) {
				_mapprops.props[row*MAPWIDTH + col] = _prop_ground;
			}
			// Walls (or Mountains)
			else if (n >= 0.6 && n < 0.8) {
				_mapprops.props[row*MAPWIDTH + col] = _prop_wall;
			}
			// Ice (or Snow)
			else {
				_mapprops.props[row*MAPWIDTH + col] = _prop_ice;
			}

		}
	}
}

int GameMap::row() const {
	return _viewport.row();
}

int GameMap::col() const {
	return _viewport.col();
}

int GameMap::height() const {
	return _viewport.height();
}

int GameMap::width() const {
	return _viewport.width();
}

Prop* GameMap::getProp(int row, int col) {
	if (row < 0 || col < 0) 
		return NULL;
	
	return _mapprops.props[row*MAPWIDTH + col];
}

Prop* GameMap::setProp(int row, int col, Prop* newprop) {
	if (row < 0 || col < 0) 
		return NULL;

	Prop* temp = _mapprops.props[row*MAPWIDTH + col];
	_mapprops.props[row*MAPWIDTH + col] = newprop;
	
	return temp;
}


Actor* GameMap::getActor(int row, int col) {
	for (int i=0; i<_mapactors.len; i++) {
		if (_mapactors.actors[i]->row() == row &&
			_mapactors.actors[i]->col() == col) {
			return _mapactors.actors[i];
		}
	}
	return NULL;
}
