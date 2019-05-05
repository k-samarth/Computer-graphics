#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
int a,count;
void init();
void display();
void drawcircle(int r);
void plot(int x,int y);
void plus();
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	printf("Enter the radius");
	scanf("%d",&a);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(30,30);
	glutInitWindowSize(700,700);
	glutCreateWindow("FAN");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-700,700,-700,700);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	drawcircle(a);
	plus();
	glPointSize(30);
	glColor3f(1,0,0);
	glBegin(GL_POINTS);
		glVertex2i(0,0);
	glEnd();
	glFlush();
}

void drawcircle(int r)
{
	int p0,x=0,y=r;
	p0=1-r;
	while(x!=y)
	{
		count++;
		if(p0<0)
		{
			x+=1;
			p0=p0+2*x+1;
			plot(x,y);
			plot(y,x);
			plot(-y,x);
			plot(-x,y);
			plot(-x,-y);
			plot(-y,-x);
			plot(y,-x);
			plot(x,-y);
		}
		else
		{
			x+=1;
			y-=1;
			p0=p0+2*x+1-2*y;
			plot(x,y);
			plot(y,x);
			plot(-y,x);
			plot(-x,y);
			plot(-x,-y);
			plot(-y,-x);
			plot(y,-x);
			plot(x,-y);
		}
	}
}
void plot(int x,int y)
{
	glColor3f(0,1,1);
	glPointSize(7);
	glBegin(GL_POINTS);
		glVertex2i(x,y);
	glEnd();
}
void plus()
{
	int x=0,y=0;
	while(y!=a)
	{
		y++;
		plot(0,y);
		plot(0,-y);
	}
	while(x!=a)
	{
		x++;
		plot(x,0);
		plot(-x,0);
	}
	x=0;
	y=0;
	while(x+y!=a)
	{
		count++;
		plot(x,y);
		plot(-x,y);
		plot(-x,-y);
		plot(x,-y);
		x++;
		y++;
	}
}
