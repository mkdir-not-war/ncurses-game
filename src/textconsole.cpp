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

		counter++;
		i++;
		i %= TEXTLOG_BUFFERSIZE;
	}
	_outputframe->refresh();
}

void TextConsole::print(std::string word) {
	push(word);
}

void TextConsole::splitnword(std::string& first, 
	std::string& rest) {
	std::string delimiter = "\n";
	size_t pos = 0;
	pos = first.find(delimiter);
	if (pos != std::string::npos) {
		std::string temp = first.substr(0, pos);
		rest = first;
		rest.erase(0, pos + delimiter.length());
		first = temp;
	}
}

void TextConsole::splitsword(std::string& first, 
	std::string& rest) {
	std::string delimiter = " ";

	std::string word = "";
	std::string firstcopy = first + delimiter;

	std::string debug = ">>";

	size_t pos = 0;
	while ((pos = firstcopy.find(delimiter)) != std::string::npos) {
		std::string temp = firstcopy.substr(0, pos);
		std::string tempword = word;
		if (tempword.length() > 0) {
			tempword += delimiter;
		}
		tempword += temp;

		// add three here for the tabs on continued lines
		if (tempword.length()+3 > TEXTLOG_WORD_BUFFERSIZE) {
			first = word;
			rest = firstcopy;
			return;
		}
		else {
			word = tempword;
		}
		firstcopy.erase(0, pos + delimiter.length());
	}
	return; // first is unchanged, rest is empty
}

void TextConsole::push(std::string word, bool wrap) {
	// if the word is longer than the word buffer size,
	// split by newline first, then spaces and try again

	if (wrap == true) {
		if (word.length() > TEXTLOG_WORD_BUFFERSIZE) {
			std::string rest = "";

			splitnword(word, rest); // try splitting on newline

			if (rest.length() == 0) { // if no newline characters in word
				splitsword(word, rest); // try splitting on spaces
			}

			if (rest.length() > 0) {
				push(word);
				std::string tabdrest = "\t\t\t" + rest;
				push(tabdrest);
				return;
			}
		}
	}

	// if log is full, pop the oldest entry
	// regardless, append to the end

	if (_log.len == TEXTLOG_BUFFERSIZE) {
		pophead();
	}
	int newtail = _log.tail + 1;
	newtail %= TEXTLOG_BUFFERSIZE;

	int wordlength = word.length();
	if (wordlength > TEXTLOG_WORD_BUFFERSIZE) {
		wordlength = TEXTLOG_WORD_BUFFERSIZE;
	}

	strncpy(_log.words[newtail].word, word.c_str(), wordlength);
	_log.words[newtail].len = wordlength;
	_log.tail = newtail;
	_log.len++;
}

void TextConsole::stash() {
	
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