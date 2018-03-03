#ifndef FRAME_H_9943758925
#define FRAME_H_9943758925

#include <ncurses.h>

#include "actor.h"
#include "perlinnoise.h"

class Frame {
private:
	int _height, _width;
	int _row, _col;
	bool _has_super;

	WINDOW *_w;
	WINDOW *_super;

public:
	// rows, cols, init row, init col
	Frame(int, int, int, int);
	// subwindow
	Frame(Frame&, int, int, int, int);
	~Frame();

	// Fill a window with numbers - the window is split in four equal regions,
	// each region is filled with a single number, so 4 regions and 4 numbers.
	// This is a suggestion of how this will look:
	//         0 | 1
	//         -----
	//         2 | 3 
	// This function is used only for debugging purposes.	
	void fillwindow();

	// move these to GameMap
	void add(Actor&);
	void erase(Actor&);
	void add(Actor&, int, int);
	void genPerlin(const unsigned int&);

	void erase(int, int);
	void add(char, int, int);
	void add(char*, int, int, int);
	void center(int, int);
	void refresh();
	void move(int, int);

	WINDOW* win() const;
	WINDOW* super() const;
	bool has_super() const;
	int height() const;
	int width() const;
	int row() const;
	int col() const;
};

#endif