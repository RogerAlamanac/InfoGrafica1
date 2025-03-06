#include <GL/glut.h>

int init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 200.0, 0.0, 150.0);
	return 0;
}

void drawObject() {
	glBegin(GL_POLYGON);
	glVertex2f(110, 50);
	glVertex2f(110, 70);
	glVertex2f(100, 80);
	glVertex2f(90, 70);
	glVertex2f(90, 50);
	glEnd();
}
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //Aixi la imatge es queda quieta

	//Transformations
	glRotatef(45, 0, 0, 1); //(4)
	glTranslatef(110, 50, 0); //(3)
	glScalef(2, 2, 1); //(2)
	glTranslatef(-110, -50, 0); //VA DE BAIX CAP A DALT (1)
	drawObject();

	glFlush();
}

void drawTriangle() {
	glBegin(GL_TRIANGLES);
	glVertex2f(50, 50);
	glVertex2f(100, 100);
	glVertex2f(150, 50);


	glEnd();
}

void Exercici1(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity(); //Aixi la imatge es queda quieta
	glTranslatef(30, 20, 0);
	drawTriangle();
	glFlush();

}

//MAIN EXERCICIS
//int main(int argc, char** argv) {
//	glutInit(&argc, argv);
//	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
//	glutInitWindowSize(800, 600);
//	glutInitWindowPosition(400, 400);
//
//	glutCreateWindow("Transformations 2D");
//	init();
//	//glutDisplayFunc(display);
//	glutDisplayFunc(Exercici1);
//	glutMainLoop();
//}

//MAIN PRACTICAL ACTIVITY

int initPA(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-2.0, 2.0, -1.5, 1.5);
	return 0;
}
void drawTrianglePA(void) {
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5f, -0.5f);
	glVertex2f(0.5, -0.5);
	glVertex2f(0, 0.5);
}

float rotationAngle = 0.0f;

void time(int) {
	rotationAngle += 1.0f;
	if (rotationAngle > 360.0f) { rotationAngle -= 360.0f; }
	glutPostRedisplay();
	glutTimerFunc(16, time, 0);
}
void PracticalActivity(void) {

	float x = (-0.5 + 0.5 + 0) / 3;
	float y = (-0.5 + -0.5 + 0.5) / 3;
	GLfloat shear_y[] = {1.0, 0.5, 0.0, 0.0,
						 0.0, 1.0, 0.0, 0.0,
						 0.0, 0.0, 1.0, 0.0,
						 0.0, 0.0 ,0.0, 1.0};
	
	//BOTTOM LEFT
	glViewport(0, 0, 300, 300); 
	glPushMatrix();
	glTranslatef(0.5, 0, 0);
	drawTrianglePA();
	glEnd();
	glPopMatrix();

	//BOTTOM RIGHT
	glViewport(300, 0, 300, 300); 
	glPushMatrix();
	glTranslatef(x, y, 0);
	glRotatef(rotationAngle, 0, 0, 1);
	glTranslatef(x, y, 0);
	
	drawTrianglePA();
	glEnd();
	glPopMatrix();

	//TOP LEFT
	glViewport(0, 300, 300, 300);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glScalef(0.5, 0.5, 0);
	glTranslatef(x, y, 0);
	drawTrianglePA();
	glEnd();
	glPopMatrix();

	//TOP RIGHT
	glViewport(300, 300, 300, 300);
	glPushMatrix();
	glTranslatef(x, y, 0);
	glMultMatrixf(shear_y);
	glTranslatef(x, y, 0);
	drawTrianglePA();
	glPopMatrix();
	glEnd();
}
void displayPA(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 1.0, 1.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	PracticalActivity();

	glFlush();
	glutSwapBuffers();
}
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(400, 400);

	glutCreateWindow("Practical Activity");
	initPA();
	glutDisplayFunc(displayPA);
	glutTimerFunc(0, time, 0);
	glutMainLoop();
}