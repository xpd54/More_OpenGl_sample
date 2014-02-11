//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<math.h>
#include"function.h"
const screenWidth=600;
const screenHeight=480;
GLdouble A,B,C,D;
void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(1.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	A=screenWidth/4.0;
	B=0.0;
	C=D=screenHeight/2.0;
}

void function_rander(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLdouble i=0,x;
	for(i=0;i<4.0;x+=0.005)
	{
		GLdouble y= exp(-x)*cos(2*M_PI*x);
		drawDot(A*x+B,C*y+D);
	}
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	//glutInitWindowPosition(100,150);
	glutCreateWindow("cos and exponential");
	glutDisplayFunc(function_rander);
	myInit();
	glutMainLoop();
}
