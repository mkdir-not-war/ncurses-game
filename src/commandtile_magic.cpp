#include "commandtile_magic.h"

CommandTile_Magic::CommandTile_Magic(MagicHandler& mh, GameMap& gm) : 
	_magichandler(mh), _map(gm) {

}
CommandTile_Magic::~CommandTile_Magic() {

}

bool CommandTile_Magic::execute(int x, int y) {
	int row, col;
	bool inbounds = _map.getWorldCoord(x, y, col, row);
	if (!inbounds) {
		return false;
	}

	_magichandler.castMagic(row, col, _map);

	Prop* prop = _map.getProp(row, col);
	const char* pdesc = prop->description().c_str();
	char buff[TEXTLOG_WORD_BUFFERSIZE*2];
	snprintf(buff, sizeof(buff), 
		"The player cast magic on the %s @ <%d, %d>", 
		pdesc, row, col);
	std::string s = buff;
	TextConsole::print(s);

	return true;
}

std::string CommandTile_Magic::toString(std::string input) const {
	return input + ": cast magic @ <x, y>";
}