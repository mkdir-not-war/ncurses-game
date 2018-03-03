#ifndef GAMEMAP_H_4567789gfdsg
#define GAMEMAP_H_4567789gfdsg

#include "frame.h"
#include "actor.h"

class GameMap {

public:
	GameMap(Frame*, Frame*, Actor*);
	~GameMap();

	void refresh();
	void loadMap();

	void add(Actor&);
	void erase(Actor&);
	void add(Actor&, int, int);

private:
	Frame* _viewport;
	Frame* _mapframe;
	Actor* _player;
};

#endif