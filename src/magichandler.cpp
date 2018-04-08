#include "magichandler.h"

MagicHandler::MagicHandler() :
	neutralaoe{
		{{0, 0}, 
		{-1, 0}, 
		{1, 0}, 
		{0, -1}, 
		{0, 1}}}, 
	combos{
		{{{0, -2}, {-1, -1}, {0, 0}, {1, 1}, {0, 2}}, 
		{{{0, 0}, {0, 1}, {0, 2}, {0, -1}, {0, -2}, {1, 1}, 
			{2, 1}, {-1, -1}, {-2, -1}}}, 
		'S', true, true}, 
		{{{0, 0}, {0, 1}, {1, 0}, {0, -1}, {-1, 0}}, 
		{{{1, 1}, {-1, 1}, {1, -1}, {-1, -1}, {2, 0}, {0, 2}, 
			{-2, 0}, {0, -2}, {2, 2}, {2, -2}, {-2, 2}, {-2, -2}}}, 
		'f', false, false}, 
		{{{0, 0}, {0, 2}, {0, -2}, {1, 1}, {1, -1}}, 
		{{{-1, 2}, {-1, 1}, {-1, 0}, {-1, -1}, {-1, -2}, {0, 1}, 
			{0, -1}, {1, 1}, {1, -1}}}, 
		'~', true, false}, 
		{{{0, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}}, 
		{{{-1, 2}, {0, 2}, {1, 2}, {2, 1}, {2, 0}, {2, -1}, 
			{-2, 1}, {-2, 0}, {-2, -1}, {-1, -2}, {0, -2}, {0, 1}}}, 
		'#', false, false}, 
		{{{0, 0}, {1, 0}, {-1, 0}, {-1, 1}, {-1, -1}}, 
		{{{0, 2}, {0, 1}, {0, 0}, {0, -1}, {0, -2}}}, 
		'P', false, false}} {

}

MagicHandler::~MagicHandler() {

}

void MagicHandler::castMagic(int row, int col, GameMap& gm) {
	// first, get the prop
	// (this can also be done in the command easily, if that's faster)
	Prop* prop = gm.getProp(row, col); 

	if (prop->symbol() != '.') {
		// deal damage AoE with appropriate effect
	}
	else {
		// deal normal damage
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