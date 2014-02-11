//by Ravi Prakash vickyravi17@gmail.com
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
unsigned long int theNumber1=173,yBigest = 1 ,kBigest=0;

void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
}

unsigned long int max(unsigned long int input)
{
	if(input > yBigest)
	{
		yBigest = input;
		return yBigest;
	}
	
	else
		return yBigest;
}

void calculateConstant(unsigned long int theNumber)
{
	while(theNumber != 1)
	{
		if(theNumber%2 == 0)
		{
			theNumber = theNumber/2;
		}
		else
			theNumber = 3*theNumber+1;
			printf("%ld ",theNumber);
		yBigest = max(theNumber);
		kBigest++;
	}
	A = screenWidth / kBigest;
	B = 0;
	C = screenHeight / yBigest;
	D =100;
	//printf("%ld %ld\n",kBigest,yBigest);
}

void theRenderFunction(void)
{
	calculateConstant(theNumber1);
	glClear(GL_COLOR_BUFFER_BIT);
	unsigned long int i=0;
	for(i=0;i<=kBigest;i++)
	//while(theNumber1 !=1)
	{
		if(theNumber1%2 == 0)
		{
			theNumber1 = theNumber1/2;
		}
		else
			theNumber1 = 3*theNumber1 + 1;
		drawDot(A*i+B,C*theNumber1+D);
	}
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("hailstone");
	glutDisplayFunc(theRenderFunction);
	myInit();
	glutMainLoop();
}
