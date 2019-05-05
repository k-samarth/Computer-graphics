#include<GL/glut.h>
#include<stdio.h>
void display();
void init();
void drawline(int x0,int y0,int x1,int y1);
void clip(int x1,int y1,int x2,int y2);
void drawline1(int e,int f,int g,int h);
float xmin = 10,ymin = 10,xmax = 250,ymax = 250,xmin1 = 300,xmax1 = 600,ymin1 = 300,ymax1 = 600;
int left = 1, right = 2, bottom = 4, top = 8;
int p[7],q[7],r[7],s[7],i;
GLfloat sx,sy; 
void drawipwindow();
void drawopwindow(float xmin1,float ymin1,float xmax1,float ymax1);
void main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	for(i=0;i<7;i++)
	{
		printf("Enter the line cordinates\n");
		scanf("%d %d %d %d",&p[i],&q[i],&r[i],&s[i]);
	}
	glutInitWindowPosition(50,50);
	glutInitWindowSize(720,600);
	glutCreateWindow("CohenSutherland line clipping algo");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}
void display()
{
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0,0,0);
	drawipwindow();
	for(i=0;i<7;i++)
	{
		drawline(p[i],q[i],r[i],s[i]);
	}
	drawopwindow(xmin1,ymin1,xmax1,ymax1);	
	for(i=0;i<7;i++) 
	{
		clip(p[i],q[i],r[i],s[i]);
	}
	glFlush();
}
void drawipwindow()
{
	glColor3f(0,0,0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2i(xmin, ymin);
	glVertex2i(xmax, ymin);
	glVertex2i(xmax, ymin);
	glVertex2i(xmax, ymax);
	glVertex2i(xmax, ymax);
	glVertex2i(xmin, ymax);
	glVertex2i(xmin, ymax);
	glVertex2i(xmin, xmin);
	glEnd(); 
}
void drawline(int x0,int y0,int x1,int y1)
{
	glColor3f(1,0,0);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(x0,y0);
	glVertex2i(x1,y1);
	glEnd();
}
void drawline1(int l,int m,int n,int o)
{
	glColor3f(0.5,0.2,0.7);
	glLineWidth(3);
	glBegin(GL_LINES);
	glVertex2i(l,m);
	glVertex2i(n,o);
	glEnd();
}
void init(){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,700,0,700);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void drawopwindow(float xmin1,float ymin1,float xmax1,float ymax1)
{
	glColor3f(0,0,0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2i(xmin1, ymin1);
	glVertex2i(xmax1, ymin1);
	glVertex2i(xmax1, ymin1);
	glVertex2i(xmax1, ymax1);
	glVertex2i(xmax1, ymax1);
	glVertex2i(xmin1, ymax1);
	glVertex2i(xmin1, ymax1);
	glVertex2i(xmin1, xmin1);
	glEnd();
}
int regioncode(int x,int y)
{	
	int rcode = 0;
	if (x < xmin)
		rcode=left;
	else if (x > xmax)
		rcode=right;
	else if (y < ymin)
		rcode=bottom;
	else if (y > ymax)
		rcode=top;
	return rcode; 
}
void clip(int x1, int y1, int x2, int y2)
{
	int accept = 1;
	int x, y, rcode1, rcode2, rcodeOut;
	int x0 = x1;
	int y0 = y1;
	int xe = x2;
	int ye = y2;
	rcode1 = regioncode(x1, y1);
	rcode2 = regioncode(x2, y2);
	while (accept==1)
	{
			if((rcode1 | rcode2)==0)
			{
				accept=0;
				break;
			}
			else if((rcode1 & rcode2)!=0)
				break;
			else
				rcodeOut=(rcode1>rcode2)?rcode1:rcode2;
			if(rcodeOut & top)
			{
				x = x0 +(xe-x0)*(ymax-y0)/(ye-y0);
				y = ymax;
			}
			else if(rcodeOut & bottom)
			{
				x = x0+(xe-x0)*(ymin-y0)/(ye-y0);
				y = ymin;
			}
			else if(rcodeOut & right)
			{
				y = y0 + ( ye - y0 ) * ( xmax - x0 ) / ( xe - x0);
				x = xmax;
			}
			else if(rcodeOut & left)
			{
				y = y0 + ( ye - y0 ) * ( xmin - x0) / ( xe - x0 );
				x = xmin; 
			}
		
			if(rcodeOut == rcode1)
			{
				x0 = x;
				y0 = y;
				rcode1 = regioncode(x0,y0);
			}
			else{
				xe = x;
				ye = y;
				rcode2 = regioncode(xe,ye);
			}
		
		}
		if(accept == 0)
		{
			sx=(xmax1-xmin1)/(xmax-xmin);
			sy=(ymax1-ymin1)/(ymax-ymin);
			x0 = xmin1+(x0-xmin)*sx;
			y0=ymin1+(y0-ymin)*sy;
			xe=xmin1+(xe-xmin)*sx;
			ye=ymin1+(ye-ymin)*sy;
			drawline1(x0,y0,xe,ye);
		}
}


			
		
		

