#ifndef TEXTCONSOLE_H_78sd9f0g79870
#define TEXTCONSOLE_H_78sd9f0g79870

#include <string.h>
#include <cstring>
#include <iostream>
#include <fstream>

#include "frame.h"

#define TEXTLOG_WORD_BUFFERSIZE	28 // 28 + sizeof(int) = 32
#define TEXTLOG_BUFFERSIZE 		64

// text log list and output frame
struct textlogword {
	char word[TEXTLOG_WORD_BUFFERSIZE];
	int len;
}; // sizeof(textlogword) = 32 bytes

struct textlog {
	unsigned char len; // 1 bytes
	unsigned char head; // 1 bytes
	unsigned char tail; // 1 bytes
	unsigned char __buffer; // 1 byte
	textlogword words[TEXTLOG_BUFFERSIZE]; // 2^6 * 2^5 = 2^11 bytes
}; // 4 + 2048 = 2052 bytes total

class TextConsole {
private:
	static textlog _log;
	static Frame* _outputframe;

	static void setFrame(Frame*);

public:
	TextConsole(Frame&);
	~TextConsole();

	// anyone who includes this header can use the logger
	// DO NOT CALL FROM SEPARATE THREADS. NOT THREAD SAFE.
	static void refresh();
	static void print(std::string); 
	static void push(std::string);
	static void clear();
	static void pophead();
	static void poptail();
	static void pop();
	static void writetofile();
};

#endif