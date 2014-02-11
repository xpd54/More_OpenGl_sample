//by Ravi Prakash vickyravi17@gmail.com
#include<stdio.h>
#include<stlib.h>
#include<math.h>
#include<gl.h>
#include<glu.h>
#include<glut.h>
#include"function.h"
#define RED 1
#define GREEN 2
#define BLUE 3
#define WHITE 4
const screenWidth = 800;
const screenHeight = 600;

float angle = 0.0; // for rotating angle
float red = 1.0, blue = 1.0, green = 1.0; // possible tringle colors

void renderScene(void )
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
}
