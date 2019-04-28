#include <GL/glut.h>
#include <math.h>


void myInit(void)
{
	glClearColor(0, 0, 0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100, 100, -100, 100);
	glMatrixMode(GL_MODELVIEW);
}


void DDADraw(x1, x2, y1, y2) {
	int dx, dy, steps, i;
	float x_inc, y_inc, x, y;
	dx = x2 - x1; dy = y2 - y1;

	if (dx > dy) {
		steps = dx;
	}
	else
		steps = dy;

	x_inc = dx / steps;
	y_inc = dy / steps;
	x = x1;
	y = y1;
	glBegin(GL_POINTS);
	glVertex2i(round(x), round(y));
	glEnd();

	for (i = 1; i < steps; i++) {
		x += x_inc;
		y += y_inc;

		glBegin(GL_POINTS);
		glVertex2i(round(x), round(y));
		glEnd();

	}


}






void myDisplay(void)  //main display routin
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 600, 600);
	DDADraw(-55, 55, 90, -50);
	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lab 5 Task 2 - DDADraw");

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

