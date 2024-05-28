#include "Knopka.h"

void Knopka::drawTxt()
{
	glColor3f(0, 0,1);
	glRasterPos2f(x, y + h / 2);

	for (int i = 0; i < text.size(); ++i) glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, text[i]);
}

void Knopka::invact()
{
	act = !act;
}

Knopka::Knopka(float x, float y, float w, float h, std::string text, void(*func)()) : x(x), y(y), w(w), h(h), text(text), func(func) {
	act = false;
}
void Knopka::drawk()
{
	//std::cout << act << std::endl;
	glColor3f(0.0, 0.0, 0.0);
	
	glLineWidth(3);
	glBegin(GL_LINES);

	glVertex2f(x, y);
	glVertex2f(x, y + h);
	glVertex2f(x, y + h);
	glVertex2f(x + w, y + h);
	glVertex2f(x + w, y + h);
	glVertex2f(x + w, y);
	glVertex2f(x + w, y);
	glVertex2f(x, y);

	//glVertex2f(x, y);
	glEnd();
	glLineWidth(1);

	drawTxt();


}

bool Knopka::isClick(float posx, float posy)
{
	if (posx<x + w && posx>x && posy < y + h && posy > y) {
		invact();
		func();

	}
	return act;
	//std::cout << act << std::endl;

}

bool Knopka::getact()
{
	return act;
}

void Knopka::actfalse()
{
	act = false;
}

