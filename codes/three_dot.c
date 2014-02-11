//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>
const screenWidth=600;
const screenHeight=480;
void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0); // set background color to a bright white
	glColor3f(0.0f,0.0f,0.0f); // set the drawing color to black
	glPointSize(4.0); // set the point size to 4 by 4 pixels
	glMatrixMode(GL_PROJECTION);// set up appropiate matrix to be explained
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
		glVertex2i(100,50);
		glVertex2i(100,130);
		glVertex2i(150,130);
	glEnd();
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);  // initialize the toolkit 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // set the dispaly mode
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("thee Dot");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
