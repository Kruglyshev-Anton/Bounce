#include "Spider.h"

Spider::Spider(float x, float y):x(x),y(y)
{
}

std::string Spider::getType()
{
	return "spider";
}

void Spider::Draw()
{
	glColor3f(0, 0, 0);
	glLineWidth(3);
	glBegin(GL_LINES);
	
	glVertex2f(x,y);
	glVertex2f(x + w, y + h);
	glVertex2f(x+w, y);
	glVertex2f(x, y + h);
	glVertex2f(x+w/2, y);
	glVertex2f(x + w/2, y + h);
	glEnd();
	glLineWidth(1);
}

void Spider::Move(unsigned char k)
{
}
