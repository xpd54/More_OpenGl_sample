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
int heightOfOneGrid , widthOfOneGrid;
//--------------------QUE FUNCTIONS---------------------

struct node
{
	GLfloatPoint point;
	struct node *next;
};
typedef struct node node;

node *createQue(void)
{
	node *ptr;
	ptr = (node *)malloc(sizeof(node *));
	ptr -> point.x= 0;
	ptr -> point.y = 0;
	ptr -> next = NULL;
	return ptr;
}

void pushPoint(node *ptr,GLfloatPoint point)
{
	node *newPoint;
	newPoint = (node *)malloc(sizeof(node *));
	ptr->point.x++;
	ptr->point.y++;
	while(ptr->next != NULL)
	{
		ptr = ptr->next;
	}
	newPoint->point = point;
	newPoint->next = NULL;
	ptr->next = newPoint;
}

GLfloatPoint popPoint(node *ptr)
{
	GLfloatPoint point;
	point = ptr->next->point;
	node *temp;
	temp = ptr->next;
	ptr->next=ptr->next->next;
	free(temp);
	return point;
}
//--------------------end of linked list function--------------
void myInit(void)
{
	glClearColor(1.0,1.0,0.0,0.0);
	glColor3f(0.0f,0.0f,0.0f);
	glPointSize(1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0,screenWidth,0.0,screenHeight);
}

//----------------------matrix function--------------------

node *gridDraw(int row,int column)
{
	int i,j ;
	node *head=createQue();
	widthOfOneGrid = screenWidth / row;
	heightOfOneGrid = screenHeight / column;
	GLfloatPoint point;
	for(i=0;i<screenHeight;i+=heightOfOneGrid)
	{
		for(j=0;j<screenWidth;j+=widthOfOneGrid)
		{
			point.x = j;
			point.y = i;
			pushPoint(head,point);
		}
	}
	return head;
}

node *matrixDraw(int row,int column)
{
	GLfloatPoint point1,point2,point3;
	int i=0;
	node *head = gridDraw(row,column),*head1 = gridDraw(row,column);
	for(i=0;i<head->point.x;i++)
	{
		point1=popPoint(head);
		point2.x=point1.x ;
		point2.y=point1.y + heightOfOneGrid;
		point3.x=point1.x + widthOfOneGrid;
		point3.y=point1.y;
		drawLine(point1,point2);
		drawLine(point1,point3); 
		glFlush();
	}
	return head1;
}

//-----------------------end of matix function--------------------

void renderMaze(void)
{
	glClear(GL_COLOR_BUFFER_BIT);
	drawMargin(screenWidth,screenHeight);
	node *head=matrixDraw(2,3);
	printf("%f\n",head->point.x);
	glFlush();
	
}


void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(screenWidth,screenHeight);
	glutInitWindowPosition(100,150);
	glutCreateWindow("maze");
	glutDisplayFunc(renderMaze);
	myInit();
	glutMainLoop();
}
