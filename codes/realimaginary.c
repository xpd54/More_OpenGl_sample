// written and debuged by ravi prakash 
// note ----------------------------------->  not completed
#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include"function.h"
const screenWidth = 800;
const screenHeight = 600;
GLdouble A,B,C,D;
void myInit(void)
{
	glClearColor(1.0,0.5,0.5,0.0);
	glColor3f(1.0f,0.0f,0.4f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	A = screenWidth/2;
	B = screenWidth/2;  // to displace the graph by screenwidth/2 in right
	C = screenHeight/2; 
	D = screenHeight/2;// to displace the graph by screenHeight/2 in up
}


void myDisplay(void)
{
	GLfloat real,imaginary,point;
	glClear(GL_COLOR_BUFFER_BIT);
	for(point -1;point<1;point+=0.001)
	{
		real=sin(point);
		imaginary=sin(point);
		drawDot(A*real+B , C*imaginary+D);
	}
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth , screenHeight);
	glutInitWindowPosition(100 , 150);
	glutCreateWindow("x*sin(x)");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
