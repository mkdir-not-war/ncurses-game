#ifndef GAMEMAP_H_4567789gfdsg
#define GAMEMAP_H_4567789gfdsg

#include "frame.h"

class GameMap {

public:
	GameMap(Frame*, Frame*, Actor*);
	~GameMap();

	void refresh();
	void loadMap();

private:
	Frame* _viewport;
	Frame* _mapframe;
	Actor* _player;
};

#endif