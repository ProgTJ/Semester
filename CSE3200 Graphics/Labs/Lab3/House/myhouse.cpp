///////////////////////////////////////////////////////////////////////////////
// draw cube with glDrawArrays
// University of Guyana
// Department of Computer Science
// CSI 322 Micro-computer Graphics
// 3D Orientation Exercise - 2009/2010
///////////////////////////////////////////////////////////////////////////////

#include <GL/glut.h>
static int x_rotation = 0, y_rotation = 0,  z_rotation = 0;
static int x_axis = 0, y_axis = 0, z_axis = 0;
// vertex coords array
GLfloat vertices[] = {1,1,1,  -1,1,1,  -1,-1,1,  1,-1,1,        // v0-v1-v2-v3
                      1,1,1,  1,-1,1,  1,-1,-1,  1,1,-1,        // v0-v3-v4-v5
                      1,1,1,  1,1,-1,  -1,1,-1,  -1,1,1,        // v0-v5-v6-v1
                      -1,1,1,  -1,1,-1,  -1,-1,-1,  -1,-1,1,    // v1-v6-v7-v2
                      -1,-1,-1,  1,-1,-1,  1,-1,1,  -1,-1,1,    // v7-v4-v3-v2
                      1,-1,-1,  -1,-1,-1,  -1,1,-1,  1,1,-1};   // v4-v7-v6-v5

GLfloat colors[] = {1,1,1,  1,1,1,  1,1,1,  1,1,1,              // v0-v1-v2-v3
                    1,1,0,  1,1,0,  1,1,0,  1,1,0,              // v0-v3-v4-v5
                    1,0,1,  1,0,1,  1,0,1,  1,0,1,              // v0-v5-v6-v1
                    0,1,0,  0,1,0,  0,1,0,  0,1,0,              // v1-v6-v7-v2
                    0,1,1,  0,1,1,  0,1,1,  0,1,1,              // v7-v4-v3-v2
                    0,0,1,  0,0,1,  0,0,1,  0,0,1};             // v4-v7-v6-v5

void init(void)
{
 glClearColor (0.0, 0.0, 0.0, 0.0);
 glShadeModel (GL_FLAT);
 glEnable (GL_DEPTH_TEST);
}

void display(void)
{
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
 glRotatef((GLfloat) x_rotation, 1, 0 ,0);
 glRotatef((GLfloat) y_rotation, 0, 1 ,0);
 glRotatef((GLfloat) z_rotation, 0, 0 ,1);
    // enble and specify pointers to vertex arrays
    glEnableClientState(GL_COLOR_ARRAY);
    glEnableClientState(GL_VERTEX_ARRAY);
    glColorPointer(3, GL_FLOAT, 0, colors);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
    glDisableClientState(GL_VERTEX_ARRAY);  // disable vertex arrays
    glDisableClientState(GL_COLOR_ARRAY);
 //-------------------------------------
//X axis
glColor3f(0,1.0,0); 
glBegin(GL_LINES);          
	glVertex3f(-10,0,0);
	glVertex3f(10,0,0);
glEnd();

//y axis
glColor3f(1.0,0,0);
glBegin(GL_LINES);          
	glVertex3f(0,-10,0);
	glVertex3f(0,10,0);
glEnd();

//z axis
glColor3f(0,0,1.0);
glBegin(GL_LINES);          
	glVertex3f(0,0,-10);
	glVertex3f(0,0,10);
glEnd();

//wire cube
glColor3f(1.0,1.0,1.0);
 glutWireCube(5);

//House
//Door
glPushMatrix();
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,0,1);
	glTranslatef(0,-1.2,2.8);
    glScalef(0.8,1.2,0.05);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();  

//Door Knob
glPushMatrix();
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,1,1);
	glTranslatef(0.5,-1.2,2.8);
    glScalef(0.1,0.1,0.1);
    glEnableClientState(GL_VERTEX_ARRAY);  
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();	
	
//Front wall
glPushMatrix();
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,1,1);
	glTranslatef(0,0,2.5);
    glScalef(2.5,2.5,0.1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//Back Wall
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,0,1);
	glTranslatef(0,0,-2.5);
    glScalef(2.5,2.5,0.1);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//Back Wall Window
glPushMatrix();
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,0.5,0.8);
	glTranslatef(0,0,-2.8);
    glScalef(1,0.8,0.1);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();
   	
//Back Wall Window Roof
glPushMatrix();
	glRotatef(15,-10,0,0);
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0.5,0.2);
	glTranslatef(0,1.8,-2.8);
    glScalef(1.5,0.1,0.8);	
	glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();   	

//Left wall
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,0.5,0.5);
	glTranslatef(-2.5,0,0);
    glScalef(0.1,2.5,2.5);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//Left Wall Window
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,0.5,0.8);
	glTranslatef(-2.8,0,0);
    glScalef(0.1,0.8,1);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();
 
//Right wall
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,0.5,0.5);
	glTranslatef(2.5,0,0);
    glScalef(0.1,2.5,2.5);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix(); 
 
 //Right Wall Window
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0,0.5,0.8);
	glTranslatef(2.8,0,0);
    glScalef(0.1,0.8,1);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//Right Wall Window Roof
glPushMatrix();
	
	glRotatef(15,0,0,-10);
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0.5,0.2);
	glTranslatef(2.8,1.8,0);
    glScalef(0.8,0.1,1.5);	
	glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();   
	    
//Floor
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0.2,1,0.2);
	glTranslatef(0,-2.5,0);
    glScalef(8,0.1,5);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();
   	
//Ceiling
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(0.2,1,0.2);
	glTranslatef(0,2.5,0);
    glScalef(2.5,0.1,2.5);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//Right Roof
glPushMatrix();
	
	glRotatef(40,0,0,-10);
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0.5,0.2);
	glTranslatef(-0.4,4,0);
    glScalef(3,0.1,4);	
	glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix(); 

//Left Roof
glPushMatrix();
	
	glRotatef(40,0,0,10);
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0.2,0.2);
	glTranslatef(0.4,4,0);
    glScalef(3,0.1,4);	
	glEnableClientState(GL_VERTEX_ARRAY);    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();
   	
//Garage Roof 
glPushMatrix();
	
	glRotatef(15,0,0,10);
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0.2,0.2);
	glTranslatef(-4.8,2,0);
    glScalef(2.5,0.1,3);	
	glEnableClientState(GL_VERTEX_ARRAY);    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//Front Door Roof
glPushMatrix();
	
	glRotatef(15,10,0,0);
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0.2,0.2);
	glTranslatef(0,1,3);
    glScalef(1.5,0.1,1);	
	glEnableClientState(GL_VERTEX_ARRAY);    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//Front Door Pillar #1 
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(-1.2,-1.2,3.6);
    glScalef(0.15,1.2,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();
   	
//Front Door Pillar #2
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(1.2,-1.2,3.6);
    glScalef(0.15,1.2,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();

//House Support Pillar #1
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(-2.6,0,2.6);
    glScalef(0.15,2.5,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();
   	
//House Support Pillar #2
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(-2.6,0,-2.6);
    glScalef(0.15,2.5,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();   	

//House Support Pillar #3
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(2.6,0,-2.6);
    glScalef(0.15,2.5,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix(); 

//House Support Pillar #4
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(2.6,0,2.6);
    glScalef(0.15,2.5,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix(); 
   	
//Garage Pillar #1 
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(-6.6,-1,2.6);
    glScalef(0.15,1.3,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();   	
   	
//Garage Pillar #2 
glPushMatrix();
	
	glDisableClientState(GL_COLOR_ARRAY);
	glColor3f(1,0,1);
	glTranslatef(-6.6,-1,-2.6);
    glScalef(0.15,1.3,0.15);
    glEnableClientState(GL_VERTEX_ARRAY);
    
    glVertexPointer(3, GL_FLOAT, 0, vertices);
    glDrawArrays(GL_QUADS, 0, 24);
   	glPopMatrix();     	
   	
   	
glutSwapBuffers();
 
}

void reshape(int w, int h)
{
     glViewport(0,0, (GLsizei)w, (GLsizei)h);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluPerspective (60, (GLfloat)w / (GLfloat)h, 1.0, 200.0);
     glMatrixMode(GL_MODELVIEW);    
     glLoadIdentity(); //clear the main matrix
     gluLookAt(15,15,15,0,0,0,0,1,0); 
 }
 
void keyboard (unsigned char key, int x, int y)
{
    switch (key) 
     {
    case 'x':
    x_rotation = 15;
    y_rotation = 0;
    z_rotation = 0;
    glutPostRedisplay();
    break;
    case 'y':
    y_rotation = 15;
    x_rotation = 0;
    z_rotation = 0;
    glutPostRedisplay();
    break;
    case 'z':
    y_rotation = 0;
    x_rotation = 0;
    z_rotation = 15;
    glutPostRedisplay();
    break;
    default:
    break;
    }
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Cubeee 2.0 |Depth Test Enabled!!!");
    init ();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutMainLoop();
    return 0;
}
