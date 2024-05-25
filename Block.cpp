#include "Block.h"

Block::Block(float x, float y):x(x), y(y)
{
}

void Block::Draw()
{
	//std::cout << 1;
	glColor3f(255, 0 ,0);
	glBegin(GL_POLYGON);
	glVertex2f(x,y);
	glVertex2f(x+w, y);
	glVertex2f(x+w, y+h);
	glVertex2f(x, y+h);
	glEnd();

	glColor3f(0, 0, 0);
	glBegin(GL_LINES);
	glVertex2f(x, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y + h);
	glVertex2f(x + w, y + h);
	glVertex2f(x, y + h);
	glVertex2f(x, y + h);
	glVertex2f(x, y);
	glEnd();
}

void Block::Move(unsigned char k)
{
}

std::string Block::getType()
{
	return "block";
}


