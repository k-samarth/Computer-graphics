#include<stdio.h>
#include<GL/glut.h>
GLfloat vert[8][3]={{-250,250,-250},{250,250,-250},{250,-250,-250},{-250,-250,-250},{-250,250,250},{250,250,250},{250,-250,250},{-250,-250,250}};
GLfloat view1[]={0,0,500};
int v,theta,x;
void init();
void display();
void drawcube(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,GLfloat *e,GLfloat *f,GLfloat *g,GLfloat *h);
void drawsquare(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d);
void keys(unsigned char ki,int x,int y);
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(60,60);
	glutInitWindowSize(720,620);
	glutCreateWindow("Perspective viewing of color cube");
	init();
	glEnable(GL_DEPTH_TEST);
	glutKeyboardFunc(keys);
	glutDisplayFunc(display);
	glutMainLoop();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glFrustum(-500,500,-500,500,500,1000);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	gluLookAt(view1[0],view1[1],view1[2],0,0,0,0,1,0);
	drawcube(vert[0],vert[1],vert[2],vert[3],vert[4],vert[5],vert[6],vert[7]);
	glLoadIdentity();
	glFlush();
	glutSwapBuffers();
}
void drawcube(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,GLfloat *e,GLfloat *f,GLfloat *g,GLfloat *h)
{
	glColor3f(1,0,0);
	drawsquare(e,f,g,h);
	glColor3f(0,1,0);
	drawsquare(e,f,b,a);
	glColor3f(0,0,1);
	drawsquare(h,g,c,d);
	glColor3f(1,1,0);
	drawsquare(a,e,h,d);
	glColor3f(1,0,1);
	drawsquare(b,f,g,c);
	glColor3f(0,1,1);
	drawsquare(a,b,c,d);
}
void drawsquare(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{
	glBegin(GL_POLYGON);
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
	glVertex3fv(d);
	glEnd();
}
void keys(unsigned char ki,int x,int y)
{
	if(ki=='x')
	{
		view1[0]-=1;
	}
	if(ki=='X')
	{
		view1[0]+=1;
	}
	if(ki=='y')
	{
		view1[1]-=1;
	}
	if(ki=='Y')
	{
		view1[1]+=1;
	}
	if(ki=='z')
	{
		view1[2]-=1;
	}
	if(ki=='Z')
	{
		view1[2]+=1;
	}
	glutPostRedisplay();
}
