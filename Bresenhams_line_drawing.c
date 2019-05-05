#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>
int a,b,c,d;
void init();
void display();
void drawline(int a,int b,int c,int d);
void drawline_horizontalsteep(int x0,int y0,int x1,int y1);
void drawline_verticalsteep(int x0,int y0,int x1,int y1);
void plot(int x,int y);
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,400,0,400);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	drawline(a,b,c,d);
	glFlush();
}
void drawline(int a,int b,int c,int d)
{
	if(abs(d-b)<abs(c-a))
	{
		if(a>c)
		{
			drawline_horizontalsteep(c,d,a,b);
		}
		else
		{
			drawline_horizontalsteep(a,b,c,d);
		}
	}
	else
	{
		if(b>d)
		{
			drawline_verticalsteep(c,d,a,b);
		}
		else
		{
			drawline_verticalsteep(a,b,c,d);
		}
	}
}
void drawline_horizontalsteep(int x0,int y0,int xe,int ye)
{
	int dx,dy,p0,yi,x,y;
	dx=xe-x0;
	dy=ye-y0;
	yi=1;
	if(dy<0)	
	{
		yi=-1;
		dy=-dy;
	}
	p0=(2*dy)-dx;
	y=y0;
	for(x=x0;x<xe;x++)
	{
		plot(x,y);
		if(p0>0)
		{
			y=y+yi;
			p0=p0-(2*dx);
		}
		p0=p0+(2*dy);
	}
}
void drawline_verticalsteep(int x0,int y0,int xe,int ye)
{
	int dx,dy,p0,xi,x,y;
	dx=xe-x0;
	dy=ye-y0;
	xi=1;
	if(dx<0)
	{
		xi=-1;
		dx=-dx;
	}
	p0=(2*dy)-dx;
	x=x0;
	for(y=y0;y<ye;y++)
	{
		plot(x,y);
		if(p0>0)
		{
			x=x+xi;
			p0=p0-(2*dy);
		}
		p0=p0+(2*dx);
	}
}
void plot(int x,int y)
{
	glColor3f(1,1,1);
	glPointSize(2);
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	printf("Enter the intial point");
	scanf("%d%d",&a,&b);
	printf("Enter the final point");
	scanf("%d%d",&c,&d);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(40,40);
	glutInitWindowSize(400,400);
	glutCreateWindow("Bresenham's line drawing");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
