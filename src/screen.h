#ifndef SCREEN_H_327859
#define SCREEN_H_327859

#include <ncurses.h>

class Screen {
private:
	int _height, _width;

public:
	Screen();
	~Screen();

	void add(const char*);

	int height() const;
	int width() const;
};

#endif