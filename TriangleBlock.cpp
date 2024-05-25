#include "TriangleBlock.h"

TriangleBlock::TriangleBlock(float x, float y, int config):x(x), y(y),config(config)
{
}

void TriangleBlock::Draw()
{
	if (config == 1) {
		glColor3f(255, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x,y+h);
		glVertex2f(x + w, y + h);
		glVertex2f(x+w, y);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x, y + h);
		glVertex2f(x+w, y + h);
		glVertex2f(x+w, y + h);
		glVertex2f(x+w, y);
		glVertex2f(x + w, y);
		glVertex2f(x, y + h);
		glEnd();

	}
	else if (config == 2) {
		glColor3f(255, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x, y + h);
		glVertex2f(x + w, y+h);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(x, y + h);
		glVertex2f(x, y + h);
		glVertex2f(x + w, y + h);
		glVertex2f(x + w, y+h);
		glVertex2f(x, y);
		glEnd();

	}
	else if (config == 3) {
		glColor3f(255, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y+h);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y+h);
		glVertex2f(x + w, y + h);
		glVertex2f(x, y );
		glEnd();

	}
	else {
		glColor3f(255, 0, 0);
		glBegin(GL_POLYGON);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x, y + h);
		glEnd();
		glColor3f(0, 0, 0);
		glBegin(GL_LINES);
		glVertex2f(x, y);
		glVertex2f(x + w, y);
		glVertex2f(x + w, y);
		glVertex2f(x, y + h);
		glVertex2f(x, y + h);
		glVertex2f(x, y);
		glEnd();
	}
	
}

std::string TriangleBlock::getType()
{
	return "t_block";
}

void TriangleBlock::Move(unsigned char k)
{
}




