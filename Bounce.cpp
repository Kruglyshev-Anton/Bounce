#include<iostream>
#include "glut.h"
#include "Map.h"
Map test("levels/test.txt");
std::vector<bool> keys(255, false);
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
	Moving();
	test.Draw();
	glutSwapBuffers();
}
void mouse(int button, int state, int x, int y) {
	
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
	gluOrtho2D(0,700,700,0);
	glMatrixMode(GL_MODELVIEW);
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