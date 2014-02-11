// written by ravi prakash
// note -----------------------------> not completed
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include"function.h"
const screenWidth = 800;
const screenHeight = 600;
GLfloat A,B,C,D;
void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(1.0f,0.5f,0.5f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	A = screenWidth / 20;
	B = screenWidth / 10;
	C = screenHeight / 4;
	D = screenHeight / 2;
}

void myDisplay(void)
{
	GLfloat xa,ya,a;
	glClear(GL_COLOR_BUFFER_BIT);
	for(a=0;a<2*M_PI;a+=0.001)
	{
		xa = 10+sin(15*a);
		ya = sin(a);
		drawDot(A*xa+B,C*ya+D);
	}
	glFlush();
}

void main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth, screenHeight);
	glutInitWindowPosition(100 , 150);
	glutCreateWindow("zig zag");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
