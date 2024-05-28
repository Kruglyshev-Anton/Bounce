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

int Block::Col(std::vector<std::pair<float, float>>& point)
{
	
	float x1, y1;
	
	for (int i = 0; i < 4; ++i) {
		x1 = point[i].first;
		y1 = point[i].second;
		if (x1 >= x && x1 <= x + w && y1 >= y && y1 <= y + h) {
			//std::cout << i+1 << '\n';
			
			return i+1;
		}
	}
	return 0;
}

float Block::getx()
{
	return x;
}

float Block::gety()
{
	return y;
}

float Block::getw()
{
	return w;
}

float Block::geth()
{
	return h;
}

void Block::setx(float val)
{
	x = val;
}

void Block::sety(float val)
{
	y = val;
}


