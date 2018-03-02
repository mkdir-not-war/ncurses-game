#include "actor.h"

Actor::Actor(char symbol, int row, int col) {
	_symbol = symbol;
	_row = row;
	_col = col;
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

