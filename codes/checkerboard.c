//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<gl.h>
#include<glu.h>
#include<glut.h>
const screenWidth = 600;
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

void board(GLint size)
{
	GLint i,j,i1=0,j1=0;
	for(i=0;i<8;i+=1)
	{
		for(j=0;j<8;j+=1)
		{
			if((i+j)%2==0)
			{
				glColor3f(0.6,0.6,0.6);
				glRecti(i*size,j*size,i*size+size,j*size+size);
			}
			else
			{
				glColor3f(0.2,0.2,0.2);
				glRecti(i*size,j*size,i*size+size,j*size+size);
			}
			
		}
	}
}

void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	board(screenWidth/8);
	glFlush();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("checkerboard");
	glutDisplayFunc(myDisplay);
	myInit();
	glutMainLoop();
}
