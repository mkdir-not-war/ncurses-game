#ifndef GAMEMAP_H_4567789gfdsg
#define GAMEMAP_H_4567789gfdsg

#include "frame.h"

#include "actor.h"
#include "prop.h"

#include "perlinnoise.h"

#define MAPWIDTH	128
#define MAPHEIGHT	128
#define MAXACTORS	32

class GameMap {

struct PropMap {
	Prop* props[MAPWIDTH*MAPHEIGHT];
};

private:
	Frame& _viewport;
	Frame& _mapframe;

	Prop* _prop_ground;
	Prop* _prop_wall;
	Prop* _prop_ice;
	Prop* _prop_water;

	Prop* _prop_null;

	PropMap _mapprops;
	//Actor _mapactors[MAXACTORS];

	/*
	* The player in this context is
	* the only actor that acts specifically according 
	* to how input is entered in the client. The player
	* is not saved inside the _mapactors array.
	*/
	Actor& _player; 

	void genPerlin(const unsigned int&);

public:
	GameMap(Frame&, Frame&, Actor&);
	~GameMap();

	void refresh();
	void loadMap();

	void addActor(Actor&);
	void addActor(Actor&, int, int);

	// maybe combine these into a struct later??
	int row() const;
	int col() const;
	int height() const;
	int width() const;

	Prop* getProp(int, int);
	//bool getActor(int, int, Actor&);
};

#endif