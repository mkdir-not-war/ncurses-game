#ifndef PROP_H_327859asdf
#define PROP_H_327859asdf

class Prop {
private:
	int _row, _col;
	char _symbol;
	bool _permeable;

public:
	Prop();
	Prop(char, bool permeable=true);

	// probably not going to be used unless dynamic prop
	/*
	void moveto(int, int);
	int row() const;
	int col() const;
	*/

	// this is used for display
	char symbol() const;

	// state variables 
	bool permeable() const;
};

#endif