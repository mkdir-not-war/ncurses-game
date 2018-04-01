#include "commandtile_confirm.h"

CommandTile_Confirm::CommandTile_Confirm(GameMap& gm) :_map(gm) {
	_confirmprop = new Prop('x');
}

CommandTile_Confirm::~CommandTile_Confirm() {
	delete _confirmprop;
}

bool CommandTile_Confirm::execute(int x, int y) {
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
	Actor* actor = _map.getActor(row, col);

	if (prop && !actor) {
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