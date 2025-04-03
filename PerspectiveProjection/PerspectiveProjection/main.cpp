#include "GL/glut.h"

void init(void) {
	glClearColor(0, 0, 0, 0);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity;
	gluPerspective(60, 1.0, 1.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	gluLookAt(0.0, 0.0, 5.0,
			  0.0, 0.0, 0.0, 
			  0.0, 1.0, 0.0);
}

void DrawCube() {
	glutWireCube(1.0f);
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	DrawCube();
	glFlush();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(400, 400);

	glutCreateWindow("Perspective Projection");
	glutDisplayFunc(display);
	glutMainLoop();
}