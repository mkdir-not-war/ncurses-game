#ifndef PROP_H_327859asdf
#define PROP_H_327859asdf

#include <string>
#include <config.h>

class Prop {
private:
	int _row, _col;
	char _symbol;
	bool _permeable;
	std::string _description;
	int _color;

public:
	Prop();
	Prop(char, bool permeable=true, 
		std::string desc="an empty tile",
		int _color=COLOR_WHITE_ON_BLACK);

	// probably not going to be used unless dynamic prop
	/*
	void moveto(int, int);
	int row() const;
	int col() const;
	*/

	// this is used for display
	char symbol() const;
	std::string description() const;
	int color() const;

	// state variables 
	bool permeable() const;
};

#endif