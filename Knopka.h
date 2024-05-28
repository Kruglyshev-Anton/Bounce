#pragma once
#include <string>
#include "glut.h"

class Knopka
{
private:
	float x, y, w, h;
	std::string text;
	bool act = false;
	void (*func)();

public:

	Knopka(float x, float y, float w, float h, std::string text, void(*func)());
	void drawk();
	void drawTxt();
	void invact();
	bool isClick(float x, float y);
	bool getact();
	void actfalse();


};

