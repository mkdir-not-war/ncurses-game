#ifndef COMMAND_CONFIRMLOC_H_6789fd6s7g8969a
#define COMMAND_CONFIRMLOC_H_6789fd6s7g8969a

#include "mymath.h"
#include "textconsole.h"
#include "commandtile.h"
#include "prop.h"
#include "gamemap.h"

class CommandTile_Confirm : public CommandTile {
public:
	CommandTile_Confirm(GameMap&);
	~CommandTile_Confirm();

	bool execute(int, int);
	void confirm();

	std::string toString(std::string) const;

private:
	GameMap& _map;
	Vector2i _tile;
	Prop* _confirmprop;
	Prop* _tempprop;
};

#endif