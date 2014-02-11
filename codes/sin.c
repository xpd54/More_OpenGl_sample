//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<math.h>
#include"function.h"
const screenWidth=800;
const screenHeight=600;
GLdouble A,B,C,D;
void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(1.0f,0.0f,1.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	A=screenWidth/(2*M_PI);
	B=screenWidth/2;
	C=D=screenHeight/2.0;
}


