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
	_outputframe->fclear();
	int height = _outputframe->height()-1;
	int i = _log.head;
	if (height <= _log.len) {
		i += _log.len-height+1;
		i %= TEXTLOG_BUFFERSIZE;
	}
	int counter = 0;
	while (counter<_log.len &&
			counter<height-1) {
		_outputframe->add(
			_log.words[i].word, 
			_log.words[i].len, 
			counter, 0);
		i++;
		counter++;
		i %= TEXTLOG_BUFFERSIZE;
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
	newtail %= TEXTLOG_BUFFERSIZE;
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
	if (_log.len == 1) {
		clear();
		return;
	}

	// clear the head
	_log.words[_log.head].len = 0;
	// move the head
	_log.head++;
	_log.head %= TEXTLOG_BUFFERSIZE;

	_log.len--;
}

void TextConsole::poptail() {
	if (_log.len == 0) {
		return;
	}
	if (_log.len == 1) {
		clear();
		return;
	}

	// clear the tail
	_log.words[_log.tail].len = 0;
	// move the tail
	_log.tail--;
	_log.tail %= TEXTLOG_BUFFERSIZE;

	_log.len--;
}

void TextConsole::pop() {
	poptail();
}

void TextConsole::writetofile() {
	std::ofstream f;
	f.open("./output/textlog.txt");

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