//#include "GL/glut.h"
//
//int init(void) {
//	glClearColor(0.0, 0.0, 0.0, 0.0);
//	glEnable(GL_DEPTH_TEST);
//	glMatrixMode(GL_PROJECTION);
//	glLoadIdentity();
//	glOrtho(-5, 5, -5, 5, -5, 5);
//	return 0;
//}
//
//void display(void) {
//	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
//	glMatrixMode(GL_MODELVIEW);
//	glLoadIdentity();
//	int currentExercise = 1;
//	switch (currentExercise) {
//	case 1: Exercici1();
//		break;
//	default: break;
//	}
//}
//
//void Exercici1() {
//	//BOTTOM LEFT
//	glViewport(0, 0, 300, 300);
//	glPushMatrix();
//
//	glColor4f(1.f, 1.f, 0.0f, 1.0f);
//	glRotatef(360, 1, 0, 0);
//	glutWireSphere(1, 20, 20);
//
//	glEnd();
//	glPopMatrix();
//
//	//BOTTOM RIGHT
//	glViewport(300, 0, 300, 300);
//	glPushMatrix();
//	glTranslatef(x, y, 0);
//	glRotatef(rotationAngle, 0, 0, 1);
//	glTranslatef(x, y, 0);
//
//	glEnd();
//	glPopMatrix();
//
//	//TOP LEFT
//	glViewport(0, 300, 300, 300);
//	glPushMatrix();
//	glColor4f(1.f, 1.f, 0.0f, 1.0f);
//	glRotatef(360, 1, 0, 0);
//	glutWireSphere(1, 20, 20);
//	glEnd();
//	glPopMatrix();
//
//	//TOP RIGHT
//	glViewport(300, 300, 300, 300);
//	glPushMatrix();
//	glColor4f(1.f, 1.f, 0.0f, 1.0f);
//	glRotatef(360, 0, 1, 0);
//	glutWireSphere(1, 20, 20);
//	glEnd();
//	glPopMatrix();
//}