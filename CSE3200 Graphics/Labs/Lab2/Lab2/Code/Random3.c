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


my2dPoint Point1 = {300,300};

void drawPoint(my2dPoint Point) //routine to draw point (x, y)
{ 	 
	 glColor3ub( rand()%255, rand()%255, rand()%255 ); 
     glBegin(GL_LINES);
     glVertex2fv(Point1); 
     glVertex2fv(Point); 
     
     glEnd();
     Point1[0] = Point[0];
     Point1[1] = Point[1];
}
     
void drawIt( void )  //some function
{    
    int rand(); // initiate random integer generator
    my2dPoint p;
    p[0] = 300;
    p[1] = 300;
    
    my2dPoint midpoint;
        
    my2dPoint vertices[3]={{50,50},{550,50},{300,550}}; 
    drawPoint(vertices[0]); drawPoint(vertices[1]); drawPoint(vertices[2]);
    
    int k;
    for( k=0; k<50000; k++) {
        
	    int rand2 = (rand()%3);
    	midpoint[0] = (p[0]+vertices[rand2][0])/2;
    	midpoint[1] = (p[1]+vertices[rand2][1])/2;
		// p[0] = (rand() % 100) * 6;
        // p[1] = (rand() % 100) * 6;
         drawPoint(midpoint);
         p[0] = midpoint[0];
         p[1] = midpoint[1];
         midpoint[0]=0; midpoint[1]=0;
    }
    
}


void myDisplay( void )  //main display routin
{
    glClear(GL_COLOR_BUFFER_BIT);
    //glViewport(0, 0, 600, 600);
    drawIt();
    glFlush(); 
 }

int main(int argc, char** argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
    glutInitWindowSize(720,720);
    glutInitWindowPosition(0,0); 
    glutCreateWindow("Lab 2 Starter Code - 50000 random lines from the new points Team: Vertex "); 
        
    glutDisplayFunc(myDisplay);
    myInit();
    glutMainLoop(); 
}


