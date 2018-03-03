#ifndef TEXTCONSOLE_H_78sd9f0g79870
#define TEXTCONSOLE_H_78sd9f0g79870

#include <string.h>
#include <iostream>
#include <fstream>

#include "frame.h"

#define TEXTLOG_WORD_BUFFERSIZE	28 // 28 + sizeof(int) = 32
#define TEXTLOG_BUFFERSIZE 		64

// text log list and output frame
struct textlogword {
	char word[TEXTLOG_WORD_BUFFERSIZE];
	int len;
}; // sizeof(textlogword) = 32

struct textlog {
	textlogword words[TEXTLOG_BUFFERSIZE];
	unsigned short int len;
	unsigned short int head;
};

class TextConsole {
private:
	static textlog _log;
	static Frame* _outputframe;

	static void setFrame(Frame*);

public:
	TextConsole(Frame*);
	~TextConsole();

	// anyone who includes this header can use the logger
	// DO NOT CALL FROM SEPARATE THREADS. NOT THREAD SAFE.
	static void refresh();
	static void print(char*); 
	static void push(char*);
	static void clear();
	static void pophead();
	static void poptail();
	static void pop();
	static void writetofile();
};

#endif