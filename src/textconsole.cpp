#include "textconsole.h"

textlog TextConsole::_log;
Frame* TextConsole::_outputframe;

TextConsole::TextConsole(Frame& outputframe) {
	setFrame(&outputframe);
	clear(); // clear the log
}

TextConsole::~TextConsole() {
	clear();
}

void TextConsole::setFrame(Frame* outputframe) {
	_outputframe = outputframe;
}

void TextConsole::refresh() {
	int i = _log.head;
	int counter = 0;
	while (counter<_log.len) {
		_outputframe->add(
			_log.words[i].word, 
			_log.words[i].len, 
			0, counter);
		i++;
		counter++;
		if (i >= TEXTLOG_BUFFERSIZE) {
			i = 0;
		}
	}
	_outputframe->refresh();
}

void TextConsole::print(std::string word) {
	push(word);
}

void TextConsole::push(std::string word) {
	// if log is full, pop the oldest entry
	// regardless, append to the end

	/*
	char poop[] = "poop";
	strcpy(_word.word, poop);
	_word.len = TEXTLOG_WORD_BUFFERSIZE;
	*/

	if (_log.len == TEXTLOG_BUFFERSIZE) {
		pophead();
	}
	int newtail = _log.tail + 1;
	if (newtail >= TEXTLOG_BUFFERSIZE) {
		newtail = 0; // also could use modulo for this situation
	}
	strcpy(_log.words[newtail].word, word.c_str());
	_log.words[newtail].len = word.length();
	_log.tail = newtail;
	_log.len++;
}


void TextConsole::clear() {
	_log.len = 0;
	for (int i=0; i<TEXTLOG_BUFFERSIZE; i++) {
		_log.words[i].len = 0;
	}
	_log.head = 0;
	_log.tail = -1; // set this so push on empty works
}

void TextConsole::pophead() {
	if (_log.len == 0) {
		return;
	}
	// clear the head
	_log.words[_log.head].len = 0;
	// move the head
	_log.head = _log.head + 1;	
	if (_log.head >= TEXTLOG_BUFFERSIZE) {
		_log.head = 0;
	}

	_log.len--;
}

void TextConsole::poptail() {
	if (_log.len == 0) {
		return;
	}

	/* use this if no tail variable in _log
	// start at 1 because checking previous node for tail
	for (int i=1; i<TEXTLOG_BUFFERSIZE; i++) {
		if (_log.words[i].len == 0) {
			if (_log.words[i-1].len > 0) {
				// empty space preceeded by word means the 
				// word is the tail
				_log.words[i-1].len = 0;
			}
		}
		else {
			// skip checking this, since its length is zero.
			// can't be the tail
			i++;
			if (i >= TEXTLOG_BUFFERSIZE && _log.head > 0) {
				// the last element is the head and tail
				_log.words[TEXTLOG_BUFFERSIZE-1].len = 0;
				_log.head = 0;
			}
		}
	}

	_log.len--;
	*/

	// clear the tail
	_log.words[_log.tail].len = 0;
	// move the tail
	_log.head = _log.tail - 1;	
	if (_log.head < 0) {
		_log.head = TEXTLOG_BUFFERSIZE-1;
	}

	_log.len--;
}

void TextConsole::pop() {
	poptail();
}

void TextConsole::writetofile() {
	std::ofstream f;
	f.open("./debug/textlog.txt");

	int i = _log.head;
	int counter = 0;
	while (counter<_log.len) {
		f << _log.words[i].word << std::endl;
		i++;
		counter++;
		if (i >= TEXTLOG_BUFFERSIZE) {
			i = 0;
		}
	}

	f.close();
}