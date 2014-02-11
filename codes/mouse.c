//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gl.h>
#include<glu.h>
#include<glut.h>
#include"function.h"
const screenWidth = 600;
const screenHeight = 600;

void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(2.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	
}

void myMouse(int button , int state ,int x ,int y)
{
	static flag=0;
	if(flag == 0)
	{
		glClear(GL_COLOR_BUFFER_BIT);
		glClearColor(0.0f,0.0f,0.0f,0.0f);
		flag = 1;
	}
	if(state == GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			drawDot(x,screenHeight-y);
			glFlush();
		}
		if(button == GLUT_RIGHT_BUTTON)
		{
			glClearColor(0.0f,1.0f,0.0f,0.0);
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
		}
		if(button == GLUT_MIDDLE_BUTTON)
		{
			exit(-1);
		}
	}
	glutPostRedisplay();
	return;
}

void myDisplay(void)
{
	glutPostRedisplay();
	return;
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("mouse");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
}
