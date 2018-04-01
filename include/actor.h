#ifndef ACTOR_H_327859
#define ACTOR_H_327859

#include <string>

class Actor {
private:
	int _row, _col;
	char _symbol;
	std::string _description;

public:
	Actor();
	Actor(char, int, int, std::string desc="a basic actor");

	void moveto(int, int);

	int row() const;
	int col() const;
	char symbol() const;
	std::string description() const;
};

#endif