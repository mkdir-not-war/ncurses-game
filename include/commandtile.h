#ifndef COMMANDTILE_H_98fd78gsvbn
#define COMMANDTILE_H_98fd78gsvbn

#include <string>
#include <stdarg.h>

class CommandTile {
public:
	virtual ~CommandTile() {}

	virtual bool execute(int x, int y) = 0;

	// used for help ('h' or 'H' keys)
	virtual std::string toString(std::string input) const = 0;
};

#endif