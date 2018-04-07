#include "commandtile_describe.h"

CommandTile_Describe::CommandTile_Describe(GameMap& map) : _map(map) {}
CommandTile_Describe::~CommandTile_Describe() {}

bool CommandTile_Describe::execute(int x, int y) {
	int row, col;
	bool inbounds = _map.getWorldCoord(x, y, col, row);
	if (!inbounds) {
		return false;
	}

	Prop* prop = _map.getProp(row, col);

	const char* pdesc;
	const char* adesc;
	if (prop) {
		Actor* actor = _map.getActor(row, col);
		bool magic = _map.getMagic(row, col);

		// putting this in an else statement fucks it up. idk
		std::string ad = "Nothing";
		adesc = ad.c_str();
		if (actor) {
			adesc = actor->description().c_str();
		}
		else if (magic) {
			adesc = "Lingering magic";
		}

		pdesc = prop->description().c_str();
		
		char buff[TEXTLOG_WORD_BUFFERSIZE*2];
		snprintf(buff, sizeof(buff), "%s is on the %s @ <%d, %d>", 
			adesc, pdesc, row, col);
		std::string s = buff;

		TextConsole::print(s);
		return false;
	}
	else {
		/*
		desc = "is too far to observe.";
		char buff[TEXTLOG_WORD_BUFFERSIZE];
		snprintf(buff, sizeof(buff), "<%d, %d> %s", 
			r, c, desc);
		std::string s = buff;

		TextConsole::print(s);
		*/
		return true; // try again
	}

	
}

std::string CommandTile_Describe::toString(std::string input) const {
	return input + ": describe tile @ <x, y>";
}