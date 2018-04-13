#ifndef SCREEN_H_327859
#define SCREEN_H_327859

#include <config.h>
#include <assert.h>

class Screen {
private:
	int _height, _width;

public:
	Screen();
	~Screen();

	void add(const char*);

	int height() const;
	int width() const;
};

#endif