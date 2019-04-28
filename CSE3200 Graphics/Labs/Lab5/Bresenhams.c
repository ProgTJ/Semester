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


void SWAP(a, b) { //SWAP FUNCTION
	a = a + b;
	b = a - b;
	a = a - b;
}

void plot(x, y) {  // TO DISPLAY THE OUTPUT
	glBegin(GL_POINTS);
	glVertex2f(x, y);
	glEnd();
}

void line(x0, y0, x1, y1) {
	int Dx = x1 - x0; int Dy = y1 - y0;

	int steep = (abs(Dy) >= abs(Dx));
	if (steep) {
		SWAP(x0, y0);
		SWAP(x1, y1);
		Dx = x1 - x0;
		Dy = y1 - y0;
	}
	int xstep = 1;

	if (Dx < 0) {
		xstep = -1;
		Dx = -Dx;
	}
	int ystep = 1;

	if (Dy < 0) {
		ystep = -1;
		Dy = -Dy;
	}
	int TwoDy = 2 * Dy;
	int TwoDyTwoDx = TwoDy - 2 * Dx;
	int E = TwoDy - Dx;
	int y = y0; int xDraw, yDraw;

	for (int x = x0; x != x1; x += xstep) {
		if (steep) {
			xDraw = y; yDraw = x;
		}
		else {
			xDraw = x;
			yDraw = y;
		}
		plot(xDraw, yDraw);

		if (E > 0) {
			E += TwoDyTwoDx;
			y = y + ystep;
		}
		else {
			E += TwoDy;
		}
	}



}






void myDisplay(void)  //main display routin
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 600, 600);
	//drawIt();
	line(-55, 90, 55, -50);
	glFlush();
}

int main(int argc, char** argv)
{

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600, 600);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("Lab 5 Task 3 - Bresenham");

	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}

