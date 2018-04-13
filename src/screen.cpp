#include "screen.h"

Screen::Screen() {
	initscr();
	start_color();

	init_pair(COLOR_WHITE_ON_BLACK, COLOR_WHITE, COLOR_BLACK);
	init_pair(COLOR_BLACK_ON_WHITE, COLOR_BLACK, COLOR_WHITE);
	init_pair(COLOR_RED_ON_BLACK, COLOR_RED, COLOR_BLACK);
	init_pair(COLOR_BLACK_ON_RED, COLOR_BLACK, COLOR_RED);
	init_pair(COLOR_WHITE_ON_RED, COLOR_WHITE, COLOR_RED);

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