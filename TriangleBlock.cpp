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

float TriangleBlock::getx()
{
	return x;
}

float TriangleBlock::gety()
{
	return y;
}

float TriangleBlock::getw()
{
	return w;
}

float TriangleBlock::geth()
{
	return h;
}

void TriangleBlock::setx(float val)
{
	x = val;
}

void TriangleBlock::sety(float val)
{
	y = val;
}

int TriangleBlock::Col(std::vector<std::pair<float, float>>& point)
{
	float x1, y1;
	for (int i = 0; i < 4; ++i) {
		x1 = point[i].first;
		y1 = point[i].second;
		if (config == 1) {
			if (x1 >= x && x1<=x + w && y1>=y && y1<=y + h && x1 - x + y1 - y>=one_cell_size) {
				//std::cout << i+1 << '\n';
				return i+1;
			}
		}
		else if (config == 2) {
			if (x1 >= x && x1 <= x + w && y1 >= y && y1 <= y + h && -(x1 - x) + (y1 - y) >= 0) {
				//std::cout << i+1 << '\n';
				return i + 1;
			}
		}
		else if (config == 3) {
			if (x1 >= x && x1 <= x + w && y1 >= y && y1 <= y + h && -(x1 - x) + (y1 - y) <= 0) {
				//std::cout << i+1 << '\n';
				return i + 1;
			}
		}
		else if (config == 4) {
			if (x1 >= x && x1 <= x + w && y1 >= y && y1 <= y + h && x1 - x + y1 - y <= one_cell_size) {
				//std::cout << i+1 << '\n';
				return i + 1;
			}
		}
	}
	return 0;
}

int TriangleBlock::getconf()
{
	return config;
}




