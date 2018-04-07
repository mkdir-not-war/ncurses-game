#include "commandtile_confirm.h"

CommandTile_Confirm::CommandTile_Confirm(GameMap& gm) :_map(gm) {
	_confirmprop = new Prop('x');
}

CommandTile_Confirm::~CommandTile_Confirm() {
	delete _confirmprop;
}

bool CommandTile_Confirm::execute(int x, int y) {
	int row, col;
	bool inbounds = _map.getWorldCoord(x, y, col, row);
	if (!inbounds) {
		return false;
	}

	Prop* prop = _map.getProp(row, col);
	Actor* actor = _map.getActor(row, col);
	bool magic = _map.getMagic(row, col);

	if (prop && !actor && !magic) {
		TextConsole::print("Cast magic? (y/n)");
		_tempprop = prop;
		_map.setProp(row, col, _confirmprop);
		_map.refresh();
		_tile.y = row;
		_tile.x = col;
		return true;
	}
	else {
		return false; // don't confirm input
	}

}

void CommandTile_Confirm::confirm() {
	TextConsole::poptail();
	_map.setProp(_tile.y, _tile.x, _tempprop);
	_map.refresh();
	_tempprop = NULL;
}

std::string CommandTile_Confirm::toString(std::string input) const {
	return "";
}