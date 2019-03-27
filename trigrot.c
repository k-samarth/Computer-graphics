#include<GL/glut.h>
#include<stdio.h>
int theta;
int theta1;
int v,x;
GLfloat vert[3][2]={{0,25},{-25,-25},{25,-25}};
char title[]="TRIANGLE ROTATION "; 
void display();
void draw_triangle(GLfloat *a,GLfloat *b,GLfloat *c);
void draw_triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
	
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
	glLineWidth(5);
	glBegin(GL_LINES);
	glColor3f(0,0,0);
	glVertex2fv(a);
	glVertex2fv(b);
	glEnd();
	glBegin(GL_LINES);		
	glColor3f(0,0,0);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
	glBegin(GL_LINES);		
	glColor3f(0,0,0);
	glVertex2fv(a);
	glVertex2fv(c);
	glEnd();
}

void display()
{
	glClearColor(1,1,1,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glRasterPos2f(-45,45);
	for(x=0;title[x]!='\0';x++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,title[x]);
	glColor3f(0.5,0.2,0.7);
	draw_triangle(vert[0],vert[1],vert[2]);
	glPushMatrix();
	if(theta>360)
	{
		theta1=theta-360;
		theta=theta1;
	}
	glRotatef(theta,0,0,1);
	glColor3f(1,0,0);
	draw_triangle(vert[0],vert[1],vert[2]);
	glPopMatrix();
	
	glPushMatrix();
	glTranslatef(vert[v-1][0],vert[v-1][1],0);
	glRotatef(theta,0,0,1);
	glTranslatef(-vert[v-1][0],-vert[v-1][1],0);
	glColor3f(0.1,0.2,0.9);
	draw_triangle(vert[0],vert[1],vert[2]);
	glPopMatrix();
	glFlush();
}
void init()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int argc,char **argv)
{
	glutInit(&argc,argv);
	printf("Enter the angle to be rotated");
	scanf("%d",&theta);
	printf("Enter the vertex to be used as centre for rotation");
	scanf("%d",&v);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(760,600);
	glutCreateWindow("Triangle Rotation");
	init();
	glutDisplayFunc(display);
	glutMainLoop();
}

