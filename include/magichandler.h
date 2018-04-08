#ifndef MAGIC_HANDLER_H_7f9gd67ag0
#define MAGIC_HANDLER_H_7f9gd67ag0

#include "gamemap.h"
#include "prop.h"	// for manipulating environment
#include "actor.h"	// for dealing damage
#include "mymath.h"

#include "textconsole.h"

#define AOETILES			12
#define MAGICPERCOMBO		5

struct AoE {
	int len;
	Vector2i tiles[AOETILES]; // 12 * (4 * 2) = 96
	char element; // 1
}; // 97

struct Combo {
	// vectors from a "center" tile, which is guaranteed included
	Vector2i tiles[MAGICPERCOMBO]; // 5 * (4 * 2) = 40
	AoE aoe; // 97
	bool rotatable; // <1
	bool reversable; // <1
}; // 137 + <=2 ~= 138

struct AllCombos {
	Combo ice;
	Combo fire; 
	Combo water; 
	Combo earth; 
	Combo wood; 
}; // 138 * 5 = 690

class MagicHandler {
private:
	AllCombos combos;
	AoE neutralaoe;

public:
	MagicHandler();
	~MagicHandler();

	void castMagic(int, int, GameMap&);
	void dealDamage(int, int, AoE, GameMap&);
};

#endif