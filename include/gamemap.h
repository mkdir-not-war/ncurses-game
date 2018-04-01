#ifndef GAMEMAP_H_4567789gfdsg
#define GAMEMAP_H_4567789gfdsg

#include "frame.h"

#include "actor.h"
#include "prop.h"

#include "perlinnoise.h"

#define MAPWIDTH	128
#define MAPHEIGHT	128
#define MAXACTORS	31

class GameMap {

struct PropMap {
	Prop* props[MAPWIDTH*MAPHEIGHT];
};

struct ActorMap {
	int len;
	Actor* actors[MAXACTORS];
}; // 1 + 31 bytes = 32 bytes

private:
	PropMap _mapprops;
	ActorMap _mapactors;

	Frame& _viewport;
	Frame& _mapframe;

	Prop* _prop_ground;
	Prop* _prop_wall;
	Prop* _prop_ice;
	Prop* _prop_water;

	Prop* _prop_null;

	/*
	* The player in this context is
	* the only actor that acts specifically according 
	* to how input is entered in the client. 
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
	Prop* setProp(int, int, Prop*);
	Actor* getActor(int, int);
	//bool getActor(int, int, Actor&);
};

#endif