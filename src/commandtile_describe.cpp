#include "commandtile_describe.h"

CommandTile_Describe::CommandTile_Describe(GameMap& map) : _map(map) {}
CommandTile_Describe::~CommandTile_Describe() {}

bool CommandTile_Describe::execute(int x, int y) {
	int r = _map.row() + y;
	int c = _map.col() + x;
	int width = _map.width();
	int height = _map.height();

	int row = r;
	int col = c;

	if (x >= width || y >= height) {
		row = -1; col = -1;
	}

	Prop* prop = _map.getProp(row, col);

	const char* pdesc;
	const char* adesc;
	if (prop) {
		Actor* actor = _map.getActor(row, col);

		// putting this in an else statement fucks it up. idk
		std::string ad = "Nothing";
		adesc = ad.c_str();
		if (actor) {
			adesc = actor->description().c_str();
		}

		pdesc = prop->description().c_str();
		
		char buff[TEXTLOG_WORD_BUFFERSIZE*2];
		snprintf(buff, sizeof(buff), "%s is on the %s @ <%d, %d>", 
			adesc, pdesc, r, c);
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