#include <glut.h>
#include <math.h>


void myInit(void)
{
	glClearColor(0, 0, 0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-5000.0, 5000.0, -5000.0, 5000.0);
	glMatrixMode(GL_MODELVIEW);
}

void setPixel(int x, int y)
{
    glColor3f(0.0, 0.3, 0.0); //Set pixel to black  
    glBegin(GL_POINTS);
    glVertex2f(x, y); //Set pixel coordinates 
    glEnd();
    glFlush(); //Render pixel
}

void drawSector(void) {
	int y;
	int r=4300;
	int xc=0;
	int yc=0;
for (y = 0; y<= r; y++){
	int x = sqrt((r*r)-(y*y));
	setPixel(xc+x,yc+y);
}
}



void myDisplay(void)  //main display routin
{
	glClear(GL_COLOR_BUFFER_BIT);
	//glViewport(0, 0, 600, 600);
	//drawIt();
	drawSector();
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


