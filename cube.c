#include<GL/glut.h>
GLfloat vert[8][3]={{-250,250,-250},{250,250,-250},{250,-250,-250},{-250,-250,-250},{-250,250,250},{250,250,250},{250,-250,250},{-250,-250,250}};
void display();
GLfloat theta;
void init();
GLfloat flag;
void drawcube(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,GLfloat *e,GLfloat *f,GLfloat *g,GLfloat *h);
void drawsquare(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d);
void spin();
void mouse(int btn,int state,int x,int y);
void display()
{
	glClearColor(1,1,1,1);
	glColor3f(0.55,0.15,0.2);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	drawcube(vert[0],vert[1],vert[2],vert[3],vert[4],vert[5],vert[6],vert[7]);
	glLoadIdentity();
	glFlush();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500,500,-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
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
void spin()
{
	theta=theta+0.05;
	if(theta>=360)
	{
		theta=0;
	}
	//glLoadIdentity();
	if(flag==1)
	{
		glRotatef(theta,1,0,0);
	}
	if(flag==2)
	{
		glRotatef(theta,0,1,0);
	}
	if(flag==3)
	{
		glRotatef(theta,0,0,1);
	}
	glutPostRedisplay();
}
void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
	{
		flag=1;
	}
	if(btn==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
	{
		flag=2;
	}
	if(btn==GLUT_MIDDLE_BUTTON && state==GLUT_DOWN)
	{
		flag=3;
	}
}	
void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_DEPTH);
	glutInitWindowPosition(60,60);
	glutInitWindowSize(720,620);
	glutCreateWindow("cube");
	init();
	glEnable(GL_DEPTH_TEST);
	glutMouseFunc(mouse);
	glutIdleFunc(spin);
	glutDisplayFunc(display);
	glutMainLoop();
}

