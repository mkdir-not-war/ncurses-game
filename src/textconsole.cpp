#include "textconsole.h"

textlog TextConsole::_log;
Frame* TextConsole::_outputframe;

TextConsole::TextConsole(Frame* outputframe) {
	setFrame(outputframe);
	clear(); // clear the log
}

TextConsole::~TextConsole() {

}

void TextConsole::setFrame(Frame* outputframe) {
	_outputframe = outputframe;
}

void TextConsole::refresh() {
	_outputframe->add(_log.words[_log.head].word, 
		_log.words[_log.head].len, 
		0, 0);
	_outputframe->refresh();
}

void TextConsole::print(char* word) {
	// if log is full, pop the oldest entry
	// regardless, append to the end

	/*
	char poop[] = "poop";
	strcpy(_word.word, poop);
	_word.len = TEXTLOG_WORD_BUFFERSIZE;
	*/
}

void TextConsole::push(char* word) {
	print(word);
}


void TextConsole::clear() {
	_log.len = 0;
	for (int i=0; i<TEXTLOG_BUFFERSIZE; i++) {
		_log.words[i].len = 0;
	}
	_log.head = 0;
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