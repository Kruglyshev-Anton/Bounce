#include "Ring.h"

Ring::Ring(float x, float y):x(x+0.2*one_cell_size),y(y-0.5*one_cell_size)
{
}

void Ring::Draw()
{
	if (isact) {
		glColor3f(0,255, 0);
	}
	else {
		glColor3f(255, 255, 0);
	}
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(x,y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y+h);
	glVertex2f(x+w, y+h);
	glVertex2f(x, y+h);
	glVertex2f(x, y + h);
	glVertex2f(x, y);
	glEnd();
	glLineWidth(1);
}

std::string Ring::getType()
{
	return "ring";
}

void Ring::Move(unsigned char k)
{
}

float Ring::getx()
{
	return x;
}

float Ring::gety()
{
	return y;
}

float Ring::getw()
{
	return w;
}

float Ring::geth()
{
	return h;
}

void Ring::setx(float val)
{
	x = val;
}

void Ring::sety(float val)
{
	y = val;
}
