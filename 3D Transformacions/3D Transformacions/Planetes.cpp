#include "GL/glut.h"

float day = 0, hour = 0;

void timer(int value) {
	hour += 0.1;
	if (hour == 24) {
		day += 1;
		hour = 0;
		if (day == 365) {
			day = 0;
		}

	}

	glutPostRedisplay();
	glutTimerFunc(40, timer, 1);

}

int init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluLookAt(0.0, 1.0, 0.0,
			  0.0, 0.0, 0.0,
			  1.0, 0.0, 0.0);
	glOrtho(-5.2, 5.2, -5.2, 5.2, -5.2, 5.2);
	return 0;
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glPushMatrix();
	glColor4f(1.f, 1.f, 0.0f, 1.0f);
	glRotatef(360.f / 28.f * day, 0, 1, 0);
	glutWireSphere(1, 20, 20);
	glPopMatrix();


	glPushMatrix();
	glColor4f(0,0,1,1);
	glRotatef(day, 0, 1, 0);
	glTranslatef(4, 0, 0);
	glRotatef(360.f / 28.f*hour, 0,1,0);
	glutWireSphere(0.5f, 10, 10);

	glColor4f(0.81f, 0.78f, 0.79, 1.0);
	glRotatef(360.f/28.f*day, 0, 1, 0);
	glTranslatef(1.0, 0.0, 0.0);
	glutWireSphere(0.2, 10, 10);
	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Solar System");
	
	init();
	glutDisplayFunc(display);
	glutTimerFunc(40, timer, 1);
	glutMainLoop();
}