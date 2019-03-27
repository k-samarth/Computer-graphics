#include<GL/glut.h>
#include<stdio.h>
void mydisplay();
void divide_triangle(GLfloat *a,GLfloat *b,GLfloat *c,int d);
void draw_triangle(GLfloat *a,GLfloat *b,GLfloat *c);
int d;
GLfloat vert[3][2]={{0,0.7},{-0.7,-0.7},{0.7,-0.7}};
void mydisplay()
{
	glClearColor(0,0,0,1);
	glClear(GL_COLOR_BUFFER_BIT);
	
	divide_triangle(vert[0],vert[1],vert[2],d);
	glFlush();
}
void divide_triangle(GLfloat *a,GLfloat *b,GLfloat *c,int d)
{
	GLfloat m0[2],m1[2],m2[2];
	if(d>0)
	{
		m0[0]=(a[0]+b[0])/2;
		m0[1]=(a[1]+b[1])/2;
		m1[0]=(b[0]+c[0])/2;
		m1[1]=(b[1]+c[1])/2;
		m2[0]=(c[0]+a[0])/2;
		m2[1]=(c[1]+a[1])/2;
		glColor3f(0.6,0.34,0.8);
		divide_triangle(a,m0,m2,d-1);
		glColor3f(0.2,0.35,0.7);
		divide_triangle(m0,b,m1,d-1);
		glColor3f(0.9,0.3,0.3);
		divide_triangle(m2,m1,c,d-1);
		//glColor3f(0.67,0,0.65);
	}
	else
	{
		draw_triangle(a,b,c);
			
	}
}
void draw_triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
	glBegin(GL_TRIANGLES);
	glVertex2fv(a);
	glVertex2fv(b);
	glVertex2fv(c);
	glEnd();
}
void main(int argc,char **argv)
{
	
	glutInit(&argc,argv);
	printf("Enter the value for divisions");
	scanf("%d",&d);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(50,100);
	glutInitWindowSize(1080,960);
	glutCreateWindow("2D surpenski cascade");
	glutDisplayFunc(mydisplay);
	glutMainLoop();
}

