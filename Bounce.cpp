#include<iostream>
#include "glut.h"
#include "Map.h"
#include "Knopka.h"
Map test("levels/bounce.txt");
std::vector<bool> keys(255, false);
void bounce();
void level1();
void testf();
void goodbye();

bool isShowKnopki = true;
std::vector<Knopka> Knopki = {Knopka(200,350, test.getSizeW() / 10, test.getSizeH()/10, "bounce", bounce),\
Knopka(200 , 350+test.getSizeH() / 10, test.getSizeW() / 10, test.getSizeH() / 10, "level 1", level1), \
Knopka(200, 350 + 2*test.getSizeH() / 10, test.getSizeW() / 10, test.getSizeH() / 10, "test", testf),\
Knopka(200, 350 + 3*test.getSizeH() / 10, test.getSizeW() / 10, test.getSizeH() / 10, "exit", goodbye) };

void Moving() {
	for (int i = 0; i < 255; ++i) {

		if (keys[i]) {
			test.Move(static_cast<char>(i));
			//std::cout << static_cast<char>(i);
		}
	}
}
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	//test.Collision();
	if (test.getGame()==0) {
		Moving();
		test.Draw();
		if (isShowKnopki) {
			for (int i = 0; i < Knopki.size(); ++i) {
				Knopki[i].drawk();
			}
		}
	}
	else if(test.getGame() == 1){
		isShowKnopki = true;
		test = Map("levels/win.txt");
	}
	else {
		isShowKnopki = true;
		test = Map("levels/lose.txt");
	}
	glutSwapBuffers();
}
void mouse(int button, int state, int x, int y) {
	if(isShowKnopki)
	for (int i = 0; i < Knopki.size(); ++i) {
		
		Knopki[i].isClick(x, y);
	}
}

void keyboardD(unsigned char key, int x, int y) {
	keys[key] = true;
}
void keyboardU(unsigned char key, int x, int y) {
	keys[key] = false;
}
void init() {
	// Цвет фона
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	// Ортогональная проекция
	gluOrtho2D(0,700,700, 0);
	glMatrixMode(GL_MODELVIEW);
	glutPositionWindow(300, 20);
}
void timer(int = 0) {
	display();

	glutTimerFunc(20, timer, 0);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);

	

	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	// Размер окна
	glutInitWindowSize(700, 700);
	
	// Заголовок окна
	glutCreateWindow("Example");
	init();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboardD);
	glutKeyboardUpFunc(keyboardU);
	glutTimerFunc(20, timer, 0);
	glutMainLoop();
	return 0;
}

void bounce()
{
	//std::cout << 2;
	isShowKnopki = false;
	test = Map("levels/bounce1.txt");
	
}

void level1()
{
	isShowKnopki = false;
	test = Map("levels/level 1.txt");
	

}
void testf()
{
	isShowKnopki = false;
	test = Map("levels/test.txt");

}

void goodbye()
{
	exit(0);
}
