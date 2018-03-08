#ifndef COMMAND_H_98fd78gs
#define COMMAND_H_98fd78gs

#include <string>

class Command {
public:
	//virtual ~Command();
	virtual void execute() = 0;
	virtual std::string toString(std::string input) const = 0;
};

#endif