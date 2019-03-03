#include <GL/glut.h>



const int width = 20;
const int height = width / 2;

void doInit() {
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/* Select the projection matrix and reset it */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	/* setup drawing canvas / 2D coodinate*/
	gluOrtho2D(0, 20, 0, 10);

}



void doDisplay() {

	/* Clear the screen with the clearcolor */
	glClear(GL_COLOR_BUFFER_BIT);

	//Set state to Green for Green Line
	glColor3f(1.0, 1.0, 1.0);

	//Setting the line parameters... 
	glBegin(GL_LINES);
	glVertex3f(20, 0, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, 0, 0);
	glVertex3f(0, 10, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, 10, 0);
	glVertex3f(20, 10, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(20, 10, 0);
	glVertex3f(20, 0, 0);
	glEnd();

	//line segments
	glBegin(GL_LINES);
	glVertex3f(0, 3, 0);
	glVertex3f(20, 3, 0);
	glEnd();


	glBegin(GL_LINES);
	glVertex3f(0, 7, 0);
	glVertex3f(20, 7, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, 3.5, 0);
	glVertex3f(20, 3.5, 0);
	glEnd();

	glBegin(GL_LINES);
	glVertex3f(0, 6.5, 0);
	glVertex3f(20, 6.5, 0);
	glEnd();

	//White background
	GLfloat p1[3] = { 0,0,0 };
	GLfloat p2[3] = { 0,10,0 };
	GLfloat p3[3] = { 20,10,0 };
	GLfloat p4[3] = { 20,0,0 };
	glBegin(GL_POLYGON);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3fv(p1);
	glVertex3fv(p2);
	glVertex3fv(p3);
	glVertex3fv(p4);
	glEnd();

	// green retangle
	GLfloat p5[3] = { 0,0,1 };
	GLfloat p6[3] = { 0,3,1 };
	GLfloat p7[3] = { 20,3,1 };
	GLfloat p8[3] = { 20,0,1 };
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex3fv(p5);
	glVertex3fv(p6);
	glVertex3fv(p7);
	glVertex3fv(p8);
	glEnd();

	//red retangle
	GLfloat p9[3] = { 0,3.5,1 };
	GLfloat p10[3] = { 0,6.5,1 };
	GLfloat p11[3] = { 20,6.5,1 };
	GLfloat p12[3] = { 20,3.5,1 };
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex3fv(p9);
	glVertex3fv(p10);
	glVertex3fv(p11);
	glVertex3fv(p12);
	glEnd();

	//black retangle
	GLfloat p13[3] = { 0,7,1 };
	GLfloat p14[3] = { 0,10,1 };
	GLfloat p15[3] = { 20,10,1 };
	GLfloat p16[3] = { 20,7,1 };
	glBegin(GL_POLYGON);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3fv(p13);
	glVertex3fv(p14);
	glVertex3fv(p15);
	glVertex3fv(p16);
	glEnd();

	//blue triangle
	/*GLfloat t1[3] = {0,0,2};
	GLfloat t2[3] = {0,myheight,2};
	GLfloat t3[3] = {(myheight*sqrt(3))/2,myheight/2,2}; */
	glBegin(GL_TRIANGLES);
	glColor3f(0.0588235294117647, 0.2784313725490196, 0.6862745098039216);
	glVertex3f(7, 5, 0);
	glVertex3f(0, 10, 0);
	glVertex3f(0, 0, 0);
	glEnd();

	//Star
	glBegin(GL_POLYGON);
	glColor3f(0.9882352941176471, 0.8666666666666667, 0.0352941176470588);
	glVertex3f(height/2, 5, 0);
	glVertex3f(3.5, 4.5, 0);
	glVertex3f(3, 5, 0);
	glVertex3f(2.5, 6, 0);
	glVertex3f(3, 4, 0);

	glVertex3f(4, 5, 0);
	glVertex3f(2.5, 5, 0);
	glVertex3f(2, 5, 0);
	glVertex3f(2.5, 6, 0);
	glVertex3f(3, 4, 0);
	glEnd();
	

	glFlush();
}

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(960, 480);
	glutInitWindowPosition(300, 100);
	glutCreateWindow("CSE3200: Simple Line : Paragon)");
	doInit();
	glutDisplayFunc(doDisplay);
	glutMainLoop();
	return 0;
}