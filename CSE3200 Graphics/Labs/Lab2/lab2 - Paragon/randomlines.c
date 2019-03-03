#include <GL/glut.h>

typedef GLfloat my2dPoint[2];

void myInit(void)
{
	glClearColor(0, 0, 0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 600.0, 0.0, 600.0);
	glMatrixMode(GL_MODELVIEW);
}

void drawPoint(my2dPoint Point) //routine to draw point (x, y)
{
	glColor3ub(rand() % 255, rand() % 255, rand() % 255);
	glBegin(GL_LINES);
	glVertex2f(rand(), rand());
	glVertex2fv(Point);
	glEnd();
}

void drawIt(void)  //some function
{
	int rand(); // initiate random integer generator
	my2dPoint p;

	int k;

	for (k = 0; k < 5000; k++) {
		p[0] = (rand() % 100) * 6;
		p[1] = (rand() % 100) * 6;
		drawPoint(p);
	}

}


void myDisplay(void)  //main display routin
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 600, 600);
	drawIt();
	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lab 2 Starter Code - 5000 random points");

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}