#include "textconsole.h"

TextConsole::TextConsole(Frame* outputframe) :
	_outputframe(outputframe) {
	char poop[] = "poop";

	strcpy(_word.word, poop);
	_word.len = 4;
}

TextConsole::~TextConsole() {

}

void TextConsole::refresh() {
	_outputframe->add(_word.word, _word.len, 0, 0);
	_outputframe->refresh();
}