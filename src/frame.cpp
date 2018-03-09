#include "frame.h"

Frame::Frame(int rows, int cols, int row, int col) :
	_has_super(false),
	_super(NULL),
	_w(newwin(rows, cols, row, col)),
	_height(rows),
	_width(cols),
	_row(row),
	_col(col) {

}

Frame::Frame(Frame& sw, int rows, int cols, int row, int col) :
	_has_super(true),
	_super(sw.win()),
	_w(derwin(sw.win(), rows, cols, row, col)),
	_height(rows),
	_width(cols),
	_row(row),
	_col(col) {

}

Frame::~Frame() {
	delwin(_w);
}

void Frame::erase(int row, int col) {
	mvwaddch(_w, row, col, ' ');
}

void Frame::fclear() {
	wclear(_w);
}

void Frame::add(char ch, int row, int col) {
	if ((row>=0 && row<_height) && (col>=0 && col<_width)) {
		mvwaddch(_w, row, col, ch);
	}
}

void Frame::add(char* str, int length, int row, int col) {
	int col_pos = col;
	//int row_pos = row;
	for (int i = 0; i<length; i++) {
		/*
		* Automatic text-wrap won't work here because textconsole
		* has no way of knowing which rows are empty and 
		* which aren't. Instead, textconsole should add long 
		* strings in chunks of size frame.width()
		*/
		add(str[i], row, col_pos+i);
	}
}

// no idea how this works. Check out ncurses for documentation
// https://invisible-island.net/ncurses/man/ncurses.3x.html
void Frame::center(int crow, int ccol) {
	if (_has_super) {
		int rr = _row, cc = _col, hh, ww;
		int _r = crow - _height/2;
		int _c = ccol - _width/2;

		getmaxyx(_super, hh, ww);

		if(_c + _width >= ww) {
			int delta = ww - (_c + _width);
			cc = _c + delta;
		}
		else {
			cc = _c;
		}

		if(_r +_height >= hh) {
			int delta = hh - (_r +_height);
			rr = _r + delta;
		}
		else {
			rr = _r;
		}

		if (_r < 0) {
			rr = 0;
		}

		if (_c < 0) {
			cc = 0;
		}

		move(rr, cc);
	}
}

void Frame::refresh() {
	if (_has_super) {
		touchwin(_super);
	}
	wrefresh(_w);
}

void Frame::move(int r, int c) {
	if (_has_super) {
		mvderwin(_w, r, c);
		_row = r;
		_col = c;
		refresh();
	}
}

// Fill a window with numbers - the window is split in four equal regions,
// each region is filled with a single number, so 4 regions and 4 numbers.
// This is a suggestion of how this will look:
//         0 | 1
//         -----
//         2 | 3 
// This function is used only for debugging purposes.
void Frame::fillwindow() {
	int max_x = _width/2;
	int max_y = _height/2;
	// Fill the first region with 0's
	for(int y = 0; y < max_y; ++y) {
		for(int x = 0; x < max_x; ++x) {
			mvwaddch(_w, y, x, '0');
		}
	}

	// Fill the second region with 1's
	for(int y = 0; y < max_y; ++y) {
		for(int x = max_x; x < _width; ++x) {
			mvwaddch(_w, y, x, '1');
		}
	}

	// Fill the third region with 2's
	for(int y = max_y; y < _height; ++y) {
		for(int x = 0; x < max_x; ++x) {
			mvwaddch(_w, y, x, '2');
		}
	}

	// Fill the fourth region with 3's
	for(int y = max_y; y < _height; ++y) {
		for(int x = max_x; x < _width; ++x) {
			mvwaddch(_w, y, x, '3');
		}
	}

	for(int y = 0; y < _height; ++y) {
		mvwaddch(_w, y, 0, '-');
		mvwaddch(_w, y, _width - 1, '-');
	}

	for(int x = 0; x < _width; ++x) {
		mvwaddch(_w, 0, x, '|');
		mvwaddch(_w, _height - 1, x, '|');
	}
}

WINDOW* Frame::win() const {
	return _w;
}

WINDOW* Frame::super() const {
	return _super;
}

bool Frame::has_super() const {
	return _has_super;
}

int Frame::height() const {
	return _height;
}

int Frame::width() const {
	return _width;
}

int Frame::row() const {
	return _row;
}

int Frame::col() const {
	return _col;
}