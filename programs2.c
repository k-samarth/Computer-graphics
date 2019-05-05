#include<GL/glut.h>
#include<stdio.h>
#include<stdbool.h>
float xmin,ymin,xmax,ymax,x1,y11,x2,y12,x,y;
float vx1,vx2,vy1,vy2,sx,sy;
float vxmax=600;
float vymax=600;//-200 for 3rd quadrant
float vxmin=200;
float vymin=200;//-600 for 3rd quadrant
int top=8,bottom=4,left=1,right=2;

void cohen_sutherland_clip(float x1,float y11,float x2,float y12);

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	glVertex2f(xmin,ymin);
	glVertex2f(xmax,ymin);
	glVertex2f(xmax,ymax);
	glVertex2f(xmin,ymax);
	glEnd();
	glColor3f(0.0,1.0,0.0);
	glBegin(GL_LINES);
	glVertex2f(x1,y11);
	glVertex2f(x2,y12);
	glEnd();
	glFlush();
	cohen_sutherland_clip(x1,y11,x2,y12);
}

int compute_outcode(float x,float y)
{	
	int code=0;
	if(y>ymax)
		code=code|top;
	if(y<ymin)
		code=code|bottom;
	if(x>xmax)
		code=code|right;
	if(x<xmin)
		code=code|left;
	return code;
}

void cohen_sutherland_clip(float x1,float y11,float x2,float y12)
{
	int outcode1,outcode2,nonzeroend;
	bool accept=false;
	bool done=false;
	outcode1=compute_outcode(x1,y11);
	outcode2=compute_outcode(x2,y12);
	
	do
	{
		if(outcode1==0 && outcode2==0)
		{	
			accept=true;
			done=true;
		}
		else if(outcode1 & outcode2)
		{
			done=true;
		}
		else
		{
			nonzeroend=(outcode1!=0)?outcode1:outcode2;
			if(nonzeroend & top)
			{
				y=ymax;
				x=x1+((x2-x1)/(y12-y11))*(ymax-y11);
			}
			if(nonzeroend & bottom)
			{
				y=ymin;
				x=x1+((x2-x1)/(y12-y11))*(ymin-y11);
			}
			if(nonzeroend & left)
			{
				x=xmin;
				y=y11+((y12-y11)/(x2-x1))*(xmin-x1);
			}
			if(nonzeroend & right)
			{
				x=xmax;
				y=y11+((y12-y11)/(x2-x1))*(xmax-x1);
			}
			
			if(outcode1==nonzeroend)
			{
				x1=x;
				y11=y;
				outcode1=compute_outcode(x1,y11);
			}
			else
			{
				x2=x;
				y12=y;
				outcode2=compute_outcode(x2,y12);
			}
		}
	}while(!done);
	if(accept)
	{
		sx=(vxmax-vxmin)/(xmax-xmin);
		sy=(vymax-vymin)/(ymax-ymin);
		vx1=vxmin+(x1-xmin)*sx;
		vy1=vymin+(y11-ymin)*sy;
		vx2=vxmin+(x2-xmin)*sx;
		vy2=vymin+(y12-ymin)*sy;
		glColor3f(0.0,0.0,1.0);
		glBegin(GL_LINE_LOOP);
		glVertex2f(vxmin,vymin);
		glVertex2f(vxmax,vymin);
		glVertex2f(vxmax,vymax);
		glVertex2f(vxmin,vymax);
		glEnd();
		glColor3f(0.0,1.0,0.0);
		glBegin(GL_LINES);
		glVertex2f(vx1,vy1);
		glVertex2f(vx2,vy2);
		glEnd();
		glFlush();
	}
}

void myinit()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1000,1000,-1000,1000);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc,char *argv[])
{
	glutInit(&argc,argv);
	
	printf("Enter the values for xmax:\n");
	scanf("%f",&xmax);

	printf("Enter the values for ymax:\n");
	scanf("%f",&ymax);

	printf("Enter the values for xmin:\n");
	scanf("%f",&xmin);

	printf("Enter the values for ymin:\n");
	scanf("%f",&ymin);

	printf("Enter the values for x1:\n");
	scanf("%f",&x1);

	printf("Enter the values for y11:\n");
	scanf("%f",&y11);

	printf("Enter the values for x2:\n");
	scanf("%f",&x2);

	printf("Enter the values for y12:\n");
	scanf("%f",&y12);
	
	glutCreateWindow("_CohenSutherland");
	myinit();
	glutDisplayFunc(display);
	glutMainLoop();
}
