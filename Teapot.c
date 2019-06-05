#include<GL/glut.h>
void leg1()
{
	glPushMatrix();
	glTranslatef(-140,-160,-60);
	glScalef(20,300,20);
	glutSolidCube(1.0);
	glPopMatrix();
}
void leg2()
{
	glPushMatrix();
	glTranslatef(-140,-160,60);
	glScalef(20,300,20);
	glutSolidCube(1.0);
	glPopMatrix();
}
void leg3()
{
	glPushMatrix();
	glTranslatef(140,-160,-60);
	glScalef(20,300,20);
	glutSolidCube(1.0);
	glPopMatrix();
}
void leg4()
{
	glPushMatrix();
	glTranslatef(140,-160,60);
	glScalef(20,300,20);
	glutSolidCube(1.0);
	glPopMatrix();
}
void surface()
{
	glPushMatrix();
	glTranslatef(0,0,0);
	glScalef(300,20,300);
	glutSolidCube(1.0);
	glPopMatrix();
}
void walls1()
{
	glPushMatrix();
	glTranslatef(0,0,-300);
	glScalef(500,600,20);
	glutSolidCube(1.0);
	glPopMatrix();
}
void walls2()
{
	glPushMatrix();
	glTranslatef(260,0,-60);
	glRotatef(90,0,1,0);
	glScalef(500,600,20);
	glutSolidCube(1.0);
	glPopMatrix();
}
void walls3()
{
	glPushMatrix();
	glTranslatef(0,-300,-60);
	glRotatef(90,1,0,0);
	glScalef(500,500,20);
	glutSolidCube(1.0);
	glPopMatrix();
}
void table()
{
	GLfloat a[]={0.7,0.2,0.3,1};
	GLfloat b[]={0.2,0.5,0.9,0.1};
	GLfloat c[]={0.9,0.4,0.7,1};
	GLfloat d[]={100};
	glMaterialfv(GL_FRONT,GL_AMBIENT,a);
	glMaterialfv(GL_FRONT,GL_SPECULAR,b);
	glMaterialfv(GL_FRONT,GL_DIFFUSE,c);
	glMaterialfv(GL_FRONT,GL_SHININESS,d);
	leg1();
	leg2();
	leg3();
	leg4();
	surface();
	walls1();
	walls2();
	walls3();
}
void teapot()
{
	glPushMatrix();
	glTranslatef(0,45,0);
	GLfloat a[]={0.5,0.7,0.9,1};
	GLfloat b[]={0.5,0.6,0.2,0.1};
	glMaterialfv(GL_FRONT,GL_AMBIENT,a);
	glMaterialfv(GL_FRONT,GL_SPECULAR,b);
	GLfloat a1[]={90,450,100,1.0};
	GLfloat b1[]={0.2,0.3,0.9,0.2};
	glLightfv(GL_LIGHT1,GL_POSITION,a1);
	glLightfv(GL_LIGHT1,GL_DIFFUSE,b1);
	glutSolidTeapot(60.0);
	glPopMatrix();
}
void init()
{
	glViewport(0,0,500,500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500,500,-500,500,-500,500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
void display()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	GLfloat a[]={50,450,100,1.0};
	GLfloat b[]={0.7,0.5,0.3,0.2};
	glLightfv(GL_LIGHT0,GL_POSITION,a);
	glLightfv(GL_LIGHT0,GL_DIFFUSE,b);
	glRotatef(3,0.1,0.3,0);
	teapot();
	table();
	glFlush();
}
void main(int argc,char ** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB|GLUT_DEPTH);
	glutInitWindowPosition(50,50);	
	glutInitWindowSize(700,700);
	glutCreateWindow("teapot");
	init();
	glutDisplayFunc(display);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT0);
	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glutMainLoop();
}
