#ifndef COMMAND_DESCRIBETILE_H_7849037890
#define COMMAND_DESCRIBETILE_H_7849037890

#include "commandtile.h"
#include "actor.h"
#include "prop.h"
#include "gamemap.h"
#include "textconsole.h"

class CommandTile_Describe : public CommandTile {
public:
	CommandTile_Describe(GameMap&);
	~CommandTile_Describe();

	bool execute(int, int);
	std::string toString(std::string) const;

private:
	GameMap& _map;
};

#endif