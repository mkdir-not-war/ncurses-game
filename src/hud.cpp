#include "hud.h"

HUD::HUD(Frame& playerhudframe, Frame& actorshudframe, 
	GameMap& gm, Actor& player) :
	_map(gm), _player(player)
{
	setFrames(&playerhudframe, &actorshudframe);
}

HUD::~HUD() {
}

void HUD::setFrames(Frame* playerhudframe, Frame* actorshudframe) {
	_playerhudframe = playerhudframe;
	_actorshudframe = actorshudframe;
}

void HUD::refresh() {
	// clear the frames
	_playerhudframe->fclear();
	_actorshudframe->fclear();

	std::string str;
	char buff[HUDFRAMEWIDTH];

	// player frame
	// print header
	str = "-PLAYER INFO-";
	_playerhudframe->add(
		str.c_str(),
		str.size(),
		1, 1);

	// player health
	snprintf(buff, sizeof(buff), "HEALTH: %d", 
		_player.health());
	str = buff;
	_playerhudframe->add(
		str.c_str(),
		str.size(),
		3, 1);

	// player hunger
	snprintf(buff, sizeof(buff), "HUNGER: %d", 
		_player.hunger());
	str = buff;
	_playerhudframe->add(
		str.c_str(),
		str.size(),
		4, 1);

	// number of small keys
	int numkeys = _player.smallkeys();
	if (numkeys > 0) {
		snprintf(buff, sizeof(buff), "KEYS: %d", numkeys);
		str = buff;
		_playerhudframe->add(
			str.c_str(),
			str.size(),
			6, 1);
	}

	// actors frame
	// print header
	str = "+ -ENEMY HEALTH-";
	_actorshudframe->add(
		str.c_str(),
		str.size(),
		1, 0);

	str = "| ";
	for (int i=0; i<MAXENEMIES+1; i++) {
		_actorshudframe->add(
		str.c_str(),
		str.size(),
		i+2, 0);
	}

	// if hostile
	// print <name>: <health>
	// maybe uniquely color code?
	int len = 0;
	Actor* enemies[MAXENEMIES];
	int highlight = -1;
	_map.getEnemies(enemies, len, &highlight);

	for (int i=0; i<len; i++) {
		snprintf(buff, sizeof(buff), "ENEMY #%d: %d", 
			i+1,
			enemies[i]->health());
		str = buff;

		// if an enemy was described, update the hud color
		int color = COLOR_WHITE_ON_BLACK;
		if (i == highlight) {
			color = HIGHLIGHTCOLOR;
		}

		_actorshudframe->add(
			str.c_str(),
			str.size(),
			i+3, 2,
			color);
	}

	// refresh the frames
	_playerhudframe->refresh();
	_actorshudframe->refresh();
}