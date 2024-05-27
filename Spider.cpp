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
	if (moveheig < 3 * one_cell_size) {
		y -= speed;
		moveheig += abs(speed);
		//std::cout << moveheig << '\n';
	}
	else {
		U = !U;
		D = !D;
		speed = -speed;
		moveheig = 0;
	}
	
}

float Spider::getx()
{
	return x;
}

float Spider::gety()
{
	return y;
}

float Spider::getw()
{
	return w;
}

float Spider::geth()
{
	return h;
}

void Spider::setx(float val)
{
	x = val;
}

void Spider::sety(float val)
{
	y = val;
}

int Spider::Col(std::vector<std::pair<float, float>>& point)
{
	float x1, y1;
	for (int i = 0; i < 4; ++i) {
		x1 = point[i].first;
		y1 = point[i].second;
		if (x1 >= x && x1 <= x + w && y1 >= y && y1 <= y + h) {
			//std::cout << i+1 << '\n';

			return i + 1;
		}
	}
	return 0;
}
