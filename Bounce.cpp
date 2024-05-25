#include<iostream>
#include "glut.h"
#include "Map.h"
Map test("levels/test.txt");
void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	test.Draw();
	glutSwapBuffers();
}
void mouse(int button, int state, int x, int y) {
	
}
void keyboard(unsigned char key, int x, int y) {
	
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
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}