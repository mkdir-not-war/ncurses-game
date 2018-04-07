#ifndef MAGIC_HANDLER_H_7f9gd67ag0
#define MAGIC_HANDLER_H_7f9gd67ag0

#include "gamemap.h"
#include "prop.h"	// for manipulating environment
#include "actor.h"	// for dealing damage
#include "textconsole.h"

class MagicHandler {
private:

public:
	MagicHandler();
	~MagicHandler();

	void castMagic(int, int, GameMap&);
};

#endif