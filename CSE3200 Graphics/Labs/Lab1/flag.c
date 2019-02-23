#include <stdio.h>
#include <gl/glut.h>
#include <math.h>
#include "dimensions.h"


//globals
float centreX;
float centreY;

//calculations
//------------------------------------
float calcTriangleHeight(){
	return (flag_height*sqrt(3))/2;
}
float calcPointSpace(){
	return (2*PI*circle_radius)/star_points;
	
}

void calcTriangleCentre(){
	centreX = (0.0+0.0+calcTriangleHeight()) / 3;
	centreY = (0.0+flag_height+(flag_height/2)) / 3;
}


//gl functions
//------------------------------------
void doInit() {
	glClearColor(1.0,1.0,1.0,0.0);

	/* Select the projection matrix and reset it */
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	/* setup drawing canvas / 2D coodinate*/
	gluOrtho2D(0,flag_width,0,flag_height);
}


void doDisplay() {

	/* Clear the screen with the clearcolor */
	glClear(GL_COLOR_BUFFER_BIT);
    
    //set black rectangle
    glColor3f(0.0,0.0,0.0);
	glBegin(GL_POLYGON); 
	  glVertex3f(0.0, flag_height, 0.0); 
	  glVertex3f(flag_width, flag_height, 0.0); 
	  glVertex3f(flag_width, flag_height-rectangle_height, 0.0); 
	  glVertex3f(0.0, 80.0, 0.0); 
	glEnd();
	
	
	//set red rectangle
	glColor3f(218.0/255.0, 47.0/255.0, 24.0/255.0);
	glBegin(GL_POLYGON); 
	  glVertex3f(0.0, flag_height-rectangle_height-rectangle_space, 0.0); 
	  glVertex3f(flag_width, flag_height-rectangle_height-rectangle_space, 0.0); 
	  glVertex3f(flag_width, flag_height-(rectangle_height*2)-rectangle_space, 0.0); 
	  glVertex3f(0.0, flag_height-(rectangle_height*2)-rectangle_space, 0.0); 
	glEnd();
	
	
	//set green rectangle
	glColor3f(40.0/255.0, 137.0/255, 48.0/255.0);
	glBegin(GL_POLYGON); 
	  glVertex3f(0.0, flag_height-(rectangle_height*2)-(rectangle_space*2), 0.0); 
	  glVertex3f(flag_width, flag_height-(rectangle_height*2)-(rectangle_space*2), 0.0); 
	  glVertex3f(flag_width, 0.0, 0.0); 
	  glVertex3f(0.0, 0.0, 0.0); 
	glEnd();
	
	
	//set blue triangle
	glColor3f(15.0/255.0, 71.0/255.0, 175.0/255.0);
	glBegin(GL_TRIANGLES);
        glVertex3f(0.0, flag_height, 0);
        glVertex3f(calcTriangleHeight(), flag_height/2, 0);
        glVertex3f(0.0, 0.0, 0.0);
    glEnd();
    
    
    //calculating center of triangle
    calcTriangleCentre();
    
    
    //star calculations
    //"It aint much but its honest work"
    glColor3f(252.0/255.0, 221.0/255.0, 8.0/255.0);
    glBegin(GL_POLYGON); 
    	
    	glVertex3f(centreX +(17*-cos(180-216)), centreY +(17*sin(180-216)), 0.0);  
    	
    	glVertex3f(centreX +(17*cos(90-72)), centreY +(17*sin(90-72)), 0.0); 
		
		glVertex3f(centreX, centreY-(17/2), 0.0); 
		
		glVertex3f(centreX +(17*cos(216)), centreY +(17*-sin(216)), 0.0); 
		                                                                                              
	glEnd();
	
	glBegin(GL_TRIANGLES);   	    	
		glVertex3f(centreX +(17*-cos(72)), centreY +(17*sin(72)),0.0);
		
		glVertex3f(centreX, centreY-(17/2), 0.0); 
		     
		glVertex3f(centreX +(17*cos(72)), centreY +(17*sin(72)), 0.0); 
		                                                                                              
	glEnd();
	//"It aint much but it's honest work"
	
	glFlush();
}
//------------------------------------

int main(int argc, char *argv[]) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(flag_width*4, flag_height*4);//aspect ratio [8:4]
	glutInitWindowPosition(300,100);
	glutCreateWindow("CSE3200: South Sudan Flag : Group: Corner Stone");
	doInit();
	glutDisplayFunc(doDisplay);
	glutMainLoop();
	return 0;
}
