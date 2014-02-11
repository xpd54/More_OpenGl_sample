// written and debuged by ravi prakash
#include<stdio.h>
#include<stdlib.h>
#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<SOIL/SOIL.h>
#include"function.h"
const screenWidth=600;
const screenHeight=640;
void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(0.0f,1.0f,0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
}


void myMouse(int button , int state, int x, int y)
{
	static GLintPoint corner[2];
	static int numCorners = 0;
	if(state==GLUT_DOWN)
	{
		if(button == GLUT_LEFT_BUTTON)
		{
			corner[numCorners].x = x;
			corner[numCorners].y = screenHeight - y;
			if(++numCorners == 2)
			{
				glRecti(corner[0].x,corner[0].y,corner[1].x,corner[1].y);
				numCorners = 0;
			}
		}
		if(button == GLUT_MIDDLE_BUTTON)
		{
			exit(-1);
		}
	}
	glFlush();
}

void myDisplay(void)
{
	GLfloatPoint corner[3] = {{10,10},{600,10},{300,600}};
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenHeight,screenWidth);
	glutInitWindowPosition(100,150);
	glutCreateWindow("sierpin");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(myMouse);
	myInit();
	glutMainLoop();
}
