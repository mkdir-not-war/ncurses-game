#ifndef GAMEMAP_H_4567789gfdsg
#define GAMEMAP_H_4567789gfdsg

#include "frame.h"

#include "actor.h"
#include "prop.h"

#include "perlinnoise.h"
#include "textconsole.h"

//#include "textconsole.h"

#define MAPWIDTH	128
#define MAPHEIGHT	128
#define MAXACTORS	31
#define MAXENEMIES	4

// maybe move this to a "magicconstants" header
#define MAGICCHAR	'*'

class GameMap {

struct PropMap {
	Prop* props[MAPWIDTH*MAPHEIGHT];
}; // MAPWIDTH * MAPHEIGHT bytes = 16,384 bytes

struct ActorMap {
	int len;
	Actor* actors[MAXACTORS];
}; // 1 + 31 bytes = 32 bytes

struct MagicMap {
	bool magic[MAPWIDTH*MAPHEIGHT];
}; // MAPWIDTH * MAPHEIGHT bits = 2048 bytes

private:
	PropMap _mapprops;
	ActorMap _mapactors;
	MagicMap _mapmagic;

	Frame& _viewport;
	Frame& _mapframe;

	// move all these to a resource manager sometime
	// since the same props will be used for each map
	Prop* _prop_ground;
	Prop* _prop_wall;
	Prop* _prop_ice;
	Prop* _prop_water;
	Prop* _prop_fire;
	Prop* _prop_wood;

	Prop* _prop_null;
	////////////////////////////////////////////////

	/*
	* The player in this context is
	* the only actor that acts specifically according 
	* to how input is entered in the client. 
	*/
	Actor& _player; 

	void genPerlin(const unsigned int&);

	void removeDeadActors();

public:
	GameMap(Frame&, Frame&, Actor&);
	~GameMap();

	void refresh();
	void loadMap();

	void addActor(char, int, int, bool hostile=false,
		std::string desc="Basic Actor",
		char resist=UNUSEDCHAR, char weak=UNUSEDCHAR,
		int numkeys=0);
	void addActor(Actor&, int, int);
	void moveActor(Actor&);
	bool moveActor(Actor&, int, int);

	// maybe combine these into a struct later??
	int row() const;
	int col() const;
	int height() const;
	int width() const;

	bool getWorldCoord(int, int, int&, int&);

	Prop* getProp(int, int) const;
	Prop* setProp(int, int, Prop*);
	Actor* getActor(int, int) const;
	bool getMagic(int, int) const;
	bool setMagic(int, int, bool);

	void updateActors(int);
	void getEnemies(Actor**, int&);
};

#endif