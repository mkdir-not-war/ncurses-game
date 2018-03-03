#ifndef ACTOR_H_327859
#define ACTOR_H_327859

class Actor {
private:
	int _row, _col;
	char _symbol;
	bool _permeable;

public:
	Actor(char, int, int, bool permeable=true);

	void moveto(int, int);

	int row() const;
	int col() const;
	char symbol() const;
	bool permeable() const;
};

#endif