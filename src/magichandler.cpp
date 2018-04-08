#include "magichandler.h"

MagicHandler::MagicHandler() :
	neutralaoe{
		5,
		{{0, 0}, {-1, 0}, {1, 0}, {0, -1}, {0, 1}},
		MAGICCHAR}, 
	combos{
		{{{0, -2}, {-1, -1}, {0, 0}, {1, 1}, {0, 2}}, 
		{9, {{0, 0}, {0, 1}, {0, 2}, {0, -1}, {0, -2}, {1, 1}, 
			{2, 1}, {-1, -1}, {-2, -1}}, 
			'S'}, 
		true, true}, 
		{{{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}}, 
		{12, {{1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {2, 0}, {0, 2}, 
			{-2, 0}, {0, -2}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}}, 
			'f'}, 
		false, false}, 
		{{{0, 0}, {0, 2}, {0, -2}, {1, 1}, {1, -1}}, 
		{9, {{-1, 2}, {-1, 1}, {-1, 0}, {-1, -1}, {-1, -2}, {0, 1}, 
			{0, -1}, {1, 1}, {1, -1}},
			'~'}, 
		true, false}, 
		{{{0, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}, 
		{12, {{-1, 2}, {0, 2}, {1, 2}, {2, 1}, {2, 0}, {2, -1}, 
			{-2, 1}, {-2, 0}, {-2, -1}, {-1, -2}, {0, -2}, {0, 1}},
			'#'}, 
		false, false}, 
		{{{0, 0}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}}, 
		{5, {{0, 2}, {0, 1}, {0, 0}, {0, -1}, {0, -2}},
			'P'}, 
		false, false}} {

}

MagicHandler::~MagicHandler() {

}

void MagicHandler::castMagic(int row, int col, GameMap& gm) {
	// first, get the prop
	// (this can also be done in the command easily, if that's faster)
	Prop* prop = gm.getProp(row, col); 
	char e = prop->symbol();

	if (e != '.') {
		// deal damage AoE with appropriate effect
		if (e == 'f') {
			dealDamage(row, col, combos.fire.aoe, gm);
		}
		else if (e == '~') {
			dealDamage(row, col, combos.water.aoe, gm);
		}
		else if (e == 'S') {
			dealDamage(row, col, combos.ice.aoe, gm);
		}
		else if (e == 'P') {
			dealDamage(row, col, combos.wood.aoe, gm);
		}
		else if (e == '#') {
			dealDamage(row, col, combos.earth.aoe, gm);
		}
	}
	else {
		// deal normal damage
		dealDamage(row, col, neutralaoe, gm);
	}

	// next, leave magic on ground if permeable prop
	if (prop->permeable()) {
		gm.setMagic(row, col, true);
	}

	// next, check for combos

	// if combo
		// remove all magic
		// if more than one
			// notify player of randomness
			// pick a combo
		// execute combo with damage
		// update map with new props
}

void MagicHandler::dealDamage(int row, int col, AoE aoe, GameMap& gm) {
	for (int i=0; i<aoe.len; i++) {
		Vector2i tile = aoe.tiles[i];
		Vector2i pos = MyMath::add(tile, Vector2i{col, row});
		Actor* a = gm.getActor(pos.y, pos.x);
		if (a) {
			a->damage(aoe.element);
		}
	}
}