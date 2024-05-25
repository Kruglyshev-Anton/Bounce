#include "Stick.h"

Stick::Stick(float x, float y):x(x), y(y)
{
}

std::string Stick::getType()
{
	return "stick";
}

void Stick::Draw()
{

	glColor3f(0, 140, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2f(x+w/2, y);
	glVertex2f(x + w / 2, y+h);
	glVertex2f(x, y+h/10);
	glVertex2f(x + w, y+h/10);
	glVertex2f(x, y+h/3);
	glVertex2f(x + w, y+h/2);
	glEnd();
	glLineWidth(1);
}

void Stick::Move(unsigned char k)
{
}
