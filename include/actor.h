#ifndef ACTOR_H_327859
#define ACTOR_H_327859

class Actor {
private:
	int _row, _col;
	char _symbol;

public:
	Actor();
	Actor(char, int, int);

	void moveto(int, int);

	int row() const;
	int col() const;
	char symbol() const;
};

#endif