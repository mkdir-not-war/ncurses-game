#include "screen.h"

Screen::Screen() {
	initscr();
	clear();
	noecho();
	cbreak();
	keypad(stdscr, true);
	curs_set(0);
	getmaxyx(stdscr, _height, _width);
}

Screen::~Screen() {
	endwin();
}

void Screen::add(const char* message) {
	printw(message);
}

int Screen::height() const {
	return _height;
}

int Screen::width() const {
	return _width;
}