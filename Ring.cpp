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
