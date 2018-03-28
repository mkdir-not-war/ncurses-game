#ifndef COMMAND_DESCRIBETILE_H_7849037890
#define COMMAND_DESCRIBETILE_H_7849037890

#include "command.h"
#include "actor.h"
#include "prop.h"
#include "gamemap.h"
#include "textconsole.h"

class Command_DescribeTile : public Command {
public:
	Command_DescribeTile(GameMap&);
	~Command_DescribeTile();

	void execute(int, int);
	std::string toString(std::string) const;

private:
	GameMap& _map;
};

#endif