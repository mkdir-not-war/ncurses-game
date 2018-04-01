#include "actor.h"

Actor::Actor() :
	_symbol(' '), _row(-1), _col(-1)
{
}

Actor::Actor(char symbol, int row, int col, std::string desc) :
	_symbol(symbol), _row(row), _col(col), _description(desc)
{
}

void Actor::moveto(int row, int col) {
	_row = row;
	_col = col;
}

int Actor::row() const {
	return _row;
}

int Actor::col() const {
	return _col;
}

char Actor::symbol() const {
	return _symbol;
}

std::string Actor::description() const {
	return _description;
}
