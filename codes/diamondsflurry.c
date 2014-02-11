//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gl.h>
#include<glu.h>
#include<glut.h>
#include"function.h"
const screenWidth = 800;
const screenHeight = 600;

void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(1.0f,0.0f,2.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	
}

void diamonds(GLintPoint center, int size)  // unfilled diamonds sape
{
	GLintPoint up,down,left,right;
	up.x = center.x;
	up.y = center.y+size;
	down.x = center.x;
	down.y = center.y - size;
	left.x = center.x - size;
	left.y = center.y;
	right.x = center.x + size;
	right.y = center.y;
	drawIntLine(left,up);
	drawIntLine(up,right);
	drawIntLine(right,down);
	drawIntLine(down,left);
}

void diamondColorFill(GLintPoint center,int size) // color filled diamonds sape
{
	GLintPoint up,down,left,right;
	up.x = center.x;
	up.y = center.y+size;
	down.x = center.x;
	down.y = center.y - size;
	left.x = center.x - size;
	left.y = center.y;
	right.x = center.x + size;
	right.y = center.y;
	glBegin(GL_POLYGON);
	glVertex2f(up.x,up.y);
	glVertex2f(right.x,right.y);
	glVertex2f(down.x,down.y);
	glVertex2f(left.x,left.y);
	glEnd();
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	GLintPoint center;
	int size,i;
	srand(2);
	for(i=0;i<50;i++)
	{
		center.x=rand()%800;
		center.y=rand()%800;
		size=rand()%100;
		if(size%2==0)
		diamonds(center,size);
		else
		diamondColorFill(center,size);
	}
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("rectangle");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
