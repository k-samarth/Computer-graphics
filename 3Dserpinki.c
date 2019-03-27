#include<stdio.h>
#include<GL/glut.h>
int e;
GLfloat vert[4][3]={{0,0.7,0.2},{-0.7,-0.7,0},{0.7,-0.7,0},{0,0,0.6}};
void display();
void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int e);
void drawtetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d);
void drawtriangle(GLfloat *x,GLfloat *y,GLfloat *z);
void init();
void display()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	divide_tetra(vert[0],vert[1],vert[2],vert[3],e);
	glFlush();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1,1,-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void divide_tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int e)
{
	GLfloat m0[3],m1[3],m2[3],m3[3],m4[3],m5[3];
	if(e>0)
	{
		int i;
		for(i=0;i<3;i++)
		{
			m0[i]=(a[i]+b[i])/2;
			m1[i]=(b[i]+c[i])/2;
			m2[i]=(c[i]+a[i])/2;
			m3[i]=(a[i]+d[i])/2;
			m4[i]=(b[i]+d[i])/2;
			m5[i]=(c[i]+d[i])/2;
		}
		
		divide_tetra(a,m0,m2,m3,e-1);
		
		divide_tetra(m0,b,m1,m4,e-1);
		
		divide_tetra(m2,m1,c,m5,e-1);
		
		divide_tetra(m3,m4,m5,d,e-1);
	}
	else
	{
		drawtetra(a,b,c,d);
	}
}
void drawtetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{	
	glColor3f(0.87,0,0);
	drawtriangle(a,b,c);
	glColor3f(0.34,0.65,0);
	drawtriangle(a,b,d);
	glColor3f(0,0.3,0.7);
	drawtriangle(d,b,c);
	glColor3f(0.6,0.2,0);
	drawtriangle(a,d,c);
}
void drawtriangle(GLfloat *x,GLfloat *y,GLfloat *z)
{
	glBegin(GL_TRIANGLES);
	glVertex3fv(x);
	glVertex3fv(y);
	glVertex3fv(z);
	glEnd();
}	
	
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	printf("Enter the number of divisions");
	scanf("%d",&e);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(1080,960);
	glutCreateWindow("3D surpenski cascade");
	init();
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutMainLoop();
}
	
