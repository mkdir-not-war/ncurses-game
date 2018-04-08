#include "actor.h"

Actor::Actor() : Actor(' ', -1, -1)
{
}

Actor::Actor(char symbol, int row, int col, std::string desc,
	char resist, char weak, int numkeys) :
	_symbol(symbol), 
	_row(row), _col(col), 
	_description(desc),
	_alive(true),
	_health(MAXHEALTH),
	_hunger(MAXHUNGER),
	_resistance(resist),
	_weakness(weak),
	_smallkeys(numkeys)
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

bool Actor::alive() const {
	return _alive;
}

int Actor::health() const {
	return _health;
}

int Actor::hunger() const {
	return _hunger;
}

int Actor::smallkeys() const {
	return _smallkeys;
}

void Actor::incHunger(int amt) {
	int newhunger = _hunger + amt;
	if (newhunger > MAXHUNGER) {
		newhunger = MAXHUNGER;
	}
	_hunger = newhunger;
}

void Actor::decHunger(int amt) {
	int newhunger = _hunger - amt;
	if (newhunger <= 0) {
		_alive = false;
	}
	_hunger = newhunger;
}

void Actor::incHealth(int amt) {
	int newhealth = _health + amt;
	if (newhealth > MAXHEALTH) {
		newhealth = MAXHEALTH;
	}
	_health = newhealth;
}

void Actor::decHealth(int amt) {
	int newhealth = _health - amt;
	if (newhealth <= 0) {
		_alive = false;
	}
	_health = newhealth;
}

void Actor::damage(char element) {
	const char* desc = _description.c_str();

	if (element == _resistance) {
		decHealth(RESISTDAMAGE);
		
		char buff[TEXTLOG_WORD_BUFFERSIZE*4];
		snprintf(buff, sizeof(buff), 
			"%s's resists the magic! %s takes reduced damage!",
			desc, desc);
		std::string s = buff;
		TextConsole::print(s);
	}
	else if (element == _weakness) {
		decHealth(WEAKDAMAGE);

		char buff[TEXTLOG_WORD_BUFFERSIZE*4];
		snprintf(buff, sizeof(buff), 
			"%s's weakness is exploited! %s takes extra damage!",
			desc, desc);
		std::string s = buff;
		TextConsole::print(s);
	}
	else {
		decHealth(NORMALDAMAGE);

		char buff[TEXTLOG_WORD_BUFFERSIZE*2];
		snprintf(buff, sizeof(buff), 
			"%s takes average damage.",
			desc);
		std::string s = buff;
		TextConsole::print(s);
	}
}
