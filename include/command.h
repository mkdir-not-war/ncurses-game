#ifndef COMMAND_H_98fd78gs
#define COMMAND_H_98fd78gs

#include <string>
#include <stdarg.h>

class Command {
public:
	//virtual ~Command();

	// only need to redefine one of these
	virtual void execute() {execute(-1, -1);} 
	virtual void execute(int x, int y) {execute();}

	// used for help ('h' or 'H' keys)
	virtual std::string toString(std::string input) const = 0;
};

#endif