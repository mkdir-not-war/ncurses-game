#include "prop.h"

Prop::Prop() :
	_symbol(' '), _permeable(true)
{
}

Prop::Prop(char symbol, bool permeable, std::string desc) :
	_symbol(symbol), _permeable(permeable), _description(desc)
{
}

/*
void Prop::moveto(int row, int col) {
	_row = row;
	_col = col;
}

int Prop::row() const {
	return _row;
}

int Prop::col() const {
	return _col;
}
*/

char Prop::symbol() const {
	return _symbol;
}

bool Prop::permeable() const {
	return _permeable;
}

std::string Prop::description() const {
	return _description;
}