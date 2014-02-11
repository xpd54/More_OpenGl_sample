//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gl.h>
#include<glu.h>
#include<glut.h>
const screenWidth = 800;
const screenHeight = 600;

void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
	
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.6,0.6,0.6);
		glRecti(20,20,100,70);
	glColor3f(0.2,0.2,0.2);
		glRecti(70,50,150,130);
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
