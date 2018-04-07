#include "magichandler.h"

MagicHandler::MagicHandler() {

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