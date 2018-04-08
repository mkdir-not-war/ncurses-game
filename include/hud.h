#ifndef HUD_H_fdg987df0ag8a0
#define HUD_H_fdg987df0ag8a0

#include <string.h>
#include <string>
#include <assert.h>

#include "frame.h"
#include "actor.h"
#include "gamemap.h"

class HUD {

private:

public:
	HUD(Frame&, GameMap&);
	~HUD();

};

#endif