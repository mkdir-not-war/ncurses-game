#ifndef TEXTCONSOLE_H_78sd9f0g79870
#define TEXTCONSOLE_H_78sd9f0g79870

#include <string.h>

#include "frame.h"

#define TEXTCONSOLE_WORD_BUFFERSIZE	10

class TextConsole {

private:
	// text log list and output frame
	struct textlogword {
		char word[TEXTCONSOLE_WORD_BUFFERSIZE];
		int len;
	};

	textlogword _word;
	Frame* _outputframe;

public:
	TextConsole(Frame*);
	~TextConsole();

	void refresh();
};

#endif