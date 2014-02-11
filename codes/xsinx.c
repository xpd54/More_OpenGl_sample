// written and debuged by ravi prakash
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
	A = screenWidth/(16*M_PI);
	B = screenWidth/2;  // to displace the graph by screenwidth/2 in right
	C = screenHeight/40; 
	D = screenHeight/2;// to displace the graph by screenHeight/2 in up
}

void myDisplay(void)
{
	GLdouble x1,x2,y1,y2,i;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,0.0f,0.4f);
	for(i=-16*M_PI;i<16*M_PI;i+=0.0001)
	{
		y1=i*sin(i);
		drawDot(A*i+B,C*y1+D);
	}
	
	glColor3f(0.0f,0.0f,0.0f);
	drawCoordinateSystem(screenWidth , screenHeight);
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
