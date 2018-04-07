#ifndef COMMANDTILE_MAGIC_H_678c9bfdas
#define COMMANDTILE_MAGIC_H_678c9bfdas

#include "commandtile.h"
#include "magichandler.h"
#include "prop.h"
#include "textconsole.h"

class CommandTile_Magic : public CommandTile {
public:
	CommandTile_Magic(MagicHandler&, GameMap&);
	~CommandTile_Magic();

	bool execute(int, int);
	std::string toString(std::string) const;

private:
	MagicHandler& _magichandler;
	GameMap& _map;
};

#endif