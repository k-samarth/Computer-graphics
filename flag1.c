#include <stdlib.h>
#include <GL/glut.h>

float theta=10;
float coltab[3]= { 0.6,0.3,0.1};//table
float coltab1[3]={ 0.3,0.1,0.0};
float pos[4]= {30,25,10,0};

float rotate_inc = 0.05;
float flag_move = 1;
float move_flag = 0;
float flag_pos = 10;

GLfloat colorBottom[] = {0.0, 1.0, 0.0};
GLfloat colorTop[] = {1.0, 0.3, 0.0};
GLfloat colorbg[] = {0.0, 0.0, 0.0};

GLfloat ctrlPts1[4][4][3] =
	{
		{{-300, 0, 00.0},  {-100, 0, 150.0},  {100, 0, -50.0},  {250, 0,150.0}},
		{{-300, 45, 00.0}, {-100, 45, 150.0}, {100, 45, -50.0}, {250, 45, 150.0}},
		{{-300, 70, 00.0}, {-100, 70, 150.0}, {100, 70, -50.0}, {250, 70, 150.0}},
		{{-300, 95, 00.0}, {-100, 95, 150.0}, {100, 95, -50.0}, {250, 95, 150.0}}
	};
GLfloat ctrlPts2[4][4][3] =
	{
		{{-300, 95, 00.0},  {-100, 95, 150.0},   {100, 95, -50.0},   {250, 95, 150.0}},
		{{-300, 120, 00.0}, {-100, 120, 150.0},  {100, 120, -50.0},  {250, 120, 150.0}},
		{{-300, 145, 00.0}, {-100, 145, 150.0},  {100, 145, -50.0},  {250, 145, 150.0}},
		{{-300, 170, 00.0}, {-100, 170, 150.0},  {100, 170, -50.0},  {250, 170, 150.0}}
	};
GLfloat ctrlPts3[4][4][3] =
	{
		{{-300, 170, 00.0}, {-100, 170, 150.0}, {100, 170, -50.0},  {250, 170, 150.0}},
		{{-300, 195, 00.0}, {-100, 195, 150.0}, {100, 195, -50.0},  {250, 195, 150.0}},
		{{-300, 220, 00.0}, {-100, 220, 150.0}, {100, 220, -50.0},  {250, 220, 150.0}},
		{{-300, 245, 00.0}, {-100, 245, 150.0}, {100, 245, -50.0},  {250, 245, 150.0}}
	};


void 
display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	glClearColor(colorbg[0],colorbg[1], colorbg[2], 1.0);
	
	GLint i,k, j;
	//glRotatef(45, 1 ,1, 0);

	glPushMatrix();
	//glRotatef(theta, 0 ,1, 0);

	if( move_flag == 1 && flag_pos <= 10){
		flag_pos++;
	} else if( move_flag == -1 && flag_pos >= -450)
		flag_pos--;

	glTranslatef(0, flag_pos, 0);
	glEnable (GL_MAP2_VERTEX_3);
	
	glColor3fv (colorTop);
	glMap2f (GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4,	0.0, 1.0, 12, 4, &ctrlPts3[0][0][0]);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);		
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);


    glColor3f (1.0, 1.0, 1.0);
	glMap2f (GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4,	0.0, 1.0, 12, 4, &ctrlPts2[0][0][0]);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);

	glColor3fv (colorBottom);
    glMap2f (GL_MAP2_VERTEX_3, 0.0, 1.0, 3, 4,	0.0, 1.0, 12, 4, &ctrlPts1[0][0][0]);
	glMapGrid2f(20, 0.0, 1.0, 20, 0.0, 1.0);		
	glEvalMesh2(GL_FILL, 0, 20, 0, 20);



	glPopMatrix();

	glPushMatrix();
		glColor3f(0.0, 0.2, 0.39);
		glTranslatef(0, 120+flag_pos, 40);
		glutWireSphere(40, 20, 6);
	glPopMatrix();

	glPushMatrix();
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glLightfv(GL_LIGHT0,GL_AMBIENT,pos);
	glLightfv(GL_LIGHT0,GL_AMBIENT,coltab);     //leg1
	glLightfv(GL_LIGHT0,GL_DIFFUSE,coltab);
	glLightfv(GL_LIGHT0,GL_SPECULAR,coltab);
	glMaterialfv(GL_FRONT_AND_BACK,GL_AMBIENT,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_DIFFUSE,coltab1);
	glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,coltab1);

	glColor3f(0.6, 0.3, 0.1);
	glTranslatef(-300, -200, 0);
	glScalef(1, 32, 1);
	glutSolidCube(30);

	glDisable(GL_LIGHTING);
	glDisable(GL_LIGHT0);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-300, -500, 0);
		glScalef(3, 2, 1);
		glutSolidCube(50);
	glPopMatrix();
	glFlush();
	glutSwapBuffers();
}

void Move()
{
	theta=theta+rotate_inc;
	if (theta< 0)
		rotate_inc=0.1;
	if (theta > 70) {
		rotate_inc= -0.1;
	}

	int i = 0;
	for(i = 0; i < 4; i++)
	{
		ctrlPts1[i][1][1]+=flag_move;
		ctrlPts1[i][2][1]-=flag_move;
		ctrlPts1[i][3][1]+=flag_move;

		ctrlPts2[i][1][1]+=flag_move;
		ctrlPts2[i][2][1]-=flag_move;
		ctrlPts2[i][3][1]+=flag_move;

		ctrlPts3[i][1][1]+=flag_move;
		ctrlPts3[i][2][1]-=flag_move;
		ctrlPts3[i][3][1]+=flag_move;

	}
	

	if (ctrlPts1[0][1][1] > 100)
		flag_move = -1;
	if (ctrlPts1[0][1][1] < -50)
		flag_move = 1;

	glutPostRedisplay();
	
}

void menu(int value){
	
	switch(value)
	{
		case 0:
			exit(0);
			break;
		case 1:
			colorbg[0] = 1.0;
			colorbg[1] = 1.0;
			colorbg[2] = 1.0;
			break;
		case 2:
			colorbg[0] = 0.0;
			colorbg[1] = 0.0;
			colorbg[2] = 0.0;
			break;
		case 3:
			colorbg[0] = 0.0;
			colorbg[1] = 0.0;
			colorbg[2] = 1.0;
			break;
		case 4:
			move_flag = 1;
			break;
		case 5:
			move_flag = -1;
			break;
	}
}

void myinit(void)
{
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_AUTO_NORMAL);
	glEnable(GL_NORMALIZE);

	int backgroundcolor = glutCreateMenu(menu);
 
	// Add sub menu entry
	glutAddMenuEntry("white", 1);
	glutAddMenuEntry("black", 2);
	glutAddMenuEntry("blue", 3);

	int flagmovement = glutCreateMenu(menu);
 
	glutAddMenuEntry("up", 4);
	glutAddMenuEntry("down", 5);

 
	// Create the menu, this menu becomes the current menu
	int menyid = glutCreateMenu(menu);
 
	// Create an entry
	glutAddSubMenu("Background color", backgroundcolor);
	glutAddSubMenu("Flag movement", flagmovement);
	// Create an entry
	glutAddMenuEntry("exit", 0);
 
	// Let the menu respond on the right mouse button
	glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void myReshape(int w, int h)
{

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-500,500,-500,500,-500,500);
	/*if (w <= h)
		glOrtho(-500, 500, 0 * (GLfloat) h / (GLfloat) w,
		500 * (GLfloat) h / (GLfloat) w, -14.0, 14.0);
	else
		glOrtho(0 * (GLfloat) w / (GLfloat) h,
		500 * (GLfloat) w / (GLfloat) h, 0, 500, -14.0, 14.0);*/
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
			glutInitWindowSize (500, 500);
			glutInitWindowPosition (100, 100);
	glutCreateWindow("");
	myinit();
	glutReshapeFunc(myReshape);
	glutDisplayFunc(display);
	glutIdleFunc(Move);
	glutMainLoop();
}