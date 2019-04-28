#include <glut.h>
#include <math.h>


void myInit(void)
{
	glClearColor(0, 0, 0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-100.0, 100.0, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
}


void Drawline(x1, y1, x2, y2) {
	float y;
	int x;
	

	for (x = x1; x <= x2; x++) {
		y = y1 + (x - x1)*(y2 - y1) / (x2 - x1);
		glColor3f(0.0, 1.0, 0.0);
		glBegin(GL_POINTS);
		//glVertex2f(x1, y1);
		glVertex2i(x, round(y));
		//SetPixel(NULL, x, round(y), RGB(255, 255, 255));
		glEnd();
	}
}


void myDisplay(void)  //main display routin
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 600, 600);
	Drawline(-55, 90, 55, -50);
	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lab 5  - Line");

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}


