#ifndef HUD_H_fdg987df0ag8a0
#define HUD_H_fdg987df0ag8a0

#include <string>
#include <string.h>
#include <assert.h>

#include "frame.h"
#include "actor.h"
#include "gamemap.h"

#include "textconsole.h"

#define HUDFRAMEWIDTH		18

class HUD {

private:
	Frame* _playerhudframe;
	Frame* _actorshudframe;
	GameMap& _map;
	Actor& _player;

	void setFrames(Frame*, Frame*);

public:
	// one frame for player, one for other actors
	HUD(Frame&, Frame&, GameMap&, Actor&);
	~HUD();

	void refresh();
};

#endif