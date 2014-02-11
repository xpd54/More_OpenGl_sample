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

void myInit(void)
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(0.0f,1.0f,0.0f);
	glPointSize(3.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
}

void myKeyboard(unsigned char key, int mouseX, int mouseY)
{
	GLint x = mouseX;
	GLint y = screenHeight - mouseY;
	static GLint size = 1.0;
	switch(key)
	{
		case 'p':
			glPointSize(size);
			drawDot(x , y);
			break;
		case '+':
			size++;
			break;
		case '-':
			size--;
			break;
		case 'r':
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1.0,0.0,0.0,0.0);
			glFlush();
			break;
		case 'b':
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(0.0,0.0,1.0,0.0);
			glFlush();
			break;
		case 'R':
			glClear(GL_COLOR_BUFFER_BIT);
			glClearColor(1.0,1.0,1.0,0.0);
			glFlush();
			break;
		case 'E':
			exit(-1);
		default:
			break;
	}
	glFlush();
}

void myDisplay(void)
{
//	GLfloatPoint corner[3] = {{10,10},{600,10},{300,600}};
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("keyboard");
	glutDisplayFunc(myDisplay);
	glutKeyboardFunc(myKeyboard);
	myInit();
	glutMainLoop();
}
